#define _CRT_SECURE_NO_WARNINGS

#include <Windows.h>
#include <winternl.h>
#include <map>
#include <string>

#include "xor/Xor.h"
#include "xor/xor_data.h"
#include "xor/xor_value.h"

#include "Data.h"
#include "spoofcall/spoof_call.hpp"

#include "CRT.h"
#include "Hook.h"
#include "SDK.h"

class SilentAimPayload : public GameSDK::IGameFrameworkListener {
public:
	void OnPreRender() {
		if (!Globals::pSilentAim) return;
		auto pSSGE = *(GameSDK::SSystemGlobalEnvironment**)GameSDK::Locations::dwSystemGlobalEnvironment;
		auto pEntityIterator = pSSGE->GetIEntitySystem()->GetEntityIterator();
		if (!is_valid_ptr(pEntityIterator)) return;
		auto pLocalActor = pSSGE->GetIGame()->GetIGameFramework()->GetLocalActor();
		if (!is_valid_ptr(pLocalActor)) return;
		if (pLocalActor->IsDead()) return;
		auto pRenderer = pSSGE->GetIRenderer();
		if (!is_valid_ptr(pRenderer)) return;
		auto currItem = pLocalActor->GetCurrentItem();
		if (!is_valid_ptr(currItem)) return;
		if (!currItem->IsGun()) return;
		auto currWeapon = currItem->GetWeapon();
		if (!is_valid_ptr(currWeapon)) return;

		DWORD silentMaxDist = 0xFFFFFF;
		Vec3 silentPos;
		currWeapon->SetFiringPos(typeZero::ZERO);

		while (GameSDK::IEntity* pEntity = pEntityIterator->Next()) {

			if (pEntity->IsHidden()) continue;
			if (pEntity->GetEntityId() == pLocalActor->GetEntityId()) continue;

			EntityId eId = pEntity->GetEntityId();

			if (GameSDK::IActor* pActor = pSSGE->GetIGame()->GetIGameFramework()->GetIActorSystem()->GetActor(eId)) {
				if (!pActor) continue;

				if (!SDKHelpers::filter_team(pLocalActor, pActor)) {
					continue;
				}

				if (pActor->IsDead()) {
					continue;
				}

				auto boneInfo = pActor->GetBonePosition(GameSDK::Enums::EBonesID::BONE_HEAD);
				GameSDK::ICharacterInstance* pCharInstance = pEntity->GetCharacter(0);
				GameSDK::ISkeletonPose* pSkeleton = pCharInstance->GetISkeletonPose();
				Vec3 bonePos = pEntity->GetBonePos(pSkeleton, std::get<0>(boneInfo));
				Vec3 bonePos2d;

				bool existsOnScreen = SDKHelpers::W2s(pRenderer, bonePos, bonePos2d);
				if (!existsOnScreen) continue;

				bool visible = SDKHelpers::IsVisibleByLocal(pSSGE->GetIPhysicalWorld(), pRenderer, pSSGE->GetIEntitySystem(), pEntity, bonePos);

				if (visible) {

					auto dist = SDKHelpers::GetDistance(SDKHelpers::GetScreenCenter(pRenderer), { (LONG)bonePos2d.x, (LONG)bonePos2d.y });

					if (dist < silentMaxDist) {
						silentMaxDist = dist;
						silentPos = bonePos;
					}

				}

			}

		}

		if (silentMaxDist <= Globals::fSilentRadius) {

			currWeapon->SetFiringPos(silentPos);

			/*if () {
				currWeapon->StartFire();
				currWeapon->StopFire();
			}*/

		}
	}
};

class WHPayload : public GameSDK::IGameFrameworkListener {
	HUDSilhouettesColor deadColor = HUDSilhouettesColor(0.f, 0.f, 0.f);
	PVOID SetVisionParams(EntityId Entityid, HUDSilhouettesColor color, bool hide = false, bool CheckDistance = false, float Distance = 1000.f)
	{
		return spoof_call<PVOID>((PVOID)GameSDK::Locations::dwCHUDSilhouettes, NULL, Entityid, color, hide, CheckDistance, Distance);
	}
	void DrawOutline(EntityId pEntId, bool dead = false, bool visible = false)
	{
		HUDSilhouettesColor VisibleColor = HUDSilhouettesColor(Globals::iVisibleVisualR / 255.0F, Globals::iVisibleVisualG / 255.0F, Globals::iVisibleVisualB / 255.0F);
		HUDSilhouettesColor InvisibleColor = HUDSilhouettesColor(Globals::iInvisibleVisualR / 255.0F, Globals::iInvisibleVisualG / 255.0F, Globals::iInvisibleVisualB / 255.0F);
		SetVisionParams(pEntId, dead ? deadColor : visible ? VisibleColor : InvisibleColor);
	}
public:
	void OnPreRender() {
		auto pSSGE = *(GameSDK::SSystemGlobalEnvironment**)GameSDK::Locations::dwSystemGlobalEnvironment;
		auto pIEntitySystem = pSSGE->GetIEntitySystem();
		if (!is_valid_ptr(pIEntitySystem)) return;
		auto pEntityIterator = pIEntitySystem->GetEntityIterator();
		if (!is_valid_ptr(pEntityIterator)) return;
		auto pLocalActor = pSSGE->GetIGame()->GetIGameFramework()->GetLocalActor();
		if (!is_valid_ptr(pLocalActor)) return;
		if (pLocalActor->IsDead()) return;
		auto pRenderer = pSSGE->GetIRenderer();
		if (!is_valid_ptr(pRenderer)) return;

		while (GameSDK::IEntity* pEntity = pEntityIterator->Next()) {

			if (pEntity->IsHidden()) continue;
			if (pEntity->GetEntityId() == pLocalActor->GetEntityId()) continue;

			EntityId eId = pEntity->GetEntityId();

			auto pClass = pEntity->GetEntityClass();
			if (pClass && Globals::SilhouetteWeapon) {
				auto pClassName = pClass->GetName();
				if (m_strstr(pClassName, "InventoryPickup") || m_strstr(pClassName, "shop_name") || m_strstr(pClassName, "default_name")) {
					DrawOutline(eId, false);
				}
			}

			if (GameSDK::IActor* pActor = pSSGE->GetIGame()->GetIGameFramework()->GetIActorSystem()->GetActor(eId)) {
				if (!Globals::SilhouetteEnemy) continue;
				if (!pActor) continue;

				if (!SDKHelpers::filter_team(pLocalActor, pActor)) {
					continue;
				}

				if (pActor->IsDead()) {
					DrawOutline(eId, true);
					continue;
				}

				auto boneInfo = pActor->GetBonePosition(GameSDK::Enums::EBonesID::BONE_HEAD);
				int boneId = std::get<0>(boneInfo);
				Vec3 bonePos = std::get<1>(boneInfo);
				Vec3 bonePos2d;

				bool existsOnScreen = SDKHelpers::W2s(pRenderer, bonePos, bonePos2d);
				if (!existsOnScreen) continue;

				bool visible = SDKHelpers::IsVisibleByLocal(pSSGE->GetIPhysicalWorld(), pSSGE->GetIRenderer(), pSSGE->GetIEntitySystem(), pEntity, bonePos);
				DrawOutline(eId, false, visible);

			}

		}
	}
};

class MiscPayload : public GameSDK::IGameFrameworkListener {
public:
	void OnPreRender() {
		auto pSSGE = *(GameSDK::SSystemGlobalEnvironment**)GameSDK::Locations::dwSystemGlobalEnvironment;
		auto pIEntitySystem = pSSGE->GetIEntitySystem();
		if (!is_valid_ptr(pIEntitySystem)) return;
		auto pEntityIterator = pIEntitySystem->GetEntityIterator();
		if (!is_valid_ptr(pEntityIterator)) return;
		auto pLocalActor = pSSGE->GetIGame()->GetIGameFramework()->GetLocalActor();
		if (!is_valid_ptr(pLocalActor)) return;
		auto pIGame = pSSGE->GetIGame();
		if (!pIGame) return;
		auto pPlayerStatus = pIGame->GetPlayerStatus();
		if (!pPlayerStatus) return;

		pPlayerStatus->SetAfkTime(0);
	}
};

class WeaponPayload : public GameSDK::IGameFrameworkListener {
public:
	void OnPreRender() {
		auto pSSGE = *(GameSDK::SSystemGlobalEnvironment**)GameSDK::Locations::dwSystemGlobalEnvironment;
		auto pIGame = pSSGE->GetIGame();
		if (!pIGame) return;
		auto pLocalActor = pIGame->GetIGameFramework()->GetLocalActor();

		if (!is_valid_ptr(pLocalActor)) return;
		if (pLocalActor->IsDead()) return;

		GameSDK::IItem* currItem = pLocalActor->GetCurrentItem();
		if (!is_valid_ptr(currItem)) return;
		GameSDK::IWeapon* currWeapon = currItem->GetWeapon();
		if (!is_valid_ptr(currWeapon)) return;
		GameSDK::IWeaponGeneral* currWeaponGeneral = currWeapon->GetWeaponGeneral();
		if (!is_valid_ptr(currWeaponGeneral)) return;
		GameSDK::IWeaponParameters* currWeaponParams = currWeaponGeneral->GetParameters();
		if (!is_valid_ptr(currWeaponParams)) return;

		if (Globals::pSpread) {
			currWeaponParams->SetValue(EGameStatType::eGS_SprdMax, 0.f);
			currWeaponParams->SetValue(EGameStatType::eGS_SprdMin, 0.f);
			currWeaponParams->SetValue(EGameStatType::eGS_SprdAtt, 0.f);
			currWeaponParams->SetValue(EGameStatType::eGS_SprdDec, 0.f);
		}
		if (Globals::pRecoil) {
			currWeaponParams->SetValue(EGameStatType::eGS_RclMax, 0.f);
			currWeaponParams->SetValue(EGameStatType::eGS_RclSmth, 0.f);
			currWeaponParams->SetValue(EGameStatType::eGS_RclRnd, 0.f);
			currWeaponParams->SetValue(EGameStatType::eGS_RclAtt, 0.f);
			currWeaponParams->SetValue(EGameStatType::eGS_RclDec, 0.f);
		}
		if (Globals::pChangeWeapons) {
			currWeaponParams->SetValue(EGameStatType::eGS_DeselectDuration, 0.f);
			currWeaponParams->SetValue(EGameStatType::eGS_DeselectDurationBuff, 0.f);
			currWeaponParams->SetValue(EGameStatType::eGS_ActivateDuration, 0.f);
			currWeaponParams->SetValue(EGameStatType::eGS_ThrowDelayDuration, 0.f);
			currWeaponParams->SetValue(EGameStatType::eGS_ThrowDuration, 0.f);
			currWeaponParams->SetValue(EGameStatType::eGS_ThrowFireDelayDuration, 0.f);
			currWeaponParams->SetValue(EGameStatType::eGS_TossDuration, 0.f);
		}
		if (Globals::pNoSway) {
			currWeaponParams->SetValue(EGameStatType::eGS_SwayDec, 0.f);
			currWeaponParams->SetValue(EGameStatType::eGS_SwayMinX, 0.f);
			currWeaponParams->SetValue(EGameStatType::eGS_SwayMinY, 0.f);
			currWeaponParams->SetValue(EGameStatType::eGS_SwaySpeedMult, 0.f);
		}
	}
};

//class HotkeysProcessing : public GameSDK::IInputEventListener {
//public:
//	HotkeysProcessing() {}
//	bool OnInputEvent(const SInputEvent* inputEvent) {
//		if (inputEvent) {
//			if (inputEvent->keyId == EKeyId::eKI_Insert) {
//				//if (inputEvent->state == EInputState::eIS_Pressed) {
//					Globals::ShowMenu = !Globals::ShowMenu;
//				//}
//			}
//		}
//		return Globals::MenuMovement || Globals::ShowMenu;
//	}
//	bool OnInputEventUI(const SInputEvent* inputEvent) {
//		return (Globals::MenuMovement || Globals::ShowMenu) ? false : inputEvent->state == EInputState::eIS_UI;
//	}
//	int GetPriority() {
//		return 1;
//	}
//};

UI::UX* UXInstance;

int f_get_async_key_state(int vk) {
	return v_import<int>(xw(L"user32"), xw(L"GetAsyncKeyState"), vk);
}

HRESULT h_present(IDXGISwapChain* p_swapchain, uint32_t syncintreval, uint32_t flags) {

	UXInstance->CallPreRender();
	UXInstance->Entry();
	if (Globals::Skeleton) {
		auto pSSGE = *(GameSDK::SSystemGlobalEnvironment**)GameSDK::Locations::dwSystemGlobalEnvironment;
		auto pIEntitySystem = pSSGE->GetIEntitySystem();
		if (is_valid_ptr(pIEntitySystem)) {
			auto pEntityIterator = pIEntitySystem->GetEntityIterator();
			if (is_valid_ptr(pEntityIterator)) {
				auto pLocalActor = pSSGE->GetIGame()->GetIGameFramework()->GetLocalActor();
				if (is_valid_ptr(pLocalActor)) {
					if (!pLocalActor->IsDead()) {
						auto pRenderer = pSSGE->GetIRenderer();
						if (is_valid_ptr(pRenderer)) {
							while (GameSDK::IEntity* pEntity = pEntityIterator->Next()) {
								if (GameSDK::IActor* pActor = pSSGE->GetIGame()->GetIGameFramework()->GetIActorSystem()->GetActor(pEntity->GetEntityId())) {
									if (!pActor) continue;
									if (!SDKHelpers::filter_team(pLocalActor, pActor)) {
										continue;
									}
									if (pActor->IsDead()) {
										continue;
									}
									UXInstance->ProcessPlayer(pActor);
								}
							}
						}
					}
				}
			}
		}
	}
	UXInstance->CallPostRender();

	if (f_get_async_key_state(VK_INSERT) & 1) {
		Globals::ShowMenu = !Globals::ShowMenu;
	}

	return f_spoof<HRESULT>(p_present, p_swapchain, syncintreval, flags);
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    if (ul_reason_for_call == DLL_PROCESS_ATTACH) {
		set_spoof_stub(MemHelper::find_pattern(xc("FF 27")));

		auto pSSGE = *(GameSDK::SSystemGlobalEnvironment**)GameSDK::Locations::dwSystemGlobalEnvironment;

		auto pGameFramework = pSSGE->GetIGame()->GetIGameFramework();

		pGameFramework->RegisterListener(new WHPayload(), 0, GameSDK::Enums::EFRAMEWORKLISTENERPRIORITY::FRAMEWORKLISTENERPRIORITY_GAME);
		pGameFramework->RegisterListener(new SilentAimPayload(), 0, GameSDK::Enums::EFRAMEWORKLISTENERPRIORITY::FRAMEWORKLISTENERPRIORITY_GAME);
		pGameFramework->RegisterListener(new WeaponPayload(), 0, GameSDK::Enums::EFRAMEWORKLISTENERPRIORITY::FRAMEWORKLISTENERPRIORITY_GAME);
		pGameFramework->RegisterListener(new MiscPayload(), 0, GameSDK::Enums::EFRAMEWORKLISTENERPRIORITY::FRAMEWORKLISTENERPRIORITY_GAME);

		//pSSGE->GetIInput()->AddEventListener(new HotkeysProcessing());

		UXInstance = new UI::UX(
			pGameFramework->GetIUIDraw(),
			pSSGE->GetIRenderer(),
			pSSGE,
			pSSGE->GetICryFont()->GetIFFont(xc("overlay")),
			pSSGE->GetHardwareMouse(),
			pSSGE->GetIInput()
		);

		p_vmt_dx = new c_vmt((PDWORD64*)pSSGE->GetIRenderer()->GetIDXGISwapChain());

		p_present = apply_vmt_hk(p_vmt_dx, h_present, 8);
    }
    return TRUE;
}

