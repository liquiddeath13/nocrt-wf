#include <Windows.h>
#include <winternl.h>
#include <map>
#include <string>

#include "xor/Xor.h"
#include "xor/xor_data.h"
#include "xor/xor_value.h"

#include "Data.h"
#include "spoofcall/spoof_call.hpp"

#include "SDK.h"

bool bounds_check(void* ptr, DWORD64 minV, DWORD64 maxV) {
	return (DWORD64)ptr > minV && (DWORD64)ptr < maxV;
}

bool is_valid_ptr(void* ptr) {
	if (!ptr) {
		return false;
	}
	return bounds_check(ptr, 0x100000, 0xFFFFFFFFFFFF);
}

class SilentAimPayload : public GameSDK::IGameFrameworkListener {
	DWORD silentFov = 150;
	bool autofire = false;
public:
	void OnPreRender() {
		auto pSSGE = *(GameSDK::SSystemGlobalEnvironment**)dwSystemGlobalEnvironment;
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

				auto boneInfo = pActor->GetBonePosition(GameSDK::EBonesID::BONE_HEAD);
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

		if (silentMaxDist <= silentFov) {

			currWeapon->SetFiringPos(silentPos);

			if (autofire) {
				currWeapon->StartFire();
				currWeapon->StopFire();
			}

		}
	}
};

class WHPayload : public GameSDK::IGameFrameworkListener {
	HUDSilhouettesColor VisibleColor = HUDSilhouettesColor(0.96f, 0.46f, 0.94f);
	HUDSilhouettesColor InvisibleColor = HUDSilhouettesColor(0.f, 0.64f, 0.21f);
	HUDSilhouettesColor deadColor = HUDSilhouettesColor(0.f, 0.f, 0.f);
	PVOID SetVisionParams(EntityId Entityid, HUDSilhouettesColor color, bool hide = false, bool CheckDistance = false, float Distance = 1000.f)
	{
		return spoof_call<PVOID>((PVOID)dwCHUDSilhouettes, NULL, Entityid, color, hide, CheckDistance, Distance);
	}
	void DrawOutline(EntityId pEntId, bool dead = false, bool visible = false)
	{
		SetVisionParams(pEntId, dead ? deadColor : visible ? VisibleColor : InvisibleColor);
	}
public:
	void OnPreRender() {
		auto pSSGE = *(GameSDK::SSystemGlobalEnvironment**)dwSystemGlobalEnvironment;
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

			if (GameSDK::IActor* pActor = pSSGE->GetIGame()->GetIGameFramework()->GetIActorSystem()->GetActor(eId)) {
				if (!pActor) continue;

				if (!SDKHelpers::filter_team(pLocalActor, pActor)) {
					continue;
				}

				if (pActor->IsDead()) {
					DrawOutline(eId, true);
					continue;
				}

				auto boneInfo = pActor->GetBonePosition(GameSDK::EBonesID::BONE_HEAD);
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
		auto pSSGE = *(GameSDK::SSystemGlobalEnvironment**)dwSystemGlobalEnvironment;
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
		auto pSSGE = *(GameSDK::SSystemGlobalEnvironment**)dwSystemGlobalEnvironment;
		auto pIGame = pSSGE->GetIGame();
		if (!pIGame) return;
		auto pLocalActor = pIGame->GetIGameFramework()->GetLocalActor();

		if (!is_valid_ptr(pLocalActor)) return;
		if (pLocalActor->IsDead()) return;

		GameSDK::IItem* currItem = pLocalActor->GetCurrentItem();
		if (!is_valid_ptr(currItem)) return;
		GameSDK::IWeapon* currWeapon = currItem->GetWeapon();
		if (!is_valid_ptr(currWeapon)) return;
		GameSDK::CWeaponGeneral* currWeaponGeneral = currWeapon->GetWeaponGeneral();
		if (!is_valid_ptr(currWeaponGeneral)) return;
		GameSDK::IWeaponParameters* currWeaponParams = currWeaponGeneral->GetParameters();
		if (!is_valid_ptr(currWeaponParams)) return;

		currWeaponParams->SetValue(EGameStatType::eGS_SprdMax, 0.f);
		currWeaponParams->SetValue(EGameStatType::eGS_SprdMin, 0.f);
		currWeaponParams->SetValue(EGameStatType::eGS_SprdAtt, 0.f);
		currWeaponParams->SetValue(EGameStatType::eGS_SprdDec, 0.f);

		currWeaponParams->SetValue(EGameStatType::eGS_RclMax, 0.f);
		currWeaponParams->SetValue(EGameStatType::eGS_RclSmth, 0.f);
		currWeaponParams->SetValue(EGameStatType::eGS_RclRnd, 0.f);
		currWeaponParams->SetValue(EGameStatType::eGS_RclAtt, 0.f);
		currWeaponParams->SetValue(EGameStatType::eGS_RclDec, 0.f);
	}
};

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    if (ul_reason_for_call == DLL_PROCESS_ATTACH) {
		set_spoof_stub(MemHelper::find_pattern(xc("FF 27")));

		auto pSSGE = *(GameSDK::SSystemGlobalEnvironment**)dwSystemGlobalEnvironment;

		auto pGameFramework = pSSGE->GetIGame()->GetIGameFramework();

		pGameFramework->RegisterListener(new WHPayload(), 0, GameSDK::EFRAMEWORKLISTENERPRIORITY::FRAMEWORKLISTENERPRIORITY_GAME);
		pGameFramework->RegisterListener(new SilentAimPayload(), 0, GameSDK::EFRAMEWORKLISTENERPRIORITY::FRAMEWORKLISTENERPRIORITY_GAME);
		pGameFramework->RegisterListener(new WeaponPayload(), 0, GameSDK::EFRAMEWORKLISTENERPRIORITY::FRAMEWORKLISTENERPRIORITY_GAME);
		pGameFramework->RegisterListener(new MiscPayload(), 0, GameSDK::EFRAMEWORKLISTENERPRIORITY::FRAMEWORKLISTENERPRIORITY_GAME);
    }
    return TRUE;
}

