// dllmain.cpp : Определяет точку входа для приложения DLL.
#include <Windows.h>
//#include "sdk.h"
//#include "d3d11draw/rD3D11.h"
//#include "d3d11draw/pch.h"
//#include "imgui/imgui.h"
//#include "imgui/imgui_impl_dx11.h"
//#include "imgui/imgui_impl_win32.h"
#include "Menu.h"
rD3D11 rd11;
std::vector<uintptr_t> healthcomponentplayer_offsets = { 0x8 ,0x10 ,0x30 ,0x118 ,0x28 ,0x0 };
std::vector<uintptr_t> CameraRigControllerPtr_offsets = { 0x0 ,0x10 ,0x30 ,0xC8 ,0x28 ,0xA0,0x0 };
std::vector<uintptr_t> CharacterBodyPtr_offsets = { 0x8 ,0x10 ,0x30 ,0xC8 ,0x28 ,0x48,0x0 };
std::vector<uintptr_t> CharacterMasterPtr_offsets = { 0x8 ,0x10 ,0x30 ,0x48 ,0x28 ,0x68,0x0 };
HealthComponent* PlayerHC = nullptr;
CameraRigController* PlayerCRC = nullptr;
CharacterBody* PlayerCB = nullptr;
CharacterMaster* PlayerCM = nullptr;
uintptr_t CAMERA_HEALTH_CHARACTER_PLAYER_BASE;
template <typename T>
T* SetPointerTo(T*& _where, uintptr_t baseaddr, std::vector<uintptr_t>& vec)
{
    _where = nullptr;
    do
    {
        _where = reinterpret_cast<T*>(FindAddressByOffset(baseaddr, vec));
    } while (_where == nullptr);

    return _where;

}



bool IsLoadedCorrect(HealthComponent*& one, CameraRigController*& two, CharacterBody*& three,CharacterMaster*& four)
{
    if (one != nullptr && two != nullptr && three != nullptr && four != nullptr)
    {
        return true;
    }
    else
        return false;
}


HRESULT __stdcall hkPresent(IDXGISwapChain* pThis, UINT SyncInterval, UINT Flags)
{
    if (!rd11.pDevice || rd11.pSwapchain != pThis)
    {
        rd11.InitD3DDraw(pThis);
    }

    MenuMainFunc(rd11.pDevice, rd11.pContext);

    return rd11.oPresentTramp(pThis, SyncInterval, Flags);
}

DWORD ScreenCastRoutine()
{
    if (rd11.HookD3D())
    {
        while (true)
        {

        };
    }
    
    rd11.UnHook();
    return 0;
}
DWORD MainHackRoutine()
{
    while (true)
    {


        if (bInGame)
        {


            if (!bCheatInit)
            {
                CAMERA_HEALTH_CHARACTER_PLAYER_BASE = reinterpret_cast<uintptr_t>(GetModuleHandle(L"UnityPlayer.dll")) + 0x01563A28;
                SetPointerTo<HealthComponent>(PlayerHC, CAMERA_HEALTH_CHARACTER_PLAYER_BASE, healthcomponentplayer_offsets);
                SetPointerTo<CameraRigController>(PlayerCRC, CAMERA_HEALTH_CHARACTER_PLAYER_BASE, CameraRigControllerPtr_offsets);
                SetPointerTo<CharacterBody>(PlayerCB, CAMERA_HEALTH_CHARACTER_PLAYER_BASE, CharacterBodyPtr_offsets);
                SetPointerTo<CharacterMaster>(PlayerCM, CAMERA_HEALTH_CHARACTER_PLAYER_BASE, CharacterMasterPtr_offsets);
                if (!IsLoadedCorrect(PlayerHC, PlayerCRC, PlayerCB, PlayerCM))
                {
                    bInGame = false;
                    bCheatInit = false;
                    bKillByCoursor = false;
                    bCameraSettingsEnable = false;
                    bWriteInPY = false;
                    bCharacterSettingsWrite = false;
                    bGodModEnable = false;
                }
                else
                {
                    bCheatInit = true;
                }

               
            }
        }
        else
        {
            bCheatInit = false;
            bKillByCoursor = false;
            bCameraSettingsEnable = false;
            bWriteInPY = false;
            bCharacterSettingsWrite = false;
            bGodModEnable = false;
            PlayerHC = nullptr;
            PlayerCRC = nullptr;
            PlayerCB = nullptr;
            PlayerCM = nullptr;
        }

        
        if (IsLoadedCorrect(PlayerHC, PlayerCRC, PlayerCB,PlayerCM) && bCheatInit)
        {
            PlayerCM->_money = MenuPlayerCM._money;
            if (bKillByCoursor)
            {
                if (PlayerCRC->lastCrosshairHurtBox != nullptr)
                {
                    PlayerCRC->lastCrosshairHurtBox->healthComponent->health = 0;
                }
            }
            if (bGodModEnable)
            {
                PlayerHC->godMode = true;
            }
            else
            {
                PlayerHC->godMode = false;
            }
            if (bCameraSettingsEnable)
            {
                if (bWriteInPY)
                {
                    PlayerCRC->pitch = MenuPlayerCRC.pitch;
                    PlayerCRC->yaw = MenuPlayerCRC.yaw;
                }

                PlayerCRC->baseFov                  = MenuPlayerCRC.baseFov;
                PlayerCRC->currentFov               = MenuPlayerCRC.currentFov;
                PlayerCRC->currentCameraDistance    = MenuPlayerCRC.currentCameraDistance;
                PlayerCRC->disableSpectating        = MenuPlayerCRC.disableSpectating;
                PlayerCRC->enableFading             = MenuPlayerCRC.enableFading;
                PlayerCRC->fadeEndDistance          = MenuPlayerCRC.fadeEndDistance;
                PlayerCRC->fadeStartDistance        = MenuPlayerCRC.fadeStartDistance;
                PlayerCRC->fovVelocity              = MenuPlayerCRC.fovVelocity;
                PlayerCRC->maxAimRaycastDistance    = MenuPlayerCRC.maxAimRaycastDistance;
            }
            else
            {


                MenuPlayerCRC.pitch                     = PlayerCRC->pitch;
                MenuPlayerCRC.yaw                       = PlayerCRC->yaw;
                MenuPlayerCRC.baseFov                   = PlayerCRC->baseFov;
                MenuPlayerCRC.currentFov                = PlayerCRC->currentFov;
                MenuPlayerCRC.crosshairWorldPosition    = PlayerCRC->crosshairWorldPosition;
                MenuPlayerCRC.currentCameraDistance     = PlayerCRC->currentCameraDistance;
                MenuPlayerCRC.disableSpectating         = PlayerCRC->disableSpectating;
                MenuPlayerCRC.enableFading              = PlayerCRC->enableFading;
                MenuPlayerCRC.fadeEndDistance           = PlayerCRC->fadeEndDistance;
                MenuPlayerCRC.fadeStartDistance         = PlayerCRC->fadeStartDistance;
                MenuPlayerCRC.fovVelocity               = PlayerCRC->fovVelocity;
                MenuPlayerCRC.maxAimRaycastDistance     = PlayerCRC->maxAimRaycastDistance;


            }
            if (bCharacterSettingsWrite)
            {
                *PlayerCB = MenuPlayerCB;
            }
            else
            {
                MenuPlayerCB = *PlayerCB;
            }
        }
        else
        {
            bInGame = false;

        }

        Sleep(1);

        Sleep(10);
    }

    return 0;
}


BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:    CreateThread(NULL, NULL, reinterpret_cast<LPTHREAD_START_ROUTINE>(MainHackRoutine), hModule, NULL, NULL);
                                CreateThread(NULL, NULL, reinterpret_cast<LPTHREAD_START_ROUTINE>(ScreenCastRoutine), hModule, NULL, NULL);

    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

