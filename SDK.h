#pragma once

namespace GameSDK {
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
			//GetVFunc<void(__fastcall*)(PVOID, IInputEventListener*)>(this, 0x8)(this, listener);
		}
		void RemoveEventListener(IInputEventListener* listener) {
			v_spoof(this, 0x10 / 8, listener);
			//GetVFunc<void(__fastcall*)(PVOID, IInputEventListener*)>(this, 0x10)(this, listener);
		}
		SInputSymbol* LookupSymbol(EDeviceId deviceId, int deviceIndex, EKeyId keyId)
		{
			return v_spoof<SInputSymbol*>(this, 0xC0 / 8, deviceId, deviceIndex, keyId);
			//return GetVFunc<SInputSymbol* (__fastcall*)(PVOID64, EDeviceId, int, EKeyId)>(this, 0xC0)(this, deviceId, deviceIndex, keyId);
		}
	};

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
			return *(IDXGISwapChain**)((uintptr_t)this + 0x14D000);
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
		Vec2  m_size;
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
		void SetSize(const Vec2& size) { m_size = size; }
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
		virtual Vec2 GetTextSize(const char* pStr, const bool asciiMultiLine, const STextDrawContext& ctx) = 0;
		virtual Vec2 GetTextSizeW(const wchar_t* pStr, const bool asciiMultiLine, const STextDrawContext& ctx) = 0;
		virtual int GetTextLength(const char* szwMsg, const bool bASCIIMultiLine) = 0;
		virtual int GetTextLengthW(const wchar_t* szwMsg, const bool bASCIIMultiLine) = 0;
	};

	class WrapFont
	{
	public:

		IFFont* font;

		WrapFont(IFFont* f) : font(f) {}

		Vec2 DrawStringA(float x, float y, float fontSz, int color, const char* str, TextFlags flags) {
			STextDrawContext ctx;
			ctx.m_sizeIn800x600 = false;
			ctx.m_size.x = fontSz;
			ctx.m_size.y = fontSz;
			ctx.m_colorOverride = color;
			ctx.m_widthScale = 1.0;

			if (flags & (TextFlags::TEXT_RIGHT | TextFlags::TEXT_CENTERED))
			{
				Vec2 v_dim = font->GetTextSize(str, 0, ctx);
				if (flags & TextFlags::TEXT_RIGHT)
					x -= v_dim.x;
				else if (flags & TextFlags::TEXT_CENTERED_X)
					x -= 0.5f * v_dim.x;
				if (flags & TextFlags::TEXT_CENTERED_Y)
					y -= 0.5f * v_dim.y;
			}

			font->DrawString(x, y, str, true, ctx);

			return ctx.m_size;
		}
		Vec2 DrawStringW(float x, float y, float fontSz, int color, const wchar_t* str, TextFlags flags) {
			STextDrawContext ctx;
			ctx.m_sizeIn800x600 = false;
			ctx.m_size.x = fontSz;
			ctx.m_size.y = fontSz;
			ctx.m_colorOverride = color;
			ctx.m_widthScale = 1.0;

			if (flags & (TextFlags::TEXT_RIGHT | TextFlags::TEXT_CENTERED))
			{
				Vec2 v_dim = font->GetTextSizeW(str, 0, ctx);
				if (flags & TextFlags::TEXT_RIGHT)
					x -= v_dim.x;
				else if (flags & TextFlags::TEXT_CENTERED_X)
					x -= 0.5f * v_dim.x;
				if (flags & TextFlags::TEXT_CENTERED_Y)
					y -= 0.5f * v_dim.y;
			}

			font->DrawStringW(x, y, 1.f, str, true, ctx);

			return ctx.m_size;
		}

	};

	class ICryFont
	{
	public:
		virtual ~ICryFont() {}
		virtual void Release() = 0;
		virtual IFFont* NewFont(char* pFontName) = 0;
		virtual IFFont* GetIFFont(const char* pFontName = xc("overlay")) const = 0;
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
		virtual void   DrawTextSimple(IFFont* pFont, float fX, float fY, float fSizeX, float fSizeY, const char* strText, Color color, EUIDRAWHORIZONTAL eUIDrawHorizontal, EUIDRAWVERTICAL eUIDrawVertical) = 0;
		virtual void   DrawText_(IFFont* pFont, float fX, float fY, float fSizeX, float fSizeY, const char* strText, float fAlpha, float fRed, float fGreen, float fBlue, EUIDRAWHORIZONTAL eUIDrawHorizontalDocking, EUIDRAWVERTICAL eUIDrawVerticalDocking, EUIDRAWHORIZONTAL eUIDrawHorizontal, EUIDRAWVERTICAL eUIDrawVertical) = 0;
		virtual void   DrawWrappedText(IFFont* pFont, float fX, float fY, float fMaxWidth, float fSizeX, float fSizeY, const char* strText, float fAlpha, float fRed, float fGreen, float fBlue, EUIDRAWHORIZONTAL eUIDrawHorizontalDocking, EUIDRAWVERTICAL eUIDrawVerticalDocking, EUIDRAWHORIZONTAL eUIDrawHorizontal, EUIDRAWVERTICAL eUIDrawVertical) = 0;
		virtual void   GetTextDim(IFFont* pFont, float* fWidth, float* fHeight, float fSizeX, float fSizeY, const char* strText) = 0;
		virtual void   GetWrappedTextDim(IFFont* pFont, float* fWidth, float* fHeight, float fMaxWidth, float fSizeX, float fSizeY, const char* strText) = 0;

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
			Matrix34 SkeletonAbs = Matrix34(pLocalSkeleton->GetAbsJointByID((int)eBone));
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

	class CWeaponGeneral
	{
	public:
		IWeaponParameters* GetParameters() { 
			return v_spoof<IWeaponParameters*>(this, 3);
		}
		bool IsFiring() {
			EWeaponStates state = v_spoof<EWeaponStates>(this, 6);
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
		bool IsZooming() {
			uintptr_t state = *(uintptr_t*)((uintptr_t)this + 272);
			return (EWeaponStates)state == EWeaponStates::eWS_IdleZoomed
				|| (EWeaponStates)state == EWeaponStates::eWS_ZoomedFire
				|| (EWeaponStates)state == EWeaponStates::eWS_ZoomIn
				|| (EWeaponStates)state == EWeaponStates::eWS_ZoomOut
				|| (EWeaponStates)state == EWeaponStates::eWS_ZoomInFire
				|| (EWeaponStates)state == EWeaponStates::eWS_ZoomOutFire;
		}
	};

	struct IWeapon
	{
	public:
		CWeaponGeneral* GetWeaponGeneral() { return *(CWeaponGeneral**)((uintptr_t)this + 0x8); }
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

	struct IAnimationGraphState
	{
	public:
		const char* GetCurrentStateName() {
			return v_spoof<const char*>(this, 0x100 / 8);
		}
	};

	struct IActor {
	public:
		IAnimationGraphState* GetAnimationGraphState() {
			return v_spoof<IAnimationGraphState*>(this, 0x128 / 8);
		}
		IEntity* GetEntity() { return *(IEntity**)((uintptr_t)this + 0x10); }
		EntityId GetEntityId() { return *(EntityId*)((uintptr_t)this + 0x20); }
		bool GetBonePos(Vec3_tpl<float>* pos, EBonesID ID, int slot, int* pBoneIndex) {
			return v_spoof<bool>(this, 158, pos, ID, slot, pBoneIndex);
		}
		std::tuple< int, Vec3_tpl<float> > GetBonePosition(EBonesID id) {

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

	enum EFRAMEWORKLISTENERPRIORITY
	{
		FRAMEWORKLISTENERPRIORITY_DEFAULT,
		FRAMEWORKLISTENERPRIORITY_GAME,
		FRAMEWORKLISTENERPRIORITY_HUD,
		FRAMEWORKLISTENERPRIORITY_MENU
	};

	struct IGameFramework {
	public:
		char pad_0x0000[0x530];
		CUIDraw* m_pUIDraw;
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
		void RegisterListener(IGameFrameworkListener* pGameFrameworkListener, const char* name, EFRAMEWORKLISTENERPRIORITY eFrameworkListenerPriority)
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

	struct IGame {
	public:
		IGameFramework* GetIGameFramework() {
			return v_spoof<IGameFramework*>(this, 0x78 / 8);
			//return GetVFunc<IGameFramework* (__fastcall*)(PVOID64)>(this, 0x78)(this); 
		}
		IGameFramework* GetIGameFramework2() {
			return *(IGameFramework**)((uintptr_t)this + 0x48);
		}
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

	struct IHardwareMouseEventListener
	{
		virtual void OnHardwareMouseEvent(int iX, int iY, EHARDWAREMOUSEEVENT eHardwareMouseEvent, int wheelDelta = 0) = 0;
	};

	struct IHardwareMouse
	{
		virtual ~IHardwareMouse() = 0;
		virtual void Release() = 0;
		virtual void OnPreInitRenderer() = 0;
		virtual void OnPostInitInput() = 0;
		virtual void Event(int iX, int iY, EHARDWAREMOUSEEVENT eHardwareMouseEvent, int wheelDelta = 0) = 0;
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

	struct UIKeyState {
	public:
		UIKeyState(IInput* pInput);
		bool GetKeyState(EKeyId keyId, bool async = true);
	private:
		IInput* pInput;
	};

	UIKeyState::UIKeyState(IInput* pInput) { this->pInput = pInput; }
	bool UIKeyState::GetKeyState(EKeyId keyId, bool async) {
		if (SInputSymbol* pSymbol = this->pInput->LookupSymbol((keyId < EKeyId::eKI_Mouse1) ? EDeviceId::eDI_Keyboard : EDeviceId::eDI_Mouse, 0, keyId))
			return pSymbol->GetKeyState(async);
		return false;
	}

	struct UIHardwareMouse {
	public:
		UIHardwareMouse(IHardwareMouse* pHardwareMouse);
		int GetMousePosition(float x, float y, float w, float h);
	private:
		IHardwareMouse* pHardwareMouse;
	};

	UIHardwareMouse::UIHardwareMouse(IHardwareMouse* pHardwareMouse) { this->pHardwareMouse = pHardwareMouse; }
	int UIHardwareMouse::GetMousePosition(float x, float y, float w, float h) {
		float MouseX, MouseY;
		if (this->pHardwareMouse) {
			this->pHardwareMouse->GetHardwareMouseClientPosition(&MouseX, &MouseY);
			return (MouseX >= x && MouseX <= x + w && MouseY >= y && MouseY <= y + h);
		}
	}

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

		/*I3DEngine* GetI3DEngine() { return *(I3DEngine**)((uintptr_t)this + 0x100); }
		IHardwareMouse* GetHardwareMouse() { return *(IHardwareMouse**)((uintptr_t)this + 0x140); }
		ICryFont* GetICryFont() { return *(ICryFont**)((uintptr_t)this + 0x30); }
		ISystem* GetISystem() { return *(ISystem**)((uintptr_t)this + 0xF0); }*/
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
}
