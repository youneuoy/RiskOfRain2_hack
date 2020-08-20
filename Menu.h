#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <iostream>
#include "d3d11draw/rD3D11.h"
#include "d3d11draw/pch.h"
#include "imgui/imgui_impl_dx11.h"
#include "imgui/imgui_impl_win32.h"
#include "sdk.h"
extern CameraRigController* PlayerCRC;
template <typename T>
T* SetPointerTo(T*& _where,uintptr_t baseaddr, std::vector<uintptr_t>& vec);
/////////////////////////////////////////////////////////////////
float fBaseFOV;
float fCurrentFOV;
float fFOVVelocity;
float fStartFadeDistance;
float fEndFadeDistance;
float fmaxAimRaycastDistance;
float fPitch;
float fYaw;
float fCurrentCameraDistance;
float fCameraDistanceVelocity;
//float fHitmarkerAlpha;
//float fHitmarkerTimer;
bool bEnableFading;
bool bDisableSpectating;
Vector3 v3_crosshairWorldPosition;
//////////////////////////////////////////////////////////////////////
int32_t iBodyIndex; 
//int32_t iActiveBuffsListCount; 
//int32_t iEliteBuffCount; 
//int32_t iPendingTonicAfflictionCount; 
//int32_t iBodyFlags; 
//int32_t iMasterObjectId; 
bool bLinkedToMaster; 
bool bIsPlayerControlled; 
bool bDisablingHurtBoxes; 
int32_t iPreviousEquipmentIndex; 
bool bHasEffectiveAuthority; 
bool b_isSprinting; 
float fOutOfCombatStopwatch; 
float fOutOfDangerStopwatch; 
bool bOutOfCombat; 
bool b_outOfDanger; 
Vector3 vec3_previousPosition; 
float fNotMovingStopwatch; 
bool bRootMotionInMainState;
float fMainRootSpeed;
float fBaseMaxHealth; 
float fBaseRegen; 
float fBaseMaxShield; 
float fBaseMoveSpeed; 
float fBaseAcceleration; 
float fBaseJumpPower; 
float fBaseDamage; 
float fBaseAttackSpeed; 
float fBaseCrit;
float fBaseArmor; 
float fBaseJumpCount; 
float fSprintingSpeedMultiplier; 
float fAutoCalculateLevelStats; 
float fLevelMaxHealth; 
float fLevelRegen; 
float fLevelMaxShield; 
float fLevelMoveSpeed; 
float fLevelJumpPower; 
float fLevelDamage; 
float fLevelAttackSpeed;
float fLevelCrit; 
float fLevelArmor;
float fExperience;
float fLevel; 
float fMaxhealth; 
float fMaxBarrier;
float fBarrierDecayRate; 
float fRegen; 
float fMaxShield; 
float fMoveSpeed; 
float fAcceleration; 
float fJumpPower; 
int32_t iMaxJumpCoun;
float fMaxJumpHeight;
float fDamage; 
float fAttackSpeed; 
float fCrit; 
float fArmor; 
float fCritHeal; 
float fCursePenalty; 
bool bHasOneShotProtection; 
bool bIsGlass; 
float fOneShotProtectionFraction; 
bool bStatsDirty;
float fAimTimer; 
float fWarCryTimer; 
bool b_warCryReady; 
int32_t iKillCount; 
float fTeslaBuffRollTimer; 
float fTeslaFireTimer; 
float fTeslaResetListTimer;
float fTeslaResetListInterval;
bool bTeslaCrit;
float fHelfireLifetime; 
bool bWasLucky; 
bool bGuardResummonCooldown; 
float fPoisonballTimer; 
float fWardResummonCooldown;
float fSpreadBloomDecayTime;
float fSpreadBloomInternal; 
bool bHideCrosshair; 
float fMultiKillTimer; 
int32_t iMultiKillCount; 
float fRadius;
bool bIsChampion; 
bool bIsElite; 
int32_t iSkinIndex; 
int32_t iLocalStartTime; 
////////////////////////////////////////////////////////////////


bool bCheatInit = false;
bool bInGame = false;
bool bKillByCoursor = false;
bool bCameraSettingsEnable = false;
bool bWriteInPY = false;
bool bCharacterSettingsWrite = false;


bool initialized_imgui = false;
bool menuMainShow = false;
bool menuCameraSettingsShow = false;
bool menuCharacterSettingsShow = false;


ImGuiContext* context = 0;
WNDPROC		oWndProc = NULL;																		// текущий хендл процесса
HWND		window1 = NULL;
typedef LRESULT(CALLBACK* WNDPROC)(HWND, UINT, WPARAM, LPARAM);
extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

void InitImgui(ID3D11Device* device, ID3D11DeviceContext* device_context);
void MenuMainFunc(ID3D11Device* device, ID3D11DeviceContext* device_context);
LRESULT __stdcall WndProc(const HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

