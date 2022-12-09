#pragma once

namespace GameSDK {
	namespace Locations {
		DWORD64 dwSystemGlobalEnvironment = 0x142262698;
		DWORD64 dwCHUDSilhouettes = 0x1416D6F00;
	}
	namespace Enums {
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
		enum EBonesID {
			BONE_BIP01 = 0x0,
			BONE_SPINE = 0x1,
			BONE_SPINE2 = 0x2,
			BONE_SPINE3 = 0x3,
			BONE_HEAD = 0x4,
			BONE_EYE_R = 0x5,
			BONE_EYE_L = 0x6,
			BONE_WEAPON = 0x7,
			BONE_FOOT_R = 0x8,
			BONE_FOOT_L = 0x9,
			BONE_ARM_R = 0xA,
			BONE_ARM_L = 0xB,
			BONE_CALF_R = 0xC,
			BONE_CALF_L = 0xD,
			BONE_CAMERA = 0xE,
			BONE_ID_NUM = 0xF,
		};
		enum EFRAMEWORKLISTENERPRIORITY
		{
			FRAMEWORKLISTENERPRIORITY_DEFAULT,
			FRAMEWORKLISTENERPRIORITY_GAME,
			FRAMEWORKLISTENERPRIORITY_HUD,
			FRAMEWORKLISTENERPRIORITY_MENU
		};
		enum EGameRoomType {

			eGRT_None = 0x0,
			eGRT_PvE_Private = 0x1,
			eGRT_PvP_Public = 0x2,
			eGRT_PvP_ClanWar = 0x4,
			eGRT_PvP_Autostart = 0x8,
			eGRT_PvE_Autostart = 0x10,
			eGRT_PvP_Rating = 0x20,
			eGRT_PvP = 0x2E,
			eGRT_PvE = 0x11,
			eGRT_All = 0x3F,
		};
		enum ESessionStatus
		{
			eGRSS_None,
			eGRSS_Starting,
			eGRSS_Running,
			eGRSS_Finishing,
			eGRSS_Failed
		};
		enum ECharacterClassId
		{
			eCCI_First = 0,
			eCCI_Rifleman = 0,
			eCCI_Heavy,
			eCCI_Recon,
			eCCI_Medic,
			eCCI_Engineer,
			eCCI_Count,
			eCCI_Other = -1,
		};
		enum EGameRoomPlayerStatus {

			eGRPS_NotReady,
			eGRPS_Ready,
			eGRPS_CantBeReady
		};
	}
	namespace Math {
		enum typeZero {
			ZERO
		};
		float sqrt_v(float number) {
			long i;
			float x2, y;
			const float threehalfs = 1.5F;

			x2 = number * 0.5F;
			y = number;
			i = *(long*)&y;
			i = 0x5f3759df - (i >> 1);
			y = *(float*)&i;
			y = y * (threehalfs - (x2 * y * y));
			y = y * (threehalfs - (x2 * y * y));
			y = y * (threehalfs - (x2 * y * y));

			return 1 / y;
		}
		template <typename F> struct Vec3_tpl
		{
			F x, y, z;
			Vec3_tpl(typeZero) : x(0), y(0), z(0) { }
			explicit Vec3_tpl(F f) : x(f), y(f), z(f) { }
			Vec3_tpl() { Vec3_tpl<F>(0, 0, 0); }
			Vec3_tpl(F xt, F yt, F zt) { x = xt; y = yt; z = zt; }
			void Set(F xt, F yt, F zt) { x = xt; y = yt; z = zt; }
			F GetLength() const { return (F)sqrt_v(x * x + y * y + z * z); }
			F GetDistance(Vec3_tpl VecB) { return (F)sqrt_v(((x - VecB.x) * (x - VecB.x)) + ((y - VecB.y) * (y - VecB.y)) + ((z - VecB.z) * (z - VecB.z))); }
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
			void SetRotationVDir(const Vec3_tpl<F>& vdir) {
				w = (0.70710676908493042f);
				v.x = (vdir.z * 0.70710676908493042f);
				v.y = (0.0f);
				v.z = (0.0f);

				F l = (F)sqrt_v(vdir.x * vdir.x + vdir.y * vdir.y);

				if (l > (0.00001)) {
					Vec3_tpl<F> hv;
					hv.x = vdir.x / l;
					hv.y = vdir.y / l + 1.0f;
					hv.z = l + 1.0f;

					F r = (F)sqrt_v(hv.x * hv.x + hv.y * hv.y);
					F s = (F)sqrt_v(hv.z * hv.z + vdir.z * vdir.z);
					F hacos0 = 0.0;
					F hasin0 = -1.0;

					if (r > (0.00001)) {
						hacos0 = hv.y / r;
						hasin0 = -hv.x / r;
					}
					F hacos1 = hv.z / s;
					F hasin1 = vdir.z / s;
					w = (hacos0 * hacos1);
					v.x = (hacos0 * hasin1);
					v.y = (hasin0 * hasin1);
					v.z = (hasin0 * hacos1);
				}
			}
			static Quat_tpl<F> CreateRotationVDir(const Vec3_tpl<F>& vdir) {
				Quat_tpl<F> q;
				q.SetRotationVDir(vdir);
				return q;
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

			friend Vec2_tpl<F>& operator+=(Vec2_tpl<F>& l, const Vec2_tpl<F>& r) {
				l.x += r.x;
				l.y += r.y;
				return l;
			}

		};
		template <typename F> struct Color_tpl
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
		};
		template <typename F> struct ReversedColor_tpl
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
		typedef Matrix33_tpl<float>	Matrix33;
		typedef Quat_tpl<float> Quat;
		typedef HUDSilhouettesColor_tpl<float> HUDSilhouettesColor;

		static ReversedColor FromHSB(float hue, float saturation, float brightness)
		{
			float h = hue == 1.0f ? 0 : hue * 6.0f;
			float f = h - (int)h;
			float p = brightness * (1.0f - saturation);
			float q = brightness * (1.0f - saturation * f);
			float t = brightness * (1.0f - (saturation * (1.0f - f)));

			if (h < 1)
			{
				return ReversedColor(
					(unsigned char)(brightness * 255),
					(unsigned char)(t * 255),
					(unsigned char)(p * 255)
				);
			}
			else if (h < 2)
			{
				return ReversedColor(
					(unsigned char)(q * 255),
					(unsigned char)(brightness * 255),
					(unsigned char)(p * 255)
				);
			}
			else if (h < 3)
			{
				return ReversedColor(
					(unsigned char)(p * 255),
					(unsigned char)(brightness * 255),
					(unsigned char)(t * 255)
				);
			}
			else if (h < 4)
			{
				return ReversedColor(
					(unsigned char)(p * 255),
					(unsigned char)(q * 255),
					(unsigned char)(brightness * 255)
				);
			}
			else if (h < 5)
			{
				return ReversedColor(
					(unsigned char)(t * 255),
					(unsigned char)(p * 255),
					(unsigned char)(brightness * 255)
				);
			}
			else
			{
				return ReversedColor(
					(unsigned char)(brightness * 255),
					(unsigned char)(p * 255),
					(unsigned char)(q * 255)
				);
			}
		}
	}

	template <typename T>
	struct Plane_tpl {
		Vec3_tpl<T> n;
		T d;
	};
	class CCamera {
	public:
		struct ScissorInfo {

			unsigned __int16 x1;
			unsigned __int16 y1;
			unsigned __int16 x2;
			unsigned __int16 y2;
		};

	public:
		Matrix34_tpl<float> m_Matrix;
		float m_fov;
		int m_Width;
		int m_Height;
		float m_ProjectionRatio;
		float m_PixelAspectRatio;
		Vec3_tpl<float> m_edge_nlt;
		Vec3_tpl<float> m_edge_plt;
		Vec3_tpl<float> m_edge_flt;
		float m_asymL;
		float m_asymR;
		float m_asymB;
		float m_asymT;
		Vec3_tpl<float> m_cltp;
		Vec3_tpl<float> m_crtp;
		Vec3_tpl<float> m_clbp;
		Vec3_tpl<float> m_crbp;
		Vec3_tpl<float> m_cltn;
		Vec3_tpl<float> m_crtn;
		Vec3_tpl<float> m_clbn;
		Vec3_tpl<float> m_crbn;
		Vec3_tpl<float> m_cltf;
		Vec3_tpl<float> m_crtf;
		Vec3_tpl<float> m_clbf;
		Vec3_tpl<float> m_crbf;
		Plane_tpl<float> m_fp[6];
		unsigned int m_idx1[6];
		unsigned int m_idy1[6];
		unsigned int m_idz1[6];
		unsigned int m_idx2[6];
		unsigned int m_idy2[6];
		unsigned int m_idz2[6];
		float m_zrangeMin;
		float m_zrangeMax;
		int m_nPosX;
		int m_nPosY;
		int m_nSizeX;
		int m_nSizeY;
		interface IVisArea* m_pPortal;
		ScissorInfo m_ScissorInfo;
		void* m_pMultiCamera;
		Vec3_tpl<float> m_OccPosition;
		int m_JustActivated;
	};
	struct IRenderer {
		struct SWorldToScreen
		{
		public:
			float toX;
			float toY;
			float toZ;
			float* outX;
			float* outY;
			float* outZ;
		};
	public:
		CCamera* GetViewCamera(const CCamera* pCamera, bool bSet) {
			return v_spoof<CCamera*>(this, 68, pCamera, bSet);
		}
		int GetWidth() {
			return v_spoof<int>(this, 0x330 / 8);
			//return GetVFunc<int(__fastcall*)(PVOID)>(this, 0x330)(this); 
		}
		int GetHeight() {
			return v_spoof<int>(this, 0x338 / 8);
			//return GetVFunc<int(__fastcall*)(PVOID)>(this, 0x338)(this); 
		}
		IDXGISwapChain* GetIDXGISwapChain() {
			//48 8B 8B ?? ?? ?? ?? 44 8B C7 8B D6 48 8B 01 FF 50 40
			return *(IDXGISwapChain**)((uintptr_t)this + 0x14CF00);
		}
		bool ProjectToScreen(SWorldToScreen* pWorldToScreen) {
			return v_spoof<bool>(this, 0x380 / 8, pWorldToScreen);
			//return GetVFunc<bool(__thiscall*)(PVOID, SWorldToScreen*)>(this, 0x380)(this, pWorldToScreen); 
		}
		bool WorldToScreen(Vec3 vPos, Vec3& vOut) {
			SWorldToScreen pWorldToScreen;

			pWorldToScreen.toX = vPos.x;
			pWorldToScreen.toY = vPos.y;
			pWorldToScreen.toZ = vPos.z;
			pWorldToScreen.outX = &vOut.x;
			pWorldToScreen.outY = &vOut.y;
			pWorldToScreen.outZ = &vOut.z;

			ProjectToScreen(&pWorldToScreen);

			vOut.x *= (GetWidth() * 0.01f);
			vOut.y *= (GetHeight() * 0.01f);
			vOut.z *= 1.0f;

			return ((vOut.z < 1.0f) && (vOut.x > 0) && (vOut.x < GetWidth()) && (vOut.y > 0) && (vOut.y < GetHeight()));
		}
	};
	struct STextDrawContext
	{
		unsigned int m_fxIdx;
		Math::Vec2 m_size;
		float m_widthScale;
		float m_clipX;
		float m_clipY;
		float m_clipWidth;
		float m_clipHeight;
		bool m_proportional;
		bool m_sizeIn800x600;
		bool m_clippingEnabled;
		bool m_framed;
		int m_colorOverride;
		int m_drawTextFlags;
		STextDrawContext() : m_fxIdx(0), m_clipX(0), m_clipY(0), m_clipWidth(0), m_clipHeight(0), m_proportional(true), m_sizeIn800x600(true), m_clippingEnabled(false), m_framed(false), m_colorOverride() {}
		void Reset() { *this = STextDrawContext(); }
		void SetEffect(unsigned int fxIdx) { m_fxIdx = fxIdx; }
		void SetSize(const Math::Vec2& size) { m_size = size; }
		void SetCharWidthScale(float widthScale) { m_widthScale = widthScale; }
		void SetClippingRect(float x, float y, float width, float height) { m_clipX = x; m_clipY = y; m_clipWidth = width; m_clipHeight = height; }
		void SetProportional(bool proportional) { m_proportional = proportional; }
		void SetSizeIn800x600(bool sizeIn800x600) { m_sizeIn800x600 = sizeIn800x600; }
		void EnableClipping(bool enable) { m_clippingEnabled = enable; }
		void EnableFrame(bool enable) { m_framed = enable; }
		void SetColor(const int& col) { m_colorOverride = col; }
		float GetCharWidth() const { return m_size.x; }
		float GetCharHeight() const { return m_size.y; }
		float GetCharWidthScale() const { return m_widthScale; }
	};
	class IFFont
	{
	public:
		virtual void Function0() = 0;
		virtual void Function1() = 0;
		virtual void Function2() = 0;
		virtual bool Load(const char* pXMLFile) = 0;
		virtual void Function4() = 0;
		virtual void Function5() = 0;;
		virtual void Function6() = 0;
		virtual void DrawString(float x, float y, const char* pStr, const bool asciiMultiLine, const STextDrawContext& ctx) = 0;
		virtual void DrawStringW(float x, float y, float z, const wchar_t* pStr, const bool asciiMultiLine, const STextDrawContext& ctx) = 0;
		virtual void Function9() = 0;
		virtual Math::Vec2 GetTextSize(const char* pStr, const bool asciiMultiLine, const STextDrawContext& ctx) = 0;
		virtual Math::Vec2 GetTextSizeW(const wchar_t* pStr, const bool asciiMultiLine, const STextDrawContext& ctx) = 0;
		virtual int GetTextLength(const char* szwMsg, const bool bASCIIMultiLine) = 0;
		virtual int GetTextLengthW(const wchar_t* szwMsg, const bool bASCIIMultiLine) = 0;

	};
	class WrapFont
	{
	public:

		IFFont* font;

		WrapFont(IFFont* f) : font(f) {}

		Math::Vec2 DrawStringA(float x, float y, float fontSz, int color, Enums::TextFlags flags, const char* str, ...) {
			STextDrawContext ctx;
			ctx.m_sizeIn800x600 = false;
			ctx.m_size.x = fontSz;
			ctx.m_size.y = fontSz;
			ctx.m_colorOverride = color;
			ctx.m_widthScale = 1.0;

			Math::Vec2 v_dim = font->GetTextSize(str, 0, ctx);
			if (flags & (Enums::TextFlags::TEXT_RIGHT | Enums::TextFlags::TEXT_CENTERED))
			{
				if (flags & Enums::TextFlags::TEXT_RIGHT)
					x -= v_dim.x;
				else if (flags & Enums::TextFlags::TEXT_CENTERED_X)
					x -= 0.5f * v_dim.x;
				if (flags & Enums::TextFlags::TEXT_CENTERED_Y)
					y -= 0.5f * v_dim.y;
			}

			font->DrawString(x, y, str, true, ctx);
			return v_dim;
		}

		Math::Vec2 DrawString(float x, float y, float fontSz, int color, Enums::TextFlags flags, const wchar_t* strText, ...) {
			STextDrawContext ctx;
			ctx.m_sizeIn800x600 = false;
			ctx.m_colorOverride = color;
			ctx.m_size.x = fontSz;
			ctx.m_size.y = fontSz;
			ctx.m_widthScale = 1.0f;

			wchar_t buf[512];
			va_list args;

			va_start(args, strText);
			_vswprintf(buf, strText, args);

			Math::Vec2 v_dim = font->GetTextSizeW(strText, true, ctx);
			if (flags & (Enums::TextFlags::TEXT_RIGHT | Enums::TextFlags::TEXT_CENTERED))
			{
				if (flags & Enums::TextFlags::TEXT_RIGHT)
					x -= v_dim.x;
				else if (flags & Enums::TextFlags::TEXT_CENTERED_X)
					x -= 0.5f * v_dim.x;
				if (flags & Enums::TextFlags::TEXT_CENTERED_Y)
					y -= 0.5f * v_dim.y;
			}

			font->DrawStringW(x, y, ctx.m_widthScale, buf, true, ctx);
			va_end(args);

			return v_dim;
		}

		Math::Vec2 GetTextSzW(float fontSz, const wchar_t* str, bool multiline) {
			STextDrawContext ctx;
			ctx.m_sizeIn800x600 = false;
			ctx.m_size.x = fontSz;
			ctx.m_size.y = fontSz;
			ctx.m_widthScale = 1.0;

			return font->GetTextSizeW(str, multiline, ctx);
		}

		Math::Vec2 DrawStringW(float x, float y, float fontSz, int color, Enums::TextFlags flags, const wchar_t* str, ...) {
			STextDrawContext ctx;
			ctx.m_sizeIn800x600 = false;
			ctx.m_size.x = fontSz;
			ctx.m_size.y = fontSz;
			ctx.m_colorOverride = color;
			ctx.m_widthScale = 1.0;

			Math::Vec2 v_dim = font->GetTextSizeW(str, true, ctx);
			if (flags & (Enums::TextFlags::TEXT_RIGHT | Enums::TextFlags::TEXT_CENTERED))
			{
				if (flags & Enums::TextFlags::TEXT_RIGHT)
					x -= v_dim.x;
				else if (flags & Enums::TextFlags::TEXT_CENTERED_X)
					x -= 0.5f * v_dim.x;
				if (flags & Enums::TextFlags::TEXT_CENTERED_Y)
					y -= 0.5f * v_dim.y;
			}

			font->DrawStringW(x, y, 1.f, str, true, ctx);
			return v_dim;
		}

	};
	class ICryFont
	{
	public:
		virtual ~ICryFont() {}
		virtual void Release() = 0;
		virtual IFFont* NewFont(char* pFontName) = 0;
		virtual IFFont* GetIFFont(const char* pFontName = xc("warface")) const = 0;
		virtual void SetRendererProperties(IRenderer* pRenderer) = 0;
	};
	class CUIDraw
	{
	public:
		virtual void   Function0() = 0;
		virtual void   Function1() = 0;

		virtual void   PreRender() = 0;
		virtual void   PostRender() = 0;
		virtual uint32 GetColorARGB(uint8 ucAlpha, uint8 ucRed, uint8 ucGreen, uint8 ucBlue) = 0;
		virtual int    CreateTexture(const char* strName, bool dontRelease = true) = 0;
		virtual bool   DeleteTexture(int iTextureID) = 0;
		virtual void   GetTextureSize(int iTextureID, float& rfSizeX, float& rfSizeY) = 0;
		virtual void   DrawTriangle(float fX0, float fY0, float fX1, float fY1, float fX2, float fY2, uint32 uiColor) = 0;
		virtual void   DrawLine(float fX1, float fY1, float fX2, float fY2, uint32 uiDiffuse) = 0;
		virtual void   ui_draw_box(float fX, float fY, float fSizeX, float fSizeY, uint32 uiDiffuse, int iTextureID = 0) = 0;
		virtual void   DrawQuad(float fX, float fY, float fSizeX, float fSizeY, uint32 uiDiffuse = 0, uint32 uiDiffuseTL = 0, uint32 uiDiffuseTR = 0, uint32 uiDiffuseDL = 0, uint32 uiDiffuseDR = 0, int iTextureID = -1, float fUTexCoordsTL = 0.0, float fVTexCoordsTL = 0.0, float fUTexCoordsTR = 1.0, float fVTexCoordsTR = 0.0, float fUTexCoordsDL = 0.0, float fVTexCoordsDL = 1.0, float fUTexCoordsDR = 1.0, float fVTexCoordsDR = 1.0, bool bUse169 = true) = 0;
		virtual void   DrawImage(int iTextureID, float fX, float fY, float fSizeX, float fSizeY, float fAngleInDegrees, float fRed, float fGreen, float fBlue, float fAlpha, float fS0 = 0.0, float fT0 = 0.0, float fS1 = 1.0, float fT1 = 1.0) = 0;
		virtual void   DrawImageCentered(int iTextureID, float fX, float fY, float fSizeX, float fSizeY, float fAngleInDegrees, float fRed, float fGreen, float fBlue, float fAlpha) = 0;
		virtual void   DrawTextSimple(IFFont* pFont, float fX, float fY, float fSizeX, float fSizeY, const char* strText, Math::Color color, Enums::EUIDRAWHORIZONTAL eUIDrawHorizontal, Enums::EUIDRAWVERTICAL eUIDrawVertical) = 0;
		virtual void   DrawText_(IFFont* pFont, float fX, float fY, float fSizeX, float fSizeY, const char* strText, float fAlpha, float fRed, float fGreen, float fBlue, Enums::EUIDRAWHORIZONTAL eUIDrawHorizontalDocking, Enums::EUIDRAWVERTICAL eUIDrawVerticalDocking, Enums::EUIDRAWHORIZONTAL eUIDrawHorizontal, Enums::EUIDRAWVERTICAL eUIDrawVertical) = 0;
		virtual void   DrawWrappedText(IFFont* pFont, float fX, float fY, float fMaxWidth, float fSizeX, float fSizeY, const char* strText, float fAlpha, float fRed, float fGreen, float fBlue, Enums::EUIDRAWHORIZONTAL eUIDrawHorizontalDocking, Enums::EUIDRAWVERTICAL eUIDrawVerticalDocking, Enums::EUIDRAWHORIZONTAL eUIDrawHorizontal, Enums::EUIDRAWVERTICAL eUIDrawVertical) = 0;
		virtual void   GetTextDim(IFFont* pFont, float* fWidth, float* fHeight, float fSizeX, float fSizeY, const char* strText) = 0;
		virtual void   GetWrappedTextDim(IFFont* pFont, float* fWidth, float* fHeight, float fMaxWidth, float fSizeX, float fSizeY, const char* strText) = 0;

		void ui_draw_border(int x, int y, int w, int h, int s, Math::ReversedColor color) {
			ui_draw_box(x, y, s, h, color);
			ui_draw_box(x, y + h, w, s, color);
			ui_draw_box(x, y, w, s, color);
			ui_draw_box(x + w, y, s, h + s, color);
		}

		void DrawCircle(float x, float y, float r, int cLine, float resolution)
		{
			float PointX = 0.f;
			float PointY = 0.f;

			for (int i = 0; i <= resolution; ++i)
			{
				float X = x + r * f_cosf(2 * 3.14159265358979323846264 * i / resolution);
				float Y = y - r * f_sinf(2 * 3.14159265358979323846264 * i / resolution);
				if (i > 0) DrawLine(X, Y, PointX, PointY, cLine);
				PointX = X; PointY = Y;
			}
		}
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
		bool GetKeyState(bool async)
		{
			if (state == Enums::EInputState::eIS_Down)
			{
				if (async) state = Enums::EInputState::eIS_Changed;
				return true;
			}
			return false;
		}
		Enums::EInputState GetKeyState() {
			return state;
		}
		Enums::EKeyId			keyId;
		TKeyName		name;
		unsigned int	devSpecId;
		Enums::EInputState		state;
		const EType		type;
		float			value;
		unsigned int	user;
		Enums::EDeviceId		deviceId;
		unsigned char	deviceIndex;
	};
	struct SInputEvent
	{
		Enums::EDeviceId deviceId;
		Enums::EInputState state;
		wchar_t inputChar;
		TKeyName keyName;
		Enums::EKeyId keyId;
		unsigned int timestamp;
		int modifiers;
		float value;
		SInputSymbol* pSymbol;
		unsigned __int8 deviceIndex;
	};
	class IInputEventListener
	{
	public:
		virtual ~IInputEventListener() {}
		virtual bool OnInputEvent(const SInputEvent* inputEvent) { return false; }
		virtual bool OnInputEventUI(const SInputEvent* inputEvent) { return false; }
		virtual int GetPriority() { return 0; }
	};
	class IInput {
	public:
		void AddEventListener(IInputEventListener* listener) {
			v_spoof(this, 0x8 / 8, listener);
		}
		void RemoveEventListener(IInputEventListener* listener) {
			v_spoof(this, 0x10 / 8, listener);
		}
		SInputSymbol* LookupSymbol(Enums::EDeviceId deviceId, int deviceIndex, Enums::EKeyId keyId)
		{
			return v_spoof<SInputSymbol*>(this, 0xC0 / 8, deviceId, deviceIndex, keyId);
		}
	};
	struct UIKeyState {
	public:
		UIKeyState(IInput* pInput) { this->pInput = pInput; }
		bool GetKeyState(Enums::EKeyId keyId, bool async = true) {
			if (SInputSymbol* pSymbol = this->pInput->LookupSymbol((keyId < Enums::EKeyId::eKI_Mouse1) ? Enums::EDeviceId::eDI_Keyboard : Enums::EDeviceId::eDI_Mouse, 0, keyId))
				return pSymbol->GetKeyState(async);
			return false;
		}
		Enums::EInputState GetRawState(Enums::EKeyId keyId) {
			if (SInputSymbol* pSymbol = this->pInput->LookupSymbol((keyId < Enums::EKeyId::eKI_Mouse1) ? Enums::EDeviceId::eDI_Keyboard : Enums::EDeviceId::eDI_Mouse, 0, keyId))
				return pSymbol->GetKeyState();
			return Enums::EInputState::eIS_Unknown;
		}
	private:
		IInput* pInput;
	};
	struct IHardwareMouseEventListener
	{
		virtual void OnHardwareMouseEvent(int iX, int iY, Enums::EHARDWAREMOUSEEVENT eHardwareMouseEvent, int wheelDelta = 0) = 0;
	};
	struct IHardwareMouse
	{
		virtual ~IHardwareMouse() = 0;
		virtual void Release() = 0;
		virtual void OnPreInitRenderer() = 0;
		virtual void OnPostInitInput() = 0;
		virtual void Event(int iX, int iY, Enums::EHARDWAREMOUSEEVENT eHardwareMouseEvent, int wheelDelta = 0) = 0;
		virtual void AddListener(IHardwareMouseEventListener* pHardwareMouseEventListener) = 0;
		virtual void RemoveListener(IHardwareMouseEventListener* pHardwareMouseEventListener) = 0;
		virtual void SetGameMode(bool bGameMode) = 0;
		virtual void IncrementCounter() = 0;
		virtual void DecrementCounter() = 0;
		virtual void UpdateCursorStatu() = 0;
		virtual bool IsCursorVisible() = 0;
		virtual void GetHardwareMousePosition(float* pfX, float* pfY) = 0;
		virtual void SetHardwareMousePosition(float fX, float fY) = 0;
		virtual void GetHardwareMouseClientPosition(float* pfX, float* pfY) = 0;
		virtual void SetHardwareMouseClientPosition(float fX, float fY) = 0;
		virtual void CaptureMouse() = 0;
		virtual void ReleaseMouse() = 0;
		virtual void Reset(bool bVisibleByDefault) = 0;
		virtual void ConfineCursor(bool confine) = 0;
		virtual void Hide(bool hide) = 0;
		virtual void Render() = 0;
		virtual void UseSystemCursor(bool useSystemCursor) = 0;
	};
	struct UIHardwareMouse {
	public:
		UIHardwareMouse(IHardwareMouse* pHardwareMouse) { this->pHardwareMouse = pHardwareMouse; }
		bool IsAtPosition(float x, float y, float w, float h) {
			float MouseX, MouseY;
			if (this->pHardwareMouse) {
				this->pHardwareMouse->GetHardwareMouseClientPosition(&MouseX, &MouseY);
				return (MouseX >= x && MouseX <= x + w && MouseY >= y && MouseY <= y + h);
			}
			return false;
		}
		Math::Vec2 GetMousePosition() {
			float x = 0.f, y = 0.f;
			if (this->pHardwareMouse) {
				pHardwareMouse->GetHardwareMouseClientPosition(&x, &y);
			}
			return { x, y };
		}
	private:
		IHardwareMouse* pHardwareMouse;
	};
	struct IEntityClass {
	public:
		const char* GetName() {
			return v_spoof<const char*>(this, 0x10 / 8);
			//return GetVFunc<const char* (__fastcall*)(PVOID64)>(this, 0x10)(this); 
		}
	};
	struct ISkeletonPose
	{
	public:
		unsigned int GetJointCount() {
			return v_spoof<unsigned int>(this, 0x10 / 8);
		}
		QuatT& GetAbsJointByID(int nJointID) {
			return v_spoof<QuatT&>(this, 0x38 / 8, nJointID);
			//return GetVFunc<QuatT& (__thiscall*)(PVOID, int)>(this, 0x38)(this, nJointID); 
		}
		int16 GetJointIdByName(const char* sz_joint_name) {
			return v_spoof<int16>(this, 0x18 / 8, sz_joint_name);
			//return GetVFunc<int16(__fastcall*)(PVOID64, const char*)>(this, 0x18)(this, sz_joint_name); 
		}
		const char* GetszNameByJointId(int16 sz_joint_name) {
			return v_spoof<const char*>(this, 0x30 / 8, sz_joint_name);
			//return GetVFunc<const char* (__fastcall*)(PVOID64, int16)>(this, 0x30)(this, sz_joint_name); 
		}
	};
	struct ICharacterInstance
	{
	public:
		ISkeletonPose* GetISkeletonPose() {
			return v_spoof<ISkeletonPose*>(this, 0x28 / 8);
			//return GetVFunc<ISkeletonPose* (__thiscall*)(PVOID)>(this, 0x28)(this); 
		}
	};
	struct IEntity {
	public:
		EntityId GetEntityId() {
			return v_spoof<EntityId>(this, 0x8 / 8);
			//return GetVFunc<EntityId(__thiscall*)(PVOID)>(this, 0x8)(this); 
		}
		IEntityClass* GetEntityClass() {
			return v_spoof<IEntityClass*>(this, 0x18 / 8);
			//return GetVFunc<IEntityClass* (__fastcall*)(PVOID64)>(this, 0x18)(this); 
		}
		Matrix34 GetEntityWorldTM() {
			return *(Matrix34*)((uintptr_t)this + 0x40);
		}
		Vec3& GetPos() {
			return v_spoof<Vec3&>(this, 0xE0 / 8);
			//return GetVFunc<Vec3& (__thiscall*)(PVOID)>(this, 0xE0)(this); 
		}
		bool IsHidden() {
			return v_spoof<bool>(this, 0x178 / 8);
			//return GetVFunc<bool(__fastcall*)(PVOID64)>(this, 0x178)(this); 
		}
		void GetWorldBounds(AABB& bbox) {
			v_spoof(this, 0xC8 / 8, bbox);
			//GetVFunc<void(__thiscall*)(PVOID, AABB&)>(this, 0xC8)(this, bbox); 
		}
		const char* GetName() {
			return v_spoof<const char*>(this, 0x60 / 8);
			//return GetVFunc<const char* (__thiscall*)(PVOID)>(this, 0x60)(this); 
		}
		ICharacterInstance* GetCharacter(int nSlot) {
			return v_spoof<ICharacterInstance*>(this, 0x298 / 8, nSlot);
			//return GetVFunc<ICharacterInstance* (__thiscall*)(PVOID, int)>(this, 0x298)(this, nSlot); 
		}
		Vec3 GetBonePos(ISkeletonPose* pLocalSkeleton, int eBone)
		{
			Matrix34 World = GetEntityWorldTM();
			Matrix34 SkeletonAbs = Matrix34(pLocalSkeleton->GetAbsJointByID(eBone));
			Matrix34 matWorld = World;

			float m03, m13, m23;
			m03 = (World.m00 * SkeletonAbs.m03) + (World.m01 * SkeletonAbs.m13) + (World.m02 * SkeletonAbs.m23) + World.m03;
			matWorld.m03 = m03;
			m13 = (World.m10 * SkeletonAbs.m03) + (World.m11 * SkeletonAbs.m13) + (World.m12 * SkeletonAbs.m23) + World.m13;
			matWorld.m13 = m13;
			m23 = (World.m20 * SkeletonAbs.m03) + (World.m21 * SkeletonAbs.m13) + (World.m22 * SkeletonAbs.m23) + World.m23;
			matWorld.m23 = m23;

			return matWorld.GetTranslation();
		}
	};
	class IWeaponParameters
	{
	public:

		bool GetValue(EGameStatType id, f32* value)
		{
			auto v0 = *(uint64_t*)(encrypted_data_entry((int16_t)id) + 0x20);
			auto v1 = *(uint32_t*)(encrypted_data_entry((int16_t)id) + 0x24);
			*(uint32_t*)value = *(uint32_t*)&v0 ^ v1;
			return value;
		}

		void SetValue(EGameStatType id, f32 value)
		{
			*(uint32_t*)(encrypted_data_entry((int16_t)id) + 0x20) = *(uint32_t*)&value ^ *(uint32_t*)(encrypted_data_entry((int16_t)id) + 0x24);
		}

	private:
		uint64_t encrypted_data_entry(int16_t id)
		{
			uint64_t result;
			uint64_t v3 = *(uint64_t*)((uintptr_t)this + 0x68);
			uint64_t v5 = *(uint64_t*)(v3 + 0x8);

			while (!(*(BYTE*)(v5 + 0x19)))
			{
				int16_t entity_id = *(int16_t*)(v5 + 0x1C);
				if (entity_id == id)
					break;
				else
					v5 = *(uint64_t*)(entity_id < id ? v5 + 0x10 : v5);
			}

			if (*(int16_t*)(v5 + 0x1C) == id)
				result = v5;

			return result;
		}
	};
	class IClipMode
	{
	public:
		virtual ~IClipMode() = 0;
		virtual int GetAmmoCount() = 0;
		virtual void SetAmmoCount(int count) = 0;
		virtual void ExpendAmmo() = 0;
		virtual bool IsEmpty() = 0;
		virtual bool IsBarrel() = 0;
		virtual bool IsRechargeable() = 0;
		virtual bool RunLevelNotification() = 0;
	};
	class IWeaponGeneral {
	public:
		virtual class CWeaponView* GetView(); //
		virtual class CWeaponSettings* GetSettings(); //
		virtual IWeaponParameters* GetParameters(); //
		virtual class CWeaponAttachment* GetAttachment(); //
		virtual class CItemBox* GetItemBox(); //
		virtual EWeaponStates GetCurrState(); //
		virtual char* GetDisplayName(); //
		virtual char* GetStatisticsName(); //
		virtual class CGameObject* GetGameObject(); //
		virtual void SetUnderBarrelWeapon(); //
		virtual unsigned __int64 GetFirstOwner(); //
		virtual void SetFirstOwner(unsigned __int64 profileId); //
	};
	struct IWeapon
	{
	public:
		IWeaponGeneral* GetWeaponGeneral() { return *(IWeaponGeneral**)((uintptr_t)this + 0x8); }
		void SetFiringPos(Vec3 Position) {
			v_spoof(this, 0x2F0 / 8, Position);
			//return GetVFunc<void(__fastcall*)(PVOID, Vec3&)>(this, 0x2F0)(this, Position);
		}
		void StartFire() {
			v_spoof(this, 0x58 / 8);
			//return GetVFunc<void(__thiscall*)(PVOID)>(this, 0x58)(this);
		}
		void StopFire() {
			v_spoof(this, 0x60 / 8);
			//return GetVFunc<void(__thiscall*)(PVOID)>(this, 0x60)(this);
		}
	};
	struct IGameObject;
	struct IItem
	{
		bool m_prefix(const char* pre, const char* str)
		{
			char cp;
			char cs;

			if (!*pre)
				return 1;

			while ((cp = *pre++) && (cs = *str++))
			{
				if (cp != cs)
					return 0;
			}

			if (!cs)
				return 0;

			return 1;
		}
	public:
		IGameObject* GetGameObject() {
			return *(IGameObject**)((uintptr_t)this + 0x18);
		}
		IEntity* GetEntity() { return *(IEntity**)((uintptr_t)this + 0x10); }
		IWeapon* GetWeapon() { return (IWeapon*)((uintptr_t)this + 0x28); }
		bool IsRifle() {
			return m_prefix(xc("ar"), GetEntity()->GetName());
		}
		bool IsSniper() {
			return m_prefix(xc("sr"), GetEntity()->GetName());
		}
		bool IsShotgun() {
			return m_prefix(xc("shg"), GetEntity()->GetName());
		}
		bool IsMicrogun() {
			return m_prefix(xc("smg"), GetEntity()->GetName());
		}
		bool IsPistol() {
			return m_prefix(xc("pt"), GetEntity()->GetName());
		}
		bool IsKnife() {
			return m_prefix(xc("kn"), GetEntity()->GetName());
		}
		bool IsMachineGun() {
			return m_prefix(xc("mg"), GetEntity()->GetName());
		}
		bool IsRocketLauncher() {
			return m_prefix(xc("arl"), GetEntity()->GetName());
		}
		bool IsGun() {
			return IsRifle() || IsSniper() || IsShotgun() || IsMicrogun() || IsPistol() || IsKnife() || IsMachineGun() || IsRocketLauncher();
		}
	};
	struct IAnimationGraphState
	{
	public:
		const char* GetCurrentStateName() {
			return v_spoof<const char*>(this, 0x100 / 8);
		}
	};
	struct CFPPlayer
	{
	public:
		void GetRecoil(bool pTimedemo, Vec3 pRecoil)
		{
			m_timedemo = pTimedemo;
			m_viewAnglesOffset = pRecoil;
		}
		void SetHeight(float Value) { m_viewParams.m_eyeOffsetView.y = Value; }
		Vec3 GetFPWeaponPos() { return m_FPWeaponPos; }
		Vec3 GetSpectatorTargetPos() { return m_viewParams.spectatorTargetPos; }
		Vec3 GetSpectatorCamPos() { return m_viewParams.spectatorCamPos; }
		Quat& GetBaseQuat() { return m_baseQuat; }
	private:
		struct SFPViewParams
		{
		public:
			Vec3 m_eyeOffsetView; //0x0000 
			Vec3 m_bobOffset; //0x000C 
			Vec3 m_FPWeaponLastDirVec; //0x0018 
			float smoothViewZ; //0x0024 
			Vec3 spectatorTargetPos; //0x0028 
			Vec3 spectatorCamPos; //0x0034 
			float spectatorPosZ; //0x0040 
			char pad_0x0044[0x4]; //0x0044
			Vec3 deathCamPlayerPos; //0x0048 
			Vec3 deathCamKillerPrevPos; //0x0054 
			Quat deathCamView; //0x0060 
			Quat deathCamKillView; //0x0070 
			float deathCamKillerFov; //0x0080 
		}; //Size=0x0084
		SFPViewParams m_viewParams; //0x0000 
		Quat m_viewQuat; //0x0084 
		Quat m_viewQuatFinal; //0x0094 
		Quat m_baseQuat; //0x00A4 
		bool m_timedemo; //0x00B4 
		Vec3 m_viewAnglesOffset; //0x00B8 
		Vec3 m_FPWeaponPos; //0x00C4 
		Vec3 m_FPWeaponAngles; //0x00D0 
		bool m_viewBlending; //0x00DC 
	};
	struct IActor {
	public:
		IAnimationGraphState* GetAnimationGraphState() {
			return v_spoof<IAnimationGraphState*>(this, 0x128 / 8);
		}
		CFPPlayer* GetPlayer() { return *(CFPPlayer**)((uintptr_t)this + 0xD10); }
		IEntity* GetEntity() { return *(IEntity**)((uintptr_t)this + 0x10); }
		EntityId GetEntityId() { return *(EntityId*)((uintptr_t)this + 0x20); }
		bool GetBonePos(Vec3_tpl<float>* pos, Enums::EBonesID ID, int slot, int* pBoneIndex) {
			return v_spoof<bool>(this, 158, pos, ID, slot, pBoneIndex);
		}
		std::tuple< int, Vec3_tpl<float> > GetBonePosition(Enums::EBonesID id) {

			int index;
			Vec3 position;

			if (this->GetBonePos(&position, id, 0, &index)) {

				auto current = GetEntity()->GetPos();
				auto output = current + position;

				return { index,  output };
			}
			else {
				return { -1, Vec3_tpl<float>(0, 0, 0) };
			}
		}
		int GetHealth() {
			return v_spoof<int>(this, 0xE0 / 8);
			//return GetVFunc<int(__thiscall*)(PVOID)>(this, 0xE0)(this); 
		}
		bool IsDead() {
			return GetHealth() <= 0;
		}
		IItem* GetCurrentItem() {
			return v_spoof<IItem*>(this, 0x1D0 / 8);
			//return GetVFunc<IItem* (__thiscall*)(PVOID, bool)>(this, 0x1D0)(this, includeVehicle); 
		}
		unsigned int LookingAtEntityId()
		{
			uintptr_t i = *(uintptr_t*)(uintptr_t(this + 0x18));
			if (!i) return 0;
			uintptr_t i_1 = *(uintptr_t*)(uintptr_t(i + 0x68));
			if (!i_1) return 0;
			uintptr_t i_2 = *(uintptr_t*)(uintptr_t(i_1 + 0x20));
			if (!i_2) return 0;
			return  *(unsigned int*)(uintptr_t(i_2 + 0x170));
		}
		uint32_t GetTeamId()
		{
			return *(uint32_t*)((uintptr_t)this + 0x3E0);
		}
		int8 GetHITT() {
			return *(int8*)(this + 0xCE4);
		}
	};
	struct IActorSystem
	{
	public:
		IActor* GetActor(int entityId) {
			return v_spoof<IActor*>(this, 0x78 / 8, entityId);
			//return GetVFunc<IActor* (__thiscall*)(PVOID, int)>(this, 0x78)(this, entityId); 
		}
	};
	struct IEntityIt {
	public:
		void Release() {
			v_spoof(this, 0x10 / 8);
			//GetVFunc<void(__thiscall*)(PVOID)>(this, 0x10)(this); 
		}
		IEntity* Next() {
			return v_spoof<IEntity*>(this, 0x30 / 8);
			//return GetVFunc<IEntity* (__fastcall*)(PVOID)>(this, 0x30)(this); 
		}
	};
	struct IPhysicalEntity
	{
	public:
		void* GetForeignData(int itype = 0) {
			return v_spoof<void*>(this, 0x68 / 8, itype);
			//return GetVFunc<void* (__thiscall*)(PVOID, int)>(this, 0x68)(this, itype); 
		}
	};
	struct IEntitySystem {
	public:
		IEntity* GetEntityFromPhysics(IPhysicalEntity* pPhysEntity) {
			return v_spoof<IEntity*>(this, 0xD0 / 8, pPhysEntity);
			//return GetVFunc<IEntity* (__thiscall*)(PVOID, IPhysicalEntity*)>(this, 0xD0)(this, pPhysEntity); 
		}
		IEntityIt* GetEntityIterator() {
			return v_spoof<IEntityIt*>(this, 0xA8 / 8);
			//return GetVFunc<IEntityIt* (__thiscall*)(PVOID)>(this, 0xA8)(this); 
		}
	};
	struct SFeedbackEventParams {
		virtual void Function0() {};
		virtual void Function1() {};
		virtual void Function2() {};
		virtual void Function3() {};
		virtual void Function4() {};
	};
	struct SMarkerParams : SFeedbackEventParams {
		EntityId m_entity;
		Vec3 m_pos;
		SMarkerParams(EntityId eid, Vec3 pos) {
			m_entity = eid;
			m_pos = pos;
		}
	};
	struct SMarker {
		int Id;
		int HUDIconID;
		int RaceIconID;
		int RadialHUDIconID;
		int MinimapIconID;
		int HUDSilhouetteID;
		int DistanceLabelID;
		int HUDTextLabelID;
		int HUDStatusInfoID;
		class CParticleMarker* particle;
		int HUDCountdownTimerID;
		int RadarIconID;
		int HUDBadgeID;
		bool TutorialHint;

		struct SDynamicMarkerParams {
			float intensity;
			unsigned int time;
			char healthPercent;
			char armorPercent;
			char ammoPercent;
			float progress;
		}; //Size=0x10;
		SDynamicMarkerParams params;
	}; //Size=0x50
	struct CFeedbackSystem {
		//int64 AddMarker(const char* name, const SMarkerParams* params) {
		//	return spoof_call<int64>((PVOID)dwCFeedBackAddMarker, name, params);
		//	//return GetVFunc<int(__fastcall*)(PVOID64, const char*, const SMarkerParams*)>(dwCFeedBackAddMarker)(this, name, params); 
		//}
		//void RemoveMarker(int id) {
		//	spoof_call<int>((PVOID)dwCFeedBackRemoveMarker, id);
		//	//GetVFunc<int(__fastcall*)(PVOID64, int)>(dwCFeedBackRemoveMarker)(this, id); 
		//}
	};
	struct INetChannel;
	struct IGameRules {
	public:
		//int SiftingOutMyTeam(EntityId mentityId, EntityId pentityId) {
		//	return spoof_call<int64>((PVOID)dwIsSameTeam, mentityId, pentityId);
		//	//return GetVFunc<int(__thiscall*)(PVOID, EntityId, EntityId)>(dwIsSameTeam)(this, mentityId, pentityId);
		//}
		//CFeedbackSystem* GetFeedbackSystem() { return m_FeedbackSystem; }
	private:
		/*char pad_0x0000[0x308];
		CFeedbackSystem* m_FeedbackSystem;*/
	};
	struct IGameFrameworkListener
	{
		virtual ~IGameFrameworkListener() {};
		virtual void OnPostUpdate(float fDeltaTime) {};
		virtual void OnSaveGame(struct ISaveGame* pSaveGame) {};
		virtual void OnLoadGame(struct ILoadGame* pLoadGame) {};
		virtual void OnLevelEnd(const char* nextLevel) {};
		virtual void OnActionEvent(struct SActionEvent& event) {};
		virtual void OnPreRender() {};
	};
	struct IGameFramework {
	public:
		CUIDraw* GetIUIDraw() { return v_spoof<CUIDraw*>(this, 0xB0 / 8); }
		IGameRules* GetIGameRules() {
			return v_spoof<IGameRules*>(this, 0x448 / 8);
			//return GetVFunc<IGameRules* (__fastcall*)(PVOID)>(this, 0x448)(this); 
		}
		IActorSystem* GetIActorSystem() {
			return v_spoof<IActorSystem*>(this, 0xC8 / 8);
			//return GetVFunc<IActorSystem* (__fastcall*)(PVOID)>(this, 0xC8)(this); 
		}
		IActor* GetLocalActor()
		{
			IActor* pLocalActor = 0;
			//bool bGetActorResult = GetVFunc<bool(__fastcall*)(PVOID, IActor**)>(this, 0x470)(this, &pLocalActor);
			bool bGetActorResult = v_spoof<bool>(this, 0x470 / 8, &pLocalActor);
			if (!bGetActorResult) pLocalActor = 0;
			return pLocalActor;
		}
		void RegisterListener(IGameFrameworkListener* pGameFrameworkListener, const char* name, Enums::EFRAMEWORKLISTENERPRIORITY eFrameworkListenerPriority)
		{
			v_spoof(this, 0x360 / 8, pGameFrameworkListener, name, eFrameworkListenerPriority);
			//GetVFunc<void(__thiscall*)(PVOID, IGameFrameworkListener*, const char*, EFRAMEWORKLISTENERPRIORITY)>(this, 0x360)(this, pGameFrameworkListener, name, eFrameworkListenerPriority);
		}
		void UnregisterListener(IGameFrameworkListener* pGameFrameworkListener)
		{
			v_spoof(this, 0x368 / 8, pGameFrameworkListener);
			//GetVFunc<void(__thiscall*)(PVOID, IGameFrameworkListener*)>(this, 0x368)(this, pGameFrameworkListener);
		}
		INetChannel* GetClientChannel() {
			return v_spoof<INetChannel*>(this, 0x238 / 8);
		}
	};
	struct SClimbParams { //"Climb" -> open 1st sub_ func under it -> result = sub_14150F0B0(v2, &v6);
		struct SAnimSelectionParams {
			float upperOffset; //0x0030  --default: 0.3f
			float upperOffset2; //0x0034 --default: 1.0f
			float middleOffset; //0x0038 --default: 1.5f
		};

		struct SClimbAnimationsSet {
			struct SAnimParams { //               <<LowerAnim>>            <<MiddleAnim>>             <<UpperAnim>>             <<DoubleAnim>>
				const char* inputId; //0x0000    --default: "climb_lower"  --default: "climb_middle"  --default: "climb_upper"  --default: "climb_double"
				char pad_0x0008[0x8]; //0x0008
				float length; //0x0010           --default: 0.8f           --default: 1.5f            --default: 1.63f          --default: 0.8f
				float duration; //0x0014         --default: 0.9f           --default: 0.63f           --default: 0.53f          --default: 2.f
				float offsetFromTop; //0x0018    --default: 1.2f           --default: 1.2f            --default: 0.9f           --default: 2.f
				float playbackMult; //0x001C     --default: 1.5f           --default: 1.25f           --default: 1.25f          --default: 1.5f
				const char* animName; //0x0020   --default: "lower_climb"  --default: "middle_climb"  --default: "upper_climb"  --default: "climb_double"
			};

			SAnimParams lowerAnim; //0x0040
			char pad_0x0068[0x8]; //0x0068
			SAnimParams middleAnim; //0x0070
			char pad_0x0098[0x8]; //0x0098
			SAnimParams upperAnim; //0x00A0
			char pad_0x00C8[0x8]; //0x00C8
			SAnimParams doubleAnim; //0x00D0
		};

		char pad_0x0000[0x10]; //0x0000
		float distNearClipPlane; //0x0010  --default: 0.f
		uint32 viewID; //0x0014          --default: 3
		float minHelperHeight; //0x0018    --default: 1.2f
		float maxHelperHeight; //0x001C    --default: 2.25f
		float detectZoneLength; //0x0020   --default: 3.5f
		float nearZoneLength; //0x0024     --default: 1.25f
		float lowerAnimStartDist; //0x0028 --default: 0.45f
		float verticalVelocity; //0x002C   --default: 3.4f
		SAnimSelectionParams animSelectionParams; //0x0030
		char pad_0x003C[0x4]; //0x003C
		SClimbAnimationsSet animationsSet; //0x0040
	};
	class CSpecialMovesSettings {
	public:
		SClimbParams* GetClimbParams() { return *(SClimbParams**)((uintptr_t)this + 0x8); }
	};
	class CSpecialMove {
	public:
		CSpecialMovesSettings* GetSettings() { return *(CSpecialMovesSettings**)((uintptr_t)this + 0x8); }
	};
	struct CPlayerStatus {
	public:
		float GetAfkTime() { return m_afkTime; }
		void SetAfkTime(float afktime) { m_afkTime = afktime; }
	private:
		char pad_0x0000[0x10]; //0x0000
		float m_afkTime; //0x0010 
		struct SPlayerStatus
		{
			int value;
			const char* placeToken;
			const char* placeInfoToken;
			const char* modeInfoToken;
			const char* missionInfoToken;
		};
		SPlayerStatus m_playerStatus;
	};
	struct IGame {
	public:
		IGameFramework* GetIGameFramework() {
			return v_spoof<IGameFramework*>(this, 0x78 / 8);
			//return GetVFunc<IGameFramework* (__fastcall*)(PVOID64)>(this, 0x78)(this); 
		}
		CSpecialMove* GetSpecialMove() { return *(CSpecialMove**)((uintptr_t)this + 0x278); }
		CPlayerStatus* GetPlayerStatus() { return *(CPlayerStatus**)((uintptr_t)this + 0x318); }
	};
	struct IPhysicalWorld {
	public:
		struct ray_hit
		{
			ray_hit() { RtlSecureZeroMemory(this, sizeof(*this)); }
			float dist;
			IPhysicalEntity* pCollider;
			int ipart;
			int partid;
			short surface_idx;
			short idmatOrg;
			int foreignIdx;
			int iNode;
			Vec3 pt;
			Vec3 n;
			int bTerrain;
			int iPrim;
			ray_hit* next;
		};
		struct ray_hit_cached : ray_hit
		{
			ray_hit_cached() { pCollider = 0; ipart = 0; }
			ray_hit_cached(const ray_hit& hit)
			{
				pCollider = hit.pCollider; ipart = hit.ipart;
				iNode = hit.iNode;
			}
			ray_hit_cached& operator=(const ray_hit& hit)
			{
				pCollider = hit.pCollider; ipart = hit.ipart;
				iNode = hit.iNode; return *this;
			}
		};
		struct EventPhys
		{
			EventPhys* next;
			int idval;
		};
		struct EventPhysMono : EventPhys
		{
			IPhysicalEntity* pEntity;
			void* pForeignData;
			int iForeignData;
		};
		struct EventPhysRWIResult : EventPhysMono
		{
			int(__fastcall* OnEvent)(EventPhysRWIResult*);
			ray_hit* pHits;
			int nHits;
			int nMaxHits;
			int bHitsFromPool;
		};
		struct SCollisionClass
		{
			uint32 type;
			uint32 ignore;
		};
		struct SRWIParams
		{
			__forceinline SRWIParams() { RtlSecureZeroMemory(this, sizeof(*this)); }
			void* pForeignData;
			int iForeignData;
			int(__fastcall* OnEvent)(EventPhysRWIResult*);
			Vec3 org;
			Vec3 dir;
			int objtypes;
			uint32 flags;
			ray_hit* hits;
			int nMaxHits;
			ray_hit_cached* phitLast;
			int nSkipEnts;
			IPhysicalEntity** pSkipEnts;
			SCollisionClass collclass;
		};

		int RayWorldIntersection(const Vec3& org, const Vec3& dir, int objtypes, unsigned int flags, ray_hit* hits, int nMaxHits, IPhysicalEntity** pSkipEnts = 0, int nSkipEnts = 0, void* pForeignData = 0, int iForeignData = 0, const char* pNameTag = xc("RayWorldIntersection(Game)"), ray_hit_cached* phitLast = 0, int iCaller = 4)
		{
			return v_spoof<int>(this, 0x308 / 8, org, dir, objtypes, flags, hits, nMaxHits, pSkipEnts, nSkipEnts, pForeignData, iForeignData, pNameTag, phitLast, iCaller);
			//return GetVFunc<int(__fastcall*)(PVOID, const Vec3&, const Vec3&, int, unsigned int, ray_hit*, int, IPhysicalEntity**, int, void*, int, const char*, ray_hit_cached*, int)>(this, 0x308)(this, org, dir, objtypes, flags, hits, nMaxHits, pSkipEnts, nSkipEnts, pForeignData, iForeignData, pNameTag, phitLast, iCaller);
		}

		bool isVisible(IEntitySystem* pEntitySystem, IEntity* pEntity, Vec3 shootPos, Vec3 pos, IPhysicalEntity** pSkipEnts = 0, int nSkipEnts = 0, int pierceability = 10) {
			ray_hit rayhit;
			if (this->RayWorldIntersection(shootPos, pos - shootPos, (int)entity_query_flags::ent_static | (int)entity_query_flags::ent_terrain, 0xA0001500 | pierceability, &rayhit, 1, pSkipEnts, nSkipEnts) > 0) {
				return pEntitySystem->GetEntityFromPhysics(rayhit.pCollider) == pEntity;
			}
			return true;
		}

	};
	class IMaterial
	{
	public:
		const char* GetName() {
			return v_spoof<const char*>(this, 0x30 / 8);
			//return GetVFunc<const char* (__fastcall*)(PVOID64)>(this, 0x30)(this); 
		}
	};
	class IMaterialManager
	{
	public:
		IMaterial* LoadMaterial(const char* sMtName, bool bMakelfNotFound = true, bool bNonremovable = false, unsigned long nLoadingFlags = 0)
		{
			return v_spoof<IMaterial*>(this, 0x28 / 8, sMtName, bMakelfNotFound, bNonremovable, nLoadingFlags);
			//return GetVFunc<IMaterial* (__thiscall*)(PVOID, const char*, bool, bool, unsigned long)>(this, 0x28)(this, sMtName, bMakelfNotFound, bNonremovable, nLoadingFlags);
		}
	};
	class I3DEngine
	{
	public:
		void GetPostEffectParam(const char* NameEffect, float Value, bool bForceValue = false)
		{
			v_spoof(this, 0x488 / 8, NameEffect, Value, bForceValue);
			//return GetVFunc<void(__fastcall*)(PVOID, const char*, float, bool)>(this, 0x488)(this, NameEffect, Value, bForceValue);
		}

		IMaterialManager* GetMaterialManager()
		{
			return v_spoof<IMaterialManager*>(this, 0x450 / 8);
			//return GetVFunc<IMaterialManager* (__thiscall*)(PVOID)>(this, 0x450)(this);
		}

		void SetFlashBangEffectParam(float Value) {
			this->GetPostEffectParam(xc("Flashbang_Time"), Value);
			this->GetPostEffectParam(xc("FlashBang_BlindAmount"), Value);
			this->GetPostEffectParam(xc("Flashbang_DifractionAmount"), Value);
			this->GetPostEffectParam(xc("Flashbang_Active"), Value);
			this->GetPostEffectParam(xc("FilterRadialBlurring_Radius"), Value);
			this->GetPostEffectParam(xc("FilterRadialBlurring_Amount"), Value);
		}
	};
	class SSystemGlobalEnvironment
	{
	public:
		IGame* GetIGame() { return *(IGame**)((uintptr_t)this + 0xD0); }
		IRenderer* GetIRenderer() { return *(IRenderer**)((uintptr_t)this + 0x48); }
		IEntitySystem* GetIEntitySystem() { return *(IEntitySystem**)((uintptr_t)this + 0xE0); }
		IPhysicalWorld* GetIPhysicalWorld() { return *(IPhysicalWorld**)((uintptr_t)this + 0x70); }
		IInput* GetIInput() { return *(IInput**)((uintptr_t)this + 0x78); }

		I3DEngine* GetI3DEngine() { return *(I3DEngine**)((uintptr_t)this + 0x100); }
		IHardwareMouse* GetHardwareMouse() { return *(IHardwareMouse**)((uintptr_t)this + 0x140); }
		ICryFont* GetICryFont() { return *(ICryFont**)((uintptr_t)this + 0x30); }
		//ISystem* GetISystem() { return *(ISystem**)((uintptr_t)this + 0xF0); }
	};
}

namespace SDKHelpers {
	bool filter_team(GameSDK::IActor* m_actor, GameSDK::IActor* p_actor)
	{
		return ((m_actor->GetTeamId() != p_actor->GetTeamId() || p_actor->GetTeamId() == 0 || m_actor->GetTeamId() == 0) && (p_actor != m_actor));
	};

	bool W2s(GameSDK::IRenderer* pRenderer, Vec3 in, Vec3& out) {
		return pRenderer->WorldToScreen(in, out);
	}

	bool IsVisibleByLocal(GameSDK::IPhysicalWorld* pPhysicalWorld, GameSDK::IRenderer* pRenderer, GameSDK::IEntitySystem* pEntitySystem, GameSDK::IEntity* pEntity, Vec3 bonePos) {
		return pPhysicalWorld->isVisible(pEntitySystem, pEntity, pRenderer->GetViewCamera(0, 0)->m_Matrix.GetTranslation(), bonePos);
	}

	POINT GetScreenCenter(GameSDK::IRenderer* pRenderer) {
		return POINT{ pRenderer->GetWidth() / 2, pRenderer->GetHeight() / 2 };
	}

	float GetDistance(POINT pt1, POINT pt2)
	{
		return sqrtf((pt2.y - pt1.y) * (pt2.y - pt1.y) + (pt2.x - pt1.x) * (pt2.x - pt1.x));
	}

	bool GetDistanceFromCenter(GameSDK::IRenderer* pRenderer, Vec3 location3d, float& result, POINT* loc2d = NULL) {
		Vec3 bonePos2d;
		if (W2s(pRenderer, location3d, bonePos2d)) {
			result = GetDistance(GetScreenCenter(pRenderer), { (LONG)bonePos2d.x, (LONG)bonePos2d.y });
			if (loc2d) {
				*loc2d = { (LONG)bonePos2d.x, (LONG)bonePos2d.y };
			}
			return true;
		}
		return false;
	}

	bool str_eq(std::string a, std::string b) {
		return a.find(b) == 0;
	}

	bool str_contain(std::string a, std::string b) {
		return a.find(b) != std::string::npos;
	}

	bool IsNear(Vec3 c1, Vec3 c2, float distance)
	{
		float dx = abs(c2.x - c1.x);
		float dy = abs(c2.y - c1.y);
		float dz = abs(c2.z - c1.z);

		if (dx > distance) return 0;
		if (dy > distance) return 0;
		if (dz > distance) return 0;

		return 1;
	}

	Vec3 GetDiffDistance(Vec3 c1, Vec3 c2) {
		return { abs(c2.x - c1.x), abs(c2.y - c1.y), abs(c2.z - c1.z) };
	}

	bool IsNearDiff(Vec3 DiffDistance, float distance) {
		if (DiffDistance.x > distance) return 0;
		if (DiffDistance.y > distance) return 0;
		if (DiffDistance.z > distance) return 0;

		return 1;
	}

	bool IsFiring(GameSDK::IWeaponGeneral* ptr) {
		EWeaponStates state = ptr->GetCurrState();
		return state == EWeaponStates::eWS_Fire
			|| state == EWeaponStates::eWS_FireUnderBarrel
			|| state == EWeaponStates::eWS_ThrowingFire
			|| state == EWeaponStates::eWS_ThrowingFireActivate
			|| state == EWeaponStates::eWS_ZoomedFire
			|| state == EWeaponStates::eWS_ZoomInFire
			|| state == EWeaponStates::eWS_ZoomOutFire
			|| state == EWeaponStates::eWS_DropAmmoPack
			|| state == EWeaponStates::eWS_Resurrect
			|| state == EWeaponStates::eWS_HoldFireUnderBarrel;
	}

	bool IsZooming(GameSDK::IWeaponGeneral* ptr) {
		EWeaponStates state = ptr->GetCurrState();
		return state == EWeaponStates::eWS_IdleZoomed
			|| state == EWeaponStates::eWS_ZoomedFire
			|| state == EWeaponStates::eWS_ZoomIn
			|| state == EWeaponStates::eWS_ZoomOut
			|| state == EWeaponStates::eWS_ZoomInFire
			|| state == EWeaponStates::eWS_ZoomOutFire;
	}
}

namespace UI {
	class UX {
		GameSDK::CUIDraw* drawing = nullptr;
		GameSDK::IRenderer* render = nullptr;
		GameSDK::WrapFont* textFont = nullptr;
		GameSDK::UIHardwareMouse* pMouse = nullptr;
		GameSDK::UIKeyState* pInputKey = nullptr;
		GameSDK::STextDrawContext ctx;

		bool loaded = false;

		GameSDK::Math::Vec2 TitleBarInitialPos = { 50, 50 };
		GameSDK::Math::Vec2 TabsBtnInitialPos = { 60, 75 };
		GameSDK::Math::Vec2 TabContentInitialPos = { 60, 115 };
		GameSDK::Math::Vec2 MenuSize = { 600, 450 };
		GameSDK::Math::Vec2 TabBtnSize = { 80, 22 };

		float ElementsHorizontalSpacing = 60;
		float ElementsVerticalSpacing = 20;

		int Tabs = 0;
		int ElementsColorAlpha = 255;
		int loadIterations = 0;
		int maxLoadIterations = 200;

		GameSDK::Math::Vec2 LastMousePos = { 0.f, 0.f };

		GameSDK::Math::ReversedColor BgColor = { 17, 17, 17 };

		void InterfaceScreenCenterCircle(float radius, int color) {
			float x = (render->GetWidth() / 2.f);
			float y = (render->GetHeight() / 2.f);
			drawing->ui_draw_border(0, 0, 0, 0, 1, GameSDK::Math::ReversedColor(0, 17, 17, 17));
			drawing->DrawCircle(x, y, radius, color, 100);
		}
		void InterfaceBackgroundFrame() {
			drawing->ui_draw_box(0, 0, render->GetWidth() + 1, render->GetHeight() + 1, GameSDK::Math::ReversedColor(50 + 190 * ((loadIterations * 1.f / maxLoadIterations)), BgColor.r, BgColor.g, BgColor.b));
		}
		void InterfaceLoadingScreen() {
			float x = (render->GetWidth() / 2.f);
			float y = (render->GetHeight() / 2.5f);

			textFont->DrawStringW(x, y, 24, GameSDK::Math::ReversedColor(ElementsColorAlpha, 230, 230, 230), GameSDK::Enums::TEXT_CENTERED, xw(L"ЗАГРУЗКА..."));
			loaded = ++loadIterations > maxLoadIterations;

			InterfaceProgressBar(x - 200, y + 30, 400, 25, 0, maxLoadIterations, loadIterations);
		}
		void InterfaceMenuFrame() {
			drawing->ui_draw_box(TitleBarInitialPos.x, TitleBarInitialPos.y, MenuSize.x, MenuSize.y, GameSDK::Math::ReversedColor(ElementsColorAlpha, 17, 17, 17));
			drawing->ui_draw_border(TitleBarInitialPos.x + 1, TitleBarInitialPos.y + 1, MenuSize.x - 5, 51, 3, GameSDK::Math::ReversedColor(ElementsColorAlpha, 38, 38, 38));
			drawing->ui_draw_border(TitleBarInitialPos.x + 1, TitleBarInitialPos.y + 17, MenuSize.x - 5, MenuSize.y - 21, 3, GameSDK::Math::ReversedColor(ElementsColorAlpha, 38, 38, 38));

			drawing->ui_draw_box(TitleBarInitialPos.x + 1, TitleBarInitialPos.y + 1, MenuSize.x - 2, 20, GameSDK::Math::ReversedColor(ElementsColorAlpha, 38, 38, 38));
			drawing->ui_draw_border(TitleBarInitialPos.x + 4, TitleBarInitialPos.y + 20, MenuSize.x - 9, 31, 1, GameSDK::Math::ReversedColor(ElementsColorAlpha, 56, 56, 56));
			drawing->ui_draw_border(TitleBarInitialPos.x + 4, TitleBarInitialPos.y + 54, MenuSize.x - 9, MenuSize.y - 59, 1, GameSDK::Math::ReversedColor(ElementsColorAlpha, 56, 56, 56));

			textFont->DrawStringW(TitleBarInitialPos.x + MenuSize.x / 2, TitleBarInitialPos.y, 16, GameSDK::Math::ReversedColor(ElementsColorAlpha, 230, 230, 230), GameSDK::Enums::TEXT_CENTERED_X, xw(L"satano v1"));

			if (pMouse->IsAtPosition(TitleBarInitialPos.x, TitleBarInitialPos.y, MenuSize.x, 31)) {
				auto rawState = pInputKey->GetRawState(GameSDK::Enums::EKeyId::eKI_Mouse1);
				auto mousePos = pMouse->GetMousePosition();

				Globals::MenuMovement = rawState == GameSDK::Enums::EInputState::eIS_Down;

				if (Globals::MenuMovement) {
					TitleBarInitialPos += GameSDK::Math::Vec2{ mousePos.x - LastMousePos.x, mousePos.y - LastMousePos.y };
					TabsBtnInitialPos += GameSDK::Math::Vec2{ mousePos.x - LastMousePos.x, mousePos.y - LastMousePos.y };
					TabContentInitialPos += GameSDK::Math::Vec2{ mousePos.x - LastMousePos.x, mousePos.y - LastMousePos.y };
				}

				LastMousePos = mousePos;
			}
		}
		void InterfaceProgressBar(float x, float y, float w, float h, int min, int max, int val) {
			drawing->ui_draw_box(x, y, w, h, GameSDK::Math::ReversedColor(ElementsColorAlpha, 63, 63, 63));
			auto coeff = ((val - min) / (max * 1.f));
			drawing->ui_draw_box(x + 1, y + 1, w * coeff - 1, h - 1, GameSDK::Math::ReversedColor(180, 119, 158, 48));
			textFont->DrawString(x + w / 2, y, 15.f, GameSDK::Math::ReversedColor(ElementsColorAlpha, 230, 230, 230), GameSDK::Enums::TEXT_CENTERED, L"%.1f%%", coeff * 100);
		}
		void InterfaceSliderInt(float x, float y, float w, int min, int max, int& pValue, const wchar_t* format) {
			auto CursorPos = pMouse->GetMousePosition();
			auto rawState = pInputKey->GetRawState(GameSDK::Enums::EKeyId::eKI_Mouse1);
			drawing->ui_draw_box(x, y, w, 20, GameSDK::Math::ReversedColor(ElementsColorAlpha, 63, 63, 63));
			if ((CursorPos.x >= x && CursorPos.x <= x + w && CursorPos.y >= y - 5 && CursorPos.y <= y + 19))
			{
				if (rawState == GameSDK::Enums::EInputState::eIS_Down) {
					auto h = w / max;
					pValue = (CursorPos.x - x) / h;
				}
			}
			if (pValue > max) pValue = max;
			if (pValue < min) pValue = min;
			float px = (pValue - min) / ((max - min) * 1.f);
			drawing->ui_draw_box(x, y, w * px, 20, GameSDK::Math::ReversedColor(ElementsColorAlpha, 119, 158, 48));
			textFont->DrawString(x + w / 2, y, 15.f, GameSDK::Math::ReversedColor(ElementsColorAlpha, 230, 230, 230), GameSDK::Enums::TEXT_CENTERED_X, format, pValue);
		}
		void InterfaceCheckbox(bool* Fun, const wchar_t* NameFun, float xPos, float yPos) {
			float Scale = 10;
			ctx.m_sizeIn800x600 = false;
			ctx.m_size.x = 16;
			ctx.m_size.y = 16;
			ctx.m_widthScale = 1.0;
			GameSDK::Math::Vec2 TextSize(textFont->font->GetTextSizeW(NameFun, 0, ctx));
			if (pMouse->IsAtPosition(xPos - 1, yPos - 1, Scale + TextSize.x + 15, Scale - 1) && pInputKey->GetKeyState(GameSDK::Enums::EKeyId::eKI_Mouse1)) {
				*Fun = !*Fun;
			}
			if (*Fun) {
				drawing->ui_draw_box(xPos, yPos, Scale, Scale, GameSDK::Math::ReversedColor(ElementsColorAlpha, 119, 158, 48));
				drawing->ui_draw_border(xPos + 1, yPos + 1, Scale - 3, Scale - 3, 1, GameSDK::Math::ReversedColor(ElementsColorAlpha, 17, 17, 17));
				textFont->DrawStringW(xPos + 20, yPos - Scale / 2 + 1, 16, GameSDK::Math::ReversedColor(ElementsColorAlpha, 230, 230, 230), GameSDK::Enums::TEXT_LEFT, NameFun);
			}
			else {
				drawing->ui_draw_box(xPos, yPos, Scale, Scale, GameSDK::Math::ReversedColor(ElementsColorAlpha, 63, 63, 63));
				textFont->DrawStringW(xPos + 20, yPos - Scale / 2 + 1, 16, GameSDK::Math::ReversedColor(ElementsColorAlpha, 150, 150, 150), GameSDK::Enums::TEXT_LEFT, NameFun);
			}
		}
		void InterfaceButton(const wchar_t* Name, int Active, float xPos, float yPos, float SizeX, float SizeY) {
			if (pMouse->IsAtPosition(xPos, yPos, SizeX, SizeY)) {
				drawing->ui_draw_box(xPos, yPos, SizeX, SizeY, GameSDK::Math::ReversedColor(ElementsColorAlpha, 45, 45, 45));
				if (pInputKey->GetKeyState(GameSDK::Enums::EKeyId::eKI_Mouse1)) {
					Tabs = Active;
				}
			}
			if (Tabs == Active) {
				drawing->ui_draw_box(xPos, yPos, SizeX, SizeY, GameSDK::Math::ReversedColor(ElementsColorAlpha, 38, 38, 38));
				drawing->ui_draw_border(xPos + 1, yPos + 1, SizeX - 3, SizeY - 3, 1, GameSDK::Math::ReversedColor(ElementsColorAlpha, 56, 56, 56));
			}
			else {
				drawing->ui_draw_box(xPos, yPos, SizeX, SizeY, GameSDK::Math::ReversedColor(ElementsColorAlpha, 32, 32, 32));
			}
			textFont->DrawStringW(xPos + SizeX / 2, yPos, 17, GameSDK::Math::ReversedColor(ElementsColorAlpha, 230, 230, 230), GameSDK::Enums::TEXT_CENTERED_X, Name);
		}
		void InterfaceWeaponTab() {
			InterfaceCheckbox(&Globals::pRecoil, xw(L"Убрать отдачу"), TabContentInitialPos.x, TabContentInitialPos.y);
			InterfaceCheckbox(&Globals::pSpread, xw(L"Убрать разброс"), TabContentInitialPos.x, TabContentInitialPos.y + ElementsVerticalSpacing * 2);
			InterfaceCheckbox(&Globals::pNoSway, xw(L"Убрать покачивание"), TabContentInitialPos.x, TabContentInitialPos.y + ElementsVerticalSpacing * 3);
			InterfaceCheckbox(&Globals::pChangeWeapons, xw(L"Быстрая смена оружий"), TabContentInitialPos.x, TabContentInitialPos.y + ElementsVerticalSpacing * 4);
		}
		void InterfaceAimbotTab() {
			InterfaceCheckbox(&Globals::pSilentAim, xw(L"Сайлент аим"), TabContentInitialPos.x, TabContentInitialPos.y);
			InterfaceSliderInt(TabContentInitialPos.x, TabContentInitialPos.y + ElementsVerticalSpacing, 400, 0, 300, Globals::fSilentRadius, xw(L"радиус: %d"));
			//InterfaceSelectBox(xw(L"Кость"), TabContentInitialPos.x, TabContentInitialPos.y + ElementsVerticalSpacing * 2.5, 353, Globals::iSilentPart, std::vector<const wchar_t*>{ L"Ближайшая", L"Голова", L"Грудь" }, 3);
			InterfaceSliderInt(TabContentInitialPos.x, TabContentInitialPos.y + ElementsVerticalSpacing * 4, 400, 0, 255, Globals::iSilentFovR, xw(L"цвет круга R: %d"));
			InterfaceSliderInt(TabContentInitialPos.x, TabContentInitialPos.y + ElementsVerticalSpacing * 5.2, 400, 0, 255, Globals::iSilentFovG, xw(L"цвет круга G: %d"));
			InterfaceSliderInt(TabContentInitialPos.x, TabContentInitialPos.y + ElementsVerticalSpacing * 6.4, 400, 0, 255, Globals::iSilentFovB, xw(L"цвет круга B: %d"));
		}
		void InterfaceVisualsTab() {
			InterfaceCheckbox(&Globals::SilhouetteEnemy, xw(L"Силуэт противника"), TabContentInitialPos.x, TabContentInitialPos.y);
			InterfaceCheckbox(&Globals::SilhouetteWeapon, xw(L"Силуэт оружия"), TabContentInitialPos.x, TabContentInitialPos.y + ElementsVerticalSpacing);
			InterfaceCheckbox(&Globals::Skeleton, xw(L"Скелет противника"), TabContentInitialPos.x, TabContentInitialPos.y + ElementsVerticalSpacing * 2);
			InterfaceSliderInt(TabContentInitialPos.x, TabContentInitialPos.y + ElementsVerticalSpacing * 3, 400, 0, 255, Globals::iVisibleVisualR, xw(L"цвет видимого силуэта R: %d"));
			InterfaceSliderInt(TabContentInitialPos.x, TabContentInitialPos.y + ElementsVerticalSpacing * 4.2, 400, 0, 255, Globals::iVisibleVisualG, xw(L"цвет видимого силуэта G: %d"));
			InterfaceSliderInt(TabContentInitialPos.x, TabContentInitialPos.y + ElementsVerticalSpacing * 5.4, 400, 0, 255, Globals::iVisibleVisualB, xw(L"цвет видимого силуэта B: %d"));
			InterfaceSliderInt(TabContentInitialPos.x, TabContentInitialPos.y + ElementsVerticalSpacing * 7.6, 400, 0, 255, Globals::iInvisibleVisualR, xw(L"цвет невидимого силуэта R: %d"));
			InterfaceSliderInt(TabContentInitialPos.x, TabContentInitialPos.y + ElementsVerticalSpacing * 8.8, 400, 0, 255, Globals::iInvisibleVisualG, xw(L"цвет невидимого силуэта G: %d"));
			InterfaceSliderInt(TabContentInitialPos.x, TabContentInitialPos.y + ElementsVerticalSpacing * 10, 400, 0, 255, Globals::iInvisibleVisualB, xw(L"цвет невидимого силуэта B: %d"));
		}
		void InterfaceDrawing() {
			InterfaceBackgroundFrame();

			if (!loaded) {
				InterfaceLoadingScreen();
				return;
			}

			InterfaceMenuFrame();

			InterfaceButton(xw(L"Оружие"), 0, TabsBtnInitialPos.x, TabsBtnInitialPos.y, TabBtnSize.x, TabBtnSize.y);
			InterfaceButton(xw(L"Аим"), 1, TabsBtnInitialPos.x + TabBtnSize.x + 2, TabsBtnInitialPos.y, TabBtnSize.x, TabBtnSize.y);
			InterfaceButton(xw(L"Визуалы"), 2, TabsBtnInitialPos.x + TabBtnSize.x * 2 + 4, TabsBtnInitialPos.y, TabBtnSize.x, TabBtnSize.y);
			//InterfaceButton(xw(L"Игрок"), 3, TabsBtnInitialPos.x + TabBtnSize.x * 3 + 6, TabsBtnInitialPos.y, TabBtnSize.x, TabBtnSize.y);
			//InterfaceButton(xw(L"Прочее"), 4, TabsBtnInitialPos.x + TabBtnSize.x * 4 + 8, TabsBtnInitialPos.y, TabBtnSize.x, TabBtnSize.y);

			if (Tabs == 0) {
				InterfaceWeaponTab();
			}
			if (Tabs == 1) {
				InterfaceAimbotTab();
			}
			if (Tabs == 2) {
				InterfaceVisualsTab();
			}
			if (Tabs == 3) {
				//InterfacePlayerTab();
			}
			if (Tabs == 4) {
				//InterfaceMiscTab();
			}
		}
		void InterfaceColorPicker(float xPos, float yPos, GameSDK::Math::ReversedColor& color, const wchar_t* label) {
			drawing->ui_draw_box(xPos + 1, yPos + 1, 14, 14, color);
			drawing->ui_draw_border(xPos, yPos, 15, 15, 2, GameSDK::Math::ReversedColor(ElementsColorAlpha, 230, 230, 230));
			textFont->DrawStringW(xPos + 20, yPos, 17, GameSDK::Math::ReversedColor(ElementsColorAlpha, 230, 230, 230), GameSDK::Enums::TEXT_LEFT, label);

			auto CursorPos = pMouse->GetMousePosition();
			auto rawState = pInputKey->GetRawState(GameSDK::Enums::EKeyId::eKI_Mouse1);
			if ((CursorPos.x >= xPos + 1 && CursorPos.x <= xPos + 14 && CursorPos.y >= yPos + 1 && CursorPos.y <= yPos + 14)) {
				if (rawState == GameSDK::Enums::EInputState::eIS_Pressed) {
					//показать палитру цветов
				}
				else {
					InterfaceTooltip(L"hex: #133713371337\nrgb: 1337 1337 1337\nfloat: 1337 1337 1337");
				}
			}
		}
		void InterfaceTooltip(const wchar_t* label) {
			auto CursorPos = pMouse->GetMousePosition();
			float xPos = CursorPos.x + 15, yPos = CursorPos.y + 15;
			auto sz = textFont->GetTextSzW(17, label, true);
			drawing->ui_draw_box(xPos + 1, yPos + 1, sz.x - 1, sz.y - 1, GameSDK::Math::ReversedColor(ElementsColorAlpha, 17, 17, 17));
			drawing->ui_draw_border(xPos, yPos, sz.x, sz.y, 2, GameSDK::Math::ReversedColor(ElementsColorAlpha, 230, 230, 230));
			textFont->DrawStringW(xPos + 1, yPos + 1, 17, GameSDK::Math::ReversedColor(ElementsColorAlpha, 230, 230, 230), GameSDK::Enums::TEXT_LEFT, label);
		}
	public:
		UX(GameSDK::CUIDraw* d,
			GameSDK::IRenderer* pRender,
			GameSDK::SSystemGlobalEnvironment* ssge,
			GameSDK::IFFont* f,
			GameSDK::IHardwareMouse* pHardwareMouse,
			GameSDK::IInput* pInput
		) {
			drawing = d;
			render = pRender;
			pInputKey = new GameSDK::UIKeyState(pInput);
			pMouse = new GameSDK::UIHardwareMouse(pHardwareMouse);
			textFont = new GameSDK::WrapFont(f);
		}

		void CallPreRender() {
			drawing->PreRender();
		}

		void CallPostRender() {
			drawing->PostRender();
		}

		void ProcessPlayer(GameSDK::IActor* player) {
			auto pSSGE = *(GameSDK::SSystemGlobalEnvironment**)GameSDK::Locations::dwSystemGlobalEnvironment;
			GameSDK::Math::ReversedColor VisibleColor = GameSDK::Math::ReversedColor(ElementsColorAlpha, Globals::iVisibleVisualR, Globals::iVisibleVisualG, Globals::iVisibleVisualB);
			GameSDK::Math::ReversedColor InvisibleColor = GameSDK::Math::ReversedColor(ElementsColorAlpha, Globals::iInvisibleVisualB, Globals::iInvisibleVisualG, Globals::iInvisibleVisualR);
			auto pEntity = player->GetEntity();
			GameSDK::ICharacterInstance* pCharInstance = pEntity->GetCharacter(0);
			GameSDK::ISkeletonPose* pSkeleton = pCharInstance->GetISkeletonPose();
			CallPostRender();
			if (Globals::Skeleton) {
				for (size_t i = 1; i < pSkeleton->GetJointCount(); i++) {
					Vec3 bonePos, bonePos2D;
					bonePos = pEntity->GetBonePos(pSkeleton, i);
					if (SDKHelpers::W2s(render, bonePos, bonePos2D)) {
						bool visible = SDKHelpers::IsVisibleByLocal(pSSGE->GetIPhysicalWorld(), pSSGE->GetIRenderer(), pSSGE->GetIEntitySystem(), pEntity, bonePos);
						textFont->DrawStringW(bonePos2D.x, bonePos2D.y, 8, visible ? VisibleColor : InvisibleColor, GameSDK::Enums::TextFlags::TEXT_CENTERED, xw(L"*"));
					}
				}
			}
			Vec3 bonePos, bonePos2D;
			bonePos = pSkeleton->GetJointIdByName(xc("Bip01 Head"));
			if (SDKHelpers::W2s(render, bonePos, bonePos2D)) {
				bool visible = SDKHelpers::IsVisibleByLocal(pSSGE->GetIPhysicalWorld(), pSSGE->GetIRenderer(), pSSGE->GetIEntitySystem(), pEntity, bonePos);

				if (Globals::Name) {
					textFont->DrawStringA(bonePos2D.x, bonePos2D.y - 60, 12, visible ? VisibleColor : InvisibleColor, GameSDK::Enums::TextFlags::TEXT_CENTERED, pEntity->GetName());
				}
				if (Globals::HP) {
					textFont->DrawStringW(bonePos2D.x, bonePos2D.y - 40, 12, visible ? VisibleColor : InvisibleColor, GameSDK::Enums::TextFlags::TEXT_CENTERED, xw(L"HP: %d +"), player->GetHealth());
				}
				if (Globals::Weapon) {
					GameSDK::IItem* currItem = player->GetCurrentItem();
					if (is_valid_ptr(currItem)) {
						GameSDK::IWeapon* currWeapon = currItem->GetWeapon();
						if (is_valid_ptr(currWeapon)) {
							GameSDK::IWeaponGeneral* currWeaponGeneral = currWeapon->GetWeaponGeneral();
							if (currWeaponGeneral) {
								textFont->DrawStringA(bonePos2D.x, bonePos2D.y - 20, 12, visible ? VisibleColor : InvisibleColor, GameSDK::Enums::TextFlags::TEXT_CENTERED, currWeaponGeneral->GetDisplayName());
							}
						}
					}
				}
				if (Globals::Snapline) {
					drawing->DrawLine(bonePos2D.x, bonePos2D.y, render->GetWidth() / 2, render->GetHeight() / 2, visible ? VisibleColor : InvisibleColor);
				}

			}
			CallPreRender();
		}

		void Entry() {
			if (Globals::ShowMenu) {
				InterfaceDrawing();
			}
			if (Globals::pSilentAim) {
				InterfaceScreenCenterCircle(Globals::fSilentRadius, GameSDK::Math::ReversedColor(Globals::iSilentFovR, Globals::iSilentFovG, Globals::iSilentFovB));
			}
		}
	};
}
