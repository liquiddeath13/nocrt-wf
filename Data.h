#pragma once
#include <cstdint>

typedef float f32;
typedef double f64;
typedef signed char int8;
typedef signed short int16;
typedef signed int int32;
typedef signed __int64 int64;
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned __int32 uint32;
typedef unsigned int uint;
typedef unsigned long ulong32;
typedef unsigned long long ulong64;
typedef unsigned __int64 uint64;
typedef unsigned __int64 uintptr;
typedef unsigned long h_font;
typedef unsigned int crc32_t;
#define p_void PVOID

typedef unsigned int EntityId;

DWORD64 dwSystemGlobalEnvironment = 0x142262698;
//DWORD64 dwRequestShootHitBegin = 0x141473C10;
//DWORD64 dwRequestShootHitEnd = 0x1424FD578;
DWORD64 dwCHUDSilhouettes = 0x1416D6F00;

typedef struct LDR_DATA_TABLE_ENTRY_FIX
{
	PVOID Reserved1[2];
	LIST_ENTRY InMemoryOrderLinks;
	PVOID Reserved2[2];
	PVOID DllBase;
	PVOID Reserved3[1];
	ULONG64 SizeOfImage;
	UNICODE_STRING FullDllName;
	UNICODE_STRING BaseDllName;
	PVOID Reserved5[2];
#pragma warning(push)
#pragma warning(disable: 4201)
	union
	{
		ULONG CheckSum;
		PVOID Reserved6;
	} DUMMYUNIONNAME;
#pragma warning(pop)
	ULONG TimeDateStamp;
};

struct IDXGISwapChain;

#define to_lower(str) ((str >= 'A' && str <= 'Z') ? (str + 32) : str)
template <typename str_type, typename in_str_type>
bool str_cmp(str_type str, in_str_type in_str, bool b_force)
{
	if (!str || !in_str)
		return false;

	wchar_t c1, c2;

	do
	{
		c1 = *str++;
		c2 = *in_str++;
		c1 = to_lower(c1);
		c2 = to_lower(c2);

		if (!c1 && (b_force ? !c2 : 1))
			return true;

	} while (c1 == c2); return false;
}

////////////////////////////////////////////////
template <typename str_type>
PBYTE gmb(str_type module_name)
{
	PPEB_LDR_DATA p_peb = ((PTEB)__readgsqword(FIELD_OFFSET(NT_TIB, Self)))->ProcessEnvironmentBlock->Ldr;
	for (PLIST_ENTRY current_entry = p_peb->InMemoryOrderModuleList.Flink; current_entry != &p_peb->InMemoryOrderModuleList; current_entry = current_entry->Flink)
	{
		LDR_DATA_TABLE_ENTRY_FIX* p_entry = CONTAINING_RECORD(current_entry, LDR_DATA_TABLE_ENTRY_FIX, InMemoryOrderLinks);
		if (!module_name || str_cmp(module_name, p_entry->BaseDllName.Buffer, false))
			return (PBYTE)p_entry->DllBase;

	} return nullptr;
}

uintptr ugmd(const wchar_t* module_name)
{
	return (uintptr)gmb(module_name);
}

#define get_module_base   gmb
#define u_get_module_base ugmd
////////////////////////////////////////////////

////////////////////////////////////////////////
#define in_range(x, a, b) (x >= a && x <= b) 
#define get_bits(x) (in_range((x&(~0x20)),'A','F')?((x&(~0x20))-'A'+0xA):(in_range(x,'0','9')?x-'0':0))
#define get_byte(a, b) (get_bits(a) << 4 | get_bits(b))

namespace MemHelper {
	bool InsideModule(const wchar_t* module, uint64_t addr)
	{
		uint64_t base = (uint64_t)(GetModuleHandleW(module));
		PIMAGE_DOS_HEADER dos = (PIMAGE_DOS_HEADER)base;
		PIMAGE_NT_HEADERS64 nt = (PIMAGE_NT_HEADERS64)base + dos->e_lfanew;

		return addr >= nt->OptionalHeader.ImageBase && addr < nt->OptionalHeader.ImageBase + nt->OptionalHeader.SizeOfImage;
		//return (addr >= base && addr <= (base + nt->OptionalHeader.SizeOfImage));
	}
	PBYTE find_pattern(const char* pattern, const wchar_t* module_name = nullptr)
	{
		uintptr start_address = u_get_module_base(module_name);
		if (!start_address)
			return 0;

		PBYTE first_match = nullptr;
		const char* current_pattern = pattern;

		PBYTE end_address = (PBYTE)(start_address + ((PIMAGE_NT_HEADERS)(start_address + ((PIMAGE_DOS_HEADER)start_address)->e_lfanew))->OptionalHeader.SizeOfImage);
		for (PBYTE p_current = (PBYTE)start_address; p_current < end_address; p_current++)
		{
			char pattern_byte = current_pattern[0];
			if (!pattern_byte)
				return first_match;

			if (pattern_byte == '\?' || *(BYTE*)p_current == get_byte(pattern_byte, current_pattern[1]))
			{
				if (!first_match) first_match = p_current;
				if (!current_pattern[2])
					return first_match;

				((pattern_byte == '\?') ? (current_pattern += 2) : (current_pattern += 3));
			}
			else
			{
				current_pattern = pattern;
				first_match = nullptr;
			}
		}

		return 0;
	}
}

enum class EDeviceId
{
	eDI_Keyboard = 0x0,
	eDI_Mouse = 0x1,
	eDI_XI = 0x2,
	eDI_Orbis = 0x3,
	eDI_Unknown = 0xFF,
};

enum class EInputState
{
	eIS_Unknown = 0x0,
	eIS_Pressed = 0x1,
	eIS_Released = 0x2,
	eIS_Down = 0x4,
	eIS_Changed = 0x8,
	eIS_UI = 0x10,
};

enum class EKeyId : unsigned __int32
{
	eKI_Escape = 0x0,
	eKI_1 = 0x1,
	eKI_2 = 0x2,
	eKI_3 = 0x3,
	eKI_4 = 0x4,
	eKI_5 = 0x5,
	eKI_6 = 0x6,
	eKI_7 = 0x7,
	eKI_8 = 0x8,
	eKI_9 = 0x9,
	eKI_0 = 0xA,
	eKI_Minus = 0xB,
	eKI_Equals = 0xC,
	eKI_Backspace = 0xD,
	eKI_Tab = 0xE,
	eKI_Q = 0xF,
	eKI_W = 0x10,
	eKI_E = 0x11,
	eKI_R = 0x12,
	eKI_T = 0x13,
	eKI_Y = 0x14,
	eKI_U = 0x15,
	eKI_I = 0x16,
	eKI_O = 0x17,
	eKI_P = 0x18,
	eKI_LBracket = 0x19,
	eKI_RBracket = 0x1A,
	eKI_Enter = 0x1B,
	eKI_LCtrl = 0x1C,
	eKI_A = 0x1D,
	eKI_S = 0x1E,
	eKI_D = 0x1F,
	eKI_F = 0x20,
	eKI_G = 0x21,
	eKI_H = 0x22,
	eKI_J = 0x23,
	eKI_K = 0x24,
	eKI_L = 0x25,
	eKI_Semicolon = 0x26,
	eKI_Apostrophe = 0x27,
	eKI_Tilde = 0x28,
	eKI_LShift = 0x29,
	eKI_Backslash = 0x2A,
	eKI_Z = 0x2B,
	eKI_X = 0x2C,
	eKI_C = 0x2D,
	eKI_V = 0x2E,
	eKI_B = 0x2F,
	eKI_N = 0x30,
	eKI_M = 0x31,
	eKI_Comma = 0x32,
	eKI_Period = 0x33,
	eKI_Slash = 0x34,
	eKI_RShift = 0x35,
	eKI_NP_Multiply = 0x36,
	eKI_LAlt = 0x37,
	eKI_Space = 0x38,
	eKI_CapsLock = 0x39,
	eKI_F1 = 0x3A,
	eKI_F2 = 0x3B,
	eKI_F3 = 0x3C,
	eKI_F4 = 0x3D,
	eKI_F5 = 0x3E,
	eKI_F6 = 0x3F,
	eKI_F7 = 0x40,
	eKI_F8 = 0x41,
	eKI_F9 = 0x42,
	eKI_F10 = 0x43,
	eKI_NumLock = 0x44,
	eKI_ScrollLock = 0x45,
	eKI_NP_7 = 0x46,
	eKI_NP_8 = 0x47,
	eKI_NP_9 = 0x48,
	eKI_NP_Substract = 0x49,
	eKI_NP_4 = 0x4A,
	eKI_NP_5 = 0x4B,
	eKI_NP_6 = 0x4C,
	eKI_NP_Add = 0x4D,
	eKI_NP_1 = 0x4E,
	eKI_NP_2 = 0x4F,
	eKI_NP_3 = 0x50,
	eKI_NP_0 = 0x51,
	eKI_F11 = 0x52,
	eKI_F12 = 0x53,
	eKI_F13 = 0x54,
	eKI_F14 = 0x55,
	eKI_F15 = 0x56,
	eKI_Colon = 0x57,
	eKI_Underline = 0x58,
	eKI_NP_Enter = 0x59,
	eKI_RCtrl = 0x5A,
	eKI_NP_Period = 0x5B,
	eKI_NP_Divide = 0x5C,
	eKI_Print = 0x5D,
	eKI_RAlt = 0x5E,
	eKI_Pause = 0x5F,
	eKI_Home = 0x60,
	eKI_Up = 0x61,
	eKI_PgUp = 0x62,
	eKI_Left = 0x63,
	eKI_Right = 0x64,
	eKI_End = 0x65,
	eKI_Down = 0x66,
	eKI_PgDn = 0x67,
	eKI_Insert = 0x68,
	eKI_Delete = 0x69,
	eKI_LWin = 0x6A,
	eKI_RWin = 0x6B,
	eKI_Apps = 0x6C,
	eKI_OEM_102 = 0x6D,
	eKI_Mouse1 = 0x100,
	eKI_Mouse2 = 0x101,
	eKI_Mouse3 = 0x102,
	eKI_Mouse4 = 0x103,
	eKI_Mouse5 = 0x104,
	eKI_Mouse6 = 0x105,
	eKI_Mouse7 = 0x106,
	eKI_Mouse8 = 0x107,
	eKI_MouseWheelUp = 0x108,
	eKI_MouseWheelDown = 0x109,
	eKI_MouseX = 0x10A,
	eKI_MouseY = 0x10B,
	eKI_MouseZ = 0x10C,
	eKI_MouseLast = 0x10D,
	eKI_XI_DPadUp = 0x200,
	eKI_XI_DPadDown = 0x201,
	eKI_XI_DPadLeft = 0x202,
	eKI_XI_DPadRight = 0x203,
	eKI_XI_Start = 0x204,
	eKI_XI_Back = 0x205,
	eKI_XI_ThumbL = 0x206,
	eKI_XI_ThumbR = 0x207,
	eKI_XI_ShoulderL = 0x208,
	eKI_XI_ShoulderR = 0x209,
	eKI_XI_A = 0x20A,
	eKI_XI_B = 0x20B,
	eKI_XI_X = 0x20C,
	eKI_XI_Y = 0x20D,
	eKI_XI_TriggerL = 0x20E,
	eKI_XI_TriggerR = 0x20F,
	eKI_XI_ThumbLX = 0x210,
	eKI_XI_ThumbLY = 0x211,
	eKI_XI_ThumbLUp = 0x212,
	eKI_XI_ThumbLDown = 0x213,
	eKI_XI_ThumbLLeft = 0x214,
	eKI_XI_ThumbLRight = 0x215,
	eKI_XI_ThumbRX = 0x216,
	eKI_XI_ThumbRY = 0x217,
	eKI_XI_ThumbRUp = 0x218,
	eKI_XI_ThumbRDown = 0x219,
	eKI_XI_ThumbRLeft = 0x21A,
	eKI_XI_ThumbRRight = 0x21B,
	eKI_XI_TriggerLBtn = 0x21C,
	eKI_XI_TriggerRBtn = 0x21D,
	eKI_XI_Connect = 0x21E,
	eKI_XI_Disconnect = 0x21F,
	eKI_PS3_Select = 0x400,
	eKI_PS3_L3 = 0x401,
	eKI_PS3_R3 = 0x402,
	eKI_PS3_Start = 0x403,
	eKI_PS3_Up = 0x404,
	eKI_PS3_Right = 0x405,
	eKI_PS3_Down = 0x406,
	eKI_PS3_Left = 0x407,
	eKI_PS3_L2 = 0x408,
	eKI_PS3_R2 = 0x409,
	eKI_PS3_L1 = 0x40A,
	eKI_PS3_R1 = 0x40B,
	eKI_PS3_Triangle = 0x40C,
	eKI_PS3_Circle = 0x40D,
	eKI_PS3_Cross = 0x40E,
	eKI_PS3_Square = 0x40F,
	eKI_PS3_StickLX = 0x410,
	eKI_PS3_StickLY = 0x411,
	eKI_PS3_StickRX = 0x412,
	eKI_PS3_StickRY = 0x413,
	eKI_PS3_RotX = 0x414,
	eKI_PS3_RotY = 0x415,
	eKI_PS3_RotZ = 0x416,
	eKI_PS3_RotX_KeyL = 0x417,
	eKI_PS3_RotX_KeyR = 0x418,
	eKI_PS3_RotZ_KeyD = 0x419,
	eKI_PS3_RotZ_KeyU = 0x41A,
	eKI_Orbis_Options = 0x800,
	eKI_Orbis_L3 = 0x801,
	eKI_Orbis_R3 = 0x802,
	eKI_Orbis_Up = 0x803,
	eKI_Orbis_Right = 0x804,
	eKI_Orbis_Down = 0x805,
	eKI_Orbis_Left = 0x806,
	eKI_Orbis_L2 = 0x807,
	eKI_Orbis_R2 = 0x808,
	eKI_Orbis_L1 = 0x809,
	eKI_Orbis_R1 = 0x80A,
	eKI_Orbis_Triangle = 0x80B,
	eKI_Orbis_Circle = 0x80C,
	eKI_Orbis_Cross = 0x80D,
	eKI_Orbis_Square = 0x80E,
	eKI_Orbis_StickLX = 0x80F,
	eKI_Orbis_StickLY = 0x810,
	eKI_Orbis_StickRX = 0x811,
	eKI_Orbis_StickRY = 0x812,
	eKI_Orbis_RotX = 0x813,
	eKI_Orbis_RotY = 0x814,
	eKI_Orbis_RotZ = 0x815,
	eKI_Orbis_RotX_KeyL = 0x816,
	eKI_Orbis_RotX_KeyR = 0x817,
	eKI_Orbis_RotZ_KeyD = 0x818,
	eKI_Orbis_RotZ_KeyU = 0x819,
	eKI_Orbis_LeftTrigger = 0x81A,
	eKI_Orbis_RightTrigger = 0x81B,
	eKI_Orbis_StickLL = 0x81C,
	eKI_Orbis_StickLR = 0x81D,
	eKI_Orbis_StickLD = 0x81E,
	eKI_Orbis_StickLU = 0x81F,
	eKI_Orbis_Touch = 0x820,
	eKI_SYS_Commit = 0x1000,
	eKI_SYS_ConnectDevice = 0x1001,
	eKI_SYS_DisconnectDevice = 0x1002,
	eKI_Unknown = 0xFFFFFFFF,
};

enum class EGameStatType : int16_t
{
	eGS_InvalidStat = -1,
	eGS_Absorption = 0,
	eGS_Accuracy,
	eGS_ActivateDuration,
	eGS_AimAccuracy,
	eGS_AiSoundRadius,
	eGS_AmmoAmount,
	eGS_ArmorHealth,
	eGS_ArmorRegenHps,
	eGS_ArmorRegenTimeout,
	eGS_ArmsDamageMult,
	eGS_AutoZoomIn,
	eGS_AutoZoomOut,
	eGS_BallisticIronsight,
	eGS_BayonetMeleeDuration,
	eGS_BayonetMeleeOutDuration,
	eGS_BlindAmountMul,
	eGS_BodyDamageMult,
	eGS_BoltAction,
	eGS_BoltActionDuration,
	eGS_BulletPierceability,
	eGS_ClaymoreActivationDelayMul,
	eGS_ClaymoreDetectorRadius,
	eGS_ClipSize,
	eGS_CrouchSpeedMul,
	eGS_CustomizeInDuration,
	eGS_CustomizeOutDuration,
	eGS_Damage,
	eGS_DamageDropMinDistance,
	eGS_DamageDropPerMeter,
	eGS_DamageMin,
	eGS_DamageUnderbarrel,
	eGS_DeselectDuration,
	eGS_DeselectDurationBuff,
	eGS_ExtraAmmoPistolMul,
	eGS_ExtraAmmoPrimaryMul,
	eGS_FireUnderbarrelDuration,
	eGS_FireUnderbarrelOnRelease,
	eGS_FlashbangTimeMul,
	eGS_FovMul,
	eGS_HeadDamageMult,
	eGS_HealthMul,
	eGS_HipAccuracy,
	eGS_HolsterInDuration,
	eGS_HpRegenerationHps,
	eGS_HpRegenerationTimeout,
	eGS_IgnoreBulletBody,
	eGS_SuppressIgnoreBulletBody,
	eGS_IgnoreBulletHead,
	eGS_SuppressIgnoreBulletHead,
	eGS_KnockBackChance,
	eGS_KnockBackMinDistance,
	eGS_KnockBackMaxDistance,
	eGS_KnockBackResistance,
	eGS_KnockBackStaminaDamage,
	eGS_LegsDamageMult,
	eGS_Unk55,
	eGS_Unk56,
	eGS_MeleeDamage,
	eGS_MeleeDuration,
	eGS_MeleeDurationBuff,
	eGS_MeleeKnockBackChance,
	eGS_MeleeKnockBackStaminaDamage,
	eGS_CyborgDamageBuff,
	eGS_MeleeOutDuration,
	eGS_MeleeRadius,
	eGS_MeleeRange,
	eGS_MeleeRes,
	eGS_Range,
	eGS_RclAtt,
	eGS_RclDec,
	eGS_RclDecDelay,
	eGS_RclMax,
	eGS_RclRnd,
	eGS_RclSmth,
	eGS_ReloadDuration,
	eGS_ReloadDurationBuff,
	eGS_ReloadUnderbarrelDuration,
	eGS_ResArms,
	eGS_ResBody,
	eGS_ResHead,
	eGS_ResLegs,
	eGS_Resistance,
	eGS_Rpm,
	eGS_MoveSoundVolumeDamping,
	eGS_SecondaryMeleeDamage,
	eGS_SecondaryMeleeDuration,
	eGS_SecondaryMeleeDurationBuff,
	eGS_SecondaryMeleeOutDuration,
	eGS_SecondaryMeleeRadius,
	eGS_SecondaryMeleeRange,
	eGS_SelectDuration,
	eGS_SelectDurationBuff,
	eGS_SlideDistMul,
	eGS_SplashRes,
	eGS_SprdAtt,
	eGS_SprdDec,
	eGS_SprdDecDelay,
	eGS_SprdMax,
	eGS_SprdMin,
	eGS_SprintSpeedMul,
	eGS_SprintTimeMul,
	eGS_StaminaMul,
	eGS_SwayDec,
	eGS_SwayMinX,
	eGS_SwayMinY,
	eGS_SwaySpeedMult,
	eGS_ThrowDelayDuration,
	eGS_ThrowDuration,
	eGS_ThrowFireDelayDuration,
	eGS_TossDuration,
	eGS_ZoomFactor,
	eGS_ZoomInDuration,
	eGS_ZoomInDurationBuff,
	eGS_ZoomOutDuration,
	eGS_ZoomOutDurationBuff,
	eGS_ZoomedBoltActionDuration,
	eGS_PoisonGrenadeDamageMul,
	eGS_InSlotSelectDuration,
	eGS_InSlotDeselectDuration,
	eGS_UseInSlotWeaponChange,
	eGS_CameraShakeMul,
	eGS_SprdInverted,
	eGS_StrafeMultiplier,
	eGS_ClimbExtraHeight,
	eGS_ArmorAbsorbRatio,
};

struct TKeyName
{
	const char* key;
	TKeyName() { key = ""; }
	TKeyName(const char* _key) { key = _key; };
	operator const char* () const { return key; };
	const char* c_str() const { return key; }
};

struct SInputSymbol
{
	enum EType
	{
		Button,
		Toggle,
		RawAxis,
		Axis,
		Trigger,
	};
	bool GetKeyState(bool async = true)
	{
		if (state == EInputState::eIS_Down)
		{
			if (async) state = EInputState::eIS_Changed;
			return true;
		}
		return false;
	}
	EKeyId			keyId;
	TKeyName		name;
	unsigned int	devSpecId;
	EInputState		state;
	const EType		type;
	float			value;
	unsigned int	user;
	EDeviceId		deviceId;
	unsigned char	deviceIndex;
};

struct SInputEvent
{
	EDeviceId deviceId;
	EInputState state;
	wchar_t inputChar;
	TKeyName keyName;
	EKeyId keyId;
	unsigned int timestamp;
	int modifiers;
	float value;
	SInputSymbol* pSymbol;
	unsigned __int8 deviceIndex;
};

template <class TVarType, typename TMaskType = uint32_t, TMaskType TMaxMaskValue = 0x7FFFFFFF>
class CMaskedVarT
{
public:
	CMaskedVarT() : m_mask(0) { }
	CMaskedVarT(const TVarType v) { Set(v); }
	operator TVarType () const { return this->Get(); }
	CMaskedVarT& operator += (const TVarType rhs)
	{
		TVarType v = this->Get();
		v += rhs;
		this->Set(v);
		return (*this);
	}
	CMaskedVarT& operator -= (const TVarType rhs)
	{
		TVarType v = this->Get();
		v -= rhs;
		this->Set(v);
		return (*this);
	}
	CMaskedVarT& operator *= (const TVarType rhs)
	{
		TVarType v = this->Get();
		v *= rhs;
		this->Set(v);
		return (*this);
	}
	CMaskedVarT& operator /= (const TVarType rhs)
	{
		TVarType  v = this->Get();
		v /= rhs;
		this->Set(v);
		return (*this);
	}
	CMaskedVarT& operator = (const TVarType rhs)
	{
		Set(rhs);
		return (*this);
	}
private:
	void Set(const TVarType v)
	{
		UVal		w;
		w.asVarType = v;
		m_val.asMaskType = (w.asMaskType ^ m_mask);
	}
	TVarType Get() const
	{
		UVal  w;
		w.asMaskType = 0;
		if (m_mask > 0) w.asMaskType = (m_val.asMaskType ^ m_mask);
		return w.asVarType;
	}
	union UVal
	{
		TVarType  asVarType;
		TMaskType  asMaskType;
	};
	UVal  m_val;
	TMaskType  m_mask;
};

using TMaskedFloat = CMaskedVarT<float>;

class CStatsArray
{
public:
	float operator[](int type)
	{
		return GetValue(type);
	}
	void SetValue(EGameStatType type, float value)
	{
		auto it = m_stats.find((int16_t)type);
		if (it != m_stats.end())
		{
			it->second = value;
		}
	}
	float GetValue(int type)
	{
		auto it = m_stats.find(type);
		if (it == m_stats.end()) return 1072.0f;
		return it->second;
	}
	auto begin() { return m_stats.begin(); }
	auto end() { return m_stats.end(); }
private:
	std::map<int16_t, TMaskedFloat> m_stats;
};

enum typeZero {
	ZERO
};

template <typename F> struct Vec3_tpl
{
	F x, y, z;
	Vec3_tpl(typeZero) : x(0), y(0), z(0) { }
	explicit Vec3_tpl(F f) : x(f), y(f), z(f) { }

	Vec3_tpl() { Vec3_tpl<F>(0, 0, 0); }
	Vec3_tpl(F xt, F yt, F zt) { x = xt; y = yt; z = zt; }
	void Set(F xt, F yt, F zt) { x = xt; y = yt; z = zt; }

	Vec3_tpl operator /  (F f) { return Vec3_tpl(x / f, y / f, z / f); }
	Vec3_tpl& operator = (const Vec3_tpl<F>& source) { x = source.x; y = source.y; z = source.z; return *this; }
	Vec3_tpl& operator = (const F value) { x = value; y = value; z = value;   return *this; }
	Vec3_tpl operator * (F f) { return Vec3_tpl(x * f, y * f, z * f); }
	Vec3_tpl& operator *= (F f) { x *= f; y *= f; z *= f; return *this; }
	Vec3_tpl& operator /= (F f) { x /= f; y /= f; z /= f; return *this; }
	bool operator!=(const Vec3_tpl<F>& vec) { return !(*this == vec); }

	Vec3_tpl& operator += (const Vec3_tpl<F>& vec) { x += vec.x; y += vec.y; z += vec.z; return *this; }
	Vec3_tpl& operator += (F f) { x += f; y += f; z += f; return *this; }

	friend Vec3_tpl operator + (const Vec3_tpl& vec1, const Vec3_tpl& vec2) { return Vec3_tpl(vec1.x + vec2.x, vec1.y + vec2.y, vec1.z + vec2.z); }
	friend Vec3_tpl operator + (const Vec3_tpl& vec1, const F* vec2) { return vec1 + Vec3_tpl(vec2); }
	friend Vec3_tpl operator + (const F* vec1, const Vec3_tpl& vec2) { return Vec3_tpl(vec1) + vec2; }

	friend Vec3_tpl operator - (const Vec3_tpl& vec1, const Vec3_tpl& vec2) { return Vec3_tpl(vec1.x - vec2.x, vec1.y - vec2.y, vec1.z - vec2.z); }
	friend Vec3_tpl operator - (const Vec3_tpl& vec1, const F* vec2) { return vec1 - Vec3_tpl(vec2); }
	friend Vec3_tpl operator - (const F* vec1, const Vec3_tpl& vec2) { return Vec3_tpl(vec1) - vec2; }
};

template <typename F> struct Matrix33_tpl
{
	F m00, m01, m02;
	F m10, m11, m12;
	F m20, m21, m22;

	Matrix33_tpl<F>(const Vec3_tpl<F>& vx, const Vec3_tpl<F>& vy, const Vec3_tpl<F>& vz)
	{
		m00 = (vx.x);
		m01 = (vy.x);
		m02 = (vz.x);

		m10 = (vx.y);
		m11 = (vy.y);
		m12 = (vz.y);

		m20 = (vx.z);
		m21 = (vy.z);
		m22 = (vz.z);
	}
};

template <typename F> struct Quat_tpl
{
	Vec3_tpl<F> v;
	F w;
	friend float operator | (const Quat_tpl<F>& q, const Quat_tpl<F>& p)
	{
		return (q.v.x * p.v.x + q.v.y * p.v.y + q.v.z * p.v.z + q.w * p.w);
	}

	friend Quat_tpl<F> operator - (const Quat_tpl<F>& q, const Quat_tpl<F>& p)
	{
		Quat_tpl<F> ret;
		ret.w = q.w - p.w;

		ret.v.x = q.v.x - p.v.x;
		ret.v.y = q.v.y - p.v.y;
		ret.v.z = q.v.z - p.v.z;

		return ret;
	}

	Quat_tpl<F>() {}

	Quat_tpl<F>(const Matrix33_tpl<F>& m)
	{
		float s, p, tr = m.m00 + m.m11 + m.m22;
		w = 1, v.x = 0, v.y = 0, v.z = 0;

		if (tr > 0)
			s = _sqrt(tr + 1.0f), p = 0.5f / s, w = s * 0.5f, v.x = (m.m21 - m.m12) * p, v.y = (m.m02 - m.m20) * p, v.z = (m.m10 - m.m01) * p;
		else if ((m.m00 >= m.m11) && (m.m00 >= m.m22))
			s = _sqrt(m.m00 - m.m11 - m.m22 + 1.0f), p = 0.5f / s, w = (m.m21 - m.m12) * p, v.x = s * 0.5f, v.y = (m.m10 + m.m01) * p, v.z = (m.m20 + m.m02) * p;
		else if ((m.m11 >= m.m00) && (m.m11 >= m.m22))
			s = _sqrt(m.m11 - m.m22 - m.m00 + 1.0f), p = 0.5f / s, w = (m.m02 - m.m20) * p, v.x = (m.m01 + m.m10) * p, v.y = s * 0.5f, v.z = (m.m21 + m.m12) * p;
		else if ((m.m22 >= m.m00) && (m.m22 >= m.m11))
			s = _sqrt(m.m22 - m.m00 - m.m11 + 1.0f), p = 0.5f / s, w = (m.m10 - m.m01) * p, v.x = (m.m02 + m.m20) * p, v.y = (m.m12 + m.m21) * p, v.z = s * 0.5f;
	}

};

template <typename F> struct QuatT_tpl
{
	Quat_tpl<F> q;
	Vec3_tpl<F> t;
};

template <typename F> struct Matrix34_tpl
{
	F m00, m01, m02, m03;
	F m10, m11, m12, m13;
	F m20, m21, m22, m23;

	template<class F1> explicit Matrix34_tpl(const QuatT_tpl<F1>& q) {
		Vec3_tpl<F1> v2 = q.q.v + q.q.v;
		F1 xx = 1 - v2.x * q.q.v.x;		F1 yy = v2.y * q.q.v.y;		F1 xw = v2.x * q.q.w;
		F1 xy = v2.y * q.q.v.x;			F1 yz = v2.z * q.q.v.y;		F1 yw = v2.y * q.q.w;
		F1 xz = v2.z * q.q.v.x;			F1 zz = v2.z * q.q.v.z;		F1 zw = v2.z * q.q.w;
		m00 = F(1 - yy - zz);			m01 = F(xy - zw);			m02 = F(xz + yw);			m03 = F(q.t.x);
		m10 = F(xy + zw);				m11 = F(xx - zz);			m12 = F(yz - xw);			m13 = F(q.t.y);
		m20 = F(xz - yw);				m21 = F(yz + xw);			m22 = F(xx - yy);			m23 = F(q.t.z);
	}

	Vec3_tpl <F>GetTranslation() const { return Vec3_tpl <F>(m03, m13, m23); }
};

template <typename F> struct Vec2_tpl
{
	F x, y;
	Vec2_tpl() : x(0), y(0) { }
	explicit Vec2_tpl(F f) : x(f), y(f) { }

	Vec2_tpl(F xt, F yt) { x = xt; y = yt; }

	void Set(F xt, F yt) { x = xt; y = yt; }
};

template <typename F>
struct Color_tpl
{
public:
	F a, r, g, b;

	Color_tpl() { Color_tpl(0, 0, 0, 0); }
	Color_tpl(int a, int r, int g, int b) { this->a = a; this->r = r; this->g = g; this->b = b; }
	Color_tpl(int r, int g, int b) { this->a = 255; this->r = r; this->g = g; this->b = b; }
	Color_tpl(float r, float g, float b) { this->a = 255; this->r = r * 255; this->g = g * 255; this->b = b * 255; }
	Color_tpl(unsigned long color) { this->b = (color & 0xff); this->g = ((color >> 8) & 0xff); this->r = ((color >> 16) & 0xff); this->a = ((color >> 24) & 0xff); }
	inline float* Base()
	{
		float fColor[3];
		fColor[0] = this->r / 255.0f;
		fColor[1] = this->g / 255.0f;
		fColor[2] = this->b / 255.0f;
		return &fColor[0];
	}

	inline float rBase() const { return this->r / 255.0f; }
	inline float gBase() const { return this->g / 255.0f; }
	inline float bBase() const { return this->b / 255.0f; }
	inline float aBase() const { return this->a / 255.0f; }

	inline operator unsigned long() const { return (a << 24) | (r) | (g << 8) | (b << 16); }

	inline unsigned long long Reversed() const { return (a << 24) | (r << 16) | (g << 8) | (b); }
};

template <typename F>
struct ReversedColor_tpl
{
public:
	F a, r, g, b;

	ReversedColor_tpl() { ReversedColor_tpl(0, 0, 0, 0); }
	ReversedColor_tpl(int a, int r, int g, int b) { this->a = a; this->r = r; this->g = g; this->b = b; }
	ReversedColor_tpl(int r, int g, int b) { this->a = 255; this->r = r; this->g = g; this->b = b; }
	ReversedColor_tpl(float r, float g, float b) { this->a = 255; this->r = r * 255; this->g = g * 255; this->b = b * 255; }
	ReversedColor_tpl(unsigned long color) { this->b = (color & 0xff); this->g = ((color >> 8) & 0xff); this->r = ((color >> 16) & 0xff); this->a = ((color >> 24) & 0xff); }
	inline float* Base()
	{
		float fColor[3];
		fColor[0] = this->r / 255.0f;
		fColor[1] = this->g / 255.0f;
		fColor[2] = this->b / 255.0f;
		return &fColor[0];
	}

	inline float rBase() const { return this->r / 255.0f; }
	inline float gBase() const { return this->g / 255.0f; }
	inline float bBase() const { return this->b / 255.0f; }
	inline float aBase() const { return this->a / 255.0f; }

	inline operator unsigned long() const { return (a << 24) | (r << 16) | (g << 8) | (b); }
};

template <typename F> struct HUDSilhouettesColor_tpl
{
	F r, g, b, a;
	HUDSilhouettesColor_tpl<F>() {
		r = 0;
		g = 0;
		b = 0;
		a = 1.2;
	}
	HUDSilhouettesColor_tpl<F>(F rv, F gv, F bv) {
		r = rv;
		g = gv;
		b = bv;
		a = 1.2;
	}
};

struct AABB
{
	Vec3_tpl<float> min, max;
	Vec3_tpl<float> GetCenter() { return (min + max) * 0.5f; }
	bool IsReset() { return min.x > max.x; }
	void Reset() { min = Vec3_tpl<float>(1e15f); max = Vec3_tpl<float>(-1e15f); }
};

typedef Color_tpl<int> Color;
typedef ReversedColor_tpl<int> ReversedColor;
typedef Vec3_tpl<float>	Vec3;
typedef Vec2_tpl<float> Vec2;
typedef QuatT_tpl<float> QuatT;
typedef Matrix34_tpl<float> Matrix34;
typedef Quat_tpl<float> Quat;
typedef HUDSilhouettesColor_tpl<float> HUDSilhouettesColor;

enum TextFlags : unsigned char
{
	TEXT_LEFT = 0 << 0,
	TEXT_RIGHT = 1 << 1,
	TEXT_CENTERED_X = 1 << 2,
	TEXT_CENTERED_Y = 1 << 3,
	TEXT_CENTERED = 1 << 2 | 1 << 3,
};

enum EUIDRAWHORIZONTAL {
	UIDRAWHORIZONTAL_LEFT,
	UIDRAWHORIZONTAL_CENTER,
	UIDRAWHORIZONTAL_RIGHT
};

enum EUIDRAWVERTICAL {
	UIDRAWVERTICAL_TOP,
	UIDRAWVERTICAL_CENTER,
	UIDRAWVERTICAL_BOTTOM
};

enum EHARDWAREMOUSEEVENT
{
	HARDWAREMOUSEEVENT_MOVE,
	HARDWAREMOUSEEVENT_LBUTTONDOWN,
	HARDWAREMOUSEEVENT_LBUTTONUP,
	HARDWAREMOUSEEVENT_LBUTTONDOUBLECLICK,
	HARDWAREMOUSEEVENT_RBUTTONDOWN,
	HARDWAREMOUSEEVENT_RBUTTONUP,
	HARDWAREMOUSEEVENT_RBUTTONDOUBLECLICK,
	HARDWAREMOUSEEVENT_MBUTTONDOWN,
	HARDWAREMOUSEEVENT_MBUTTONUP,
	HARDWAREMOUSEEVENT_MBUTTONDOUBLECLICK,
	HARDWAREMOUSEEVENT_WHEEL,
};

enum class EWeaponStates
{
	eWS_Disabled,
	eWS_Idle,
	eWS_IdleZoomed,
	eWS_Fire,
	eWS_IdleUnderBarrel,
	eWS_HoldFireUnderBarrel,
	eWS_FireUnderBarrel,
	eWS_ReloadUnderBarrel,
	eWS_HolsterInDisabled,
	eWS_HolsterInUnderBarrel,
	eWS_HolsteredUnderBarrel,
	eWS_MeleeUnderBarrel,
	eWS_ThrowingFire,
	eWS_ThrowingFireActivate,
	eWS_ZoomedFire,
	eWS_ZoomInFire,
	eWS_ZoomOutFire,
	eWS_Reload,
	eWS_ReloadBarrel,
	eWS_BoltAction,
	eWS_ZoomedBoltAction,
	eWS_ZoomIn,
	eWS_ZoomOut,
	eWS_ZoomOutReloadAuto,
	eWS_ZoomOutReloadManual,
	eWS_ZoomOutQSA,
	eWS_ZoomOutMelee,
	eWS_ZoomOutBoltAction,
	eWS_ZoomOutCustomize,
	eWS_Throwing,
	eWS_Toss,
	eWS_Melee,
	eWS_Select,
	eWS_Deselect,
	eWS_Holding,
	eWS_Activate,
	eWS_Customize,
	eWS_CustomizeIn,
	eWS_CustomizeOut,
	eWS_HolsterIn,
	eWS_Holstered,
	eWS_StartRestoreSelf,
	eWS_StartRestoreTeamMate,
	eWS_CancelRestore,
	eWS_RestoreSelf,
	eWS_RestoreTeamMate,
	eWS_TryingRestoreSelf,
	eWS_TryingRestoreTeamMate,
	eWS_DropAmmoPack,
	eWS_Resurrect,
	eWS_ResetClipAmmo,
	eWS_Last,
	eWS_Num = eWS_Last
};

enum class entity_query_flags {
	ent_static = 0x1,
	ent_sleeping_rigid = 0x2,
	ent_rigid = 0x4,
	ent_living = 0x8,
	ent_independent = 0x10,
	ent_deleted = 0x80,
	ent_terrain = 0x100,
	ent_areas = 0x20,
	ent_triggers = 0x40,
	ent_ignore_noncolliding = 0x10000,
	ent_sort_by_mass = 0x20000,
	ent_allocate_list = 0x40000,
	ent_addref_results = 0x100000,
	ent_water = 0x200,
	ent_no_ondemand_activation = 0x80000,
	ent_delayed_deformations = 0x80000,

	pef_update = 0x800,

	ent_flagged_only = pef_update,
	ent_skip_flagged = pef_update * 2,
	ent_all = ent_static | ent_sleeping_rigid | ent_rigid | ent_living | ent_independent | ent_terrain,
};

template <typename T>
class CryStringT {
public:

	struct StrHeader {
		volatile int nRefCount;
		int nLength;
		int nAllocSize;
	};

public:

	T* m_str;
	StrHeader* m_header;
};

enum EFlowchartState {

	eFS_None = 0xFFFFFFFF,
	eFS_First = 0x0,
	eFS_NoUI = 0x0,
	eFS_Login = 0x1,
	eFS_LoadingLobby = 0x2,
	eFS_CharacterCreation = 0x3,
	eFS_Lobby = 0x4,
	eFS_LoadingLevel = 0x5,
	eFS_Ingame = 0x6,
	eFS_Renaming = 0x7,
	eFS_PromoTutorial = 0x8,
	eFS_PostGame = 0x9,
	eFS_Count = 0xA,
};
