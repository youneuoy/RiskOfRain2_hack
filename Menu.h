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
int32_t iActiveBuffsListCount; 
int32_t iEliteBuffCount; 
int32_t iPendingTonicAfflictionCount; 
int32_t iBodyFlags; 
int32_t iMasterObjectId; 
bool bLinkedToMaster; 
bool bLsPlayerControlled; 
bool disablingHurtBoxes; 
int32_t previousEquipmentIndex; 
bool hasEffectiveAuthority; 
bool _isSprinting; 
float outOfCombatStopwatch; 
float outOfDangerStopwatch; 
bool outOfCombat; 
bool _outOfDanger; 
Vector3 previousPosition; 
float notMovingStopwatch; 
bool rootMotionInMainState;
float mainRootSpeed;
float baseMaxHealth; 
float baseRegen; 
float baseMaxShield; 
float baseMoveSpeed; 
float baseAcceleration; 
float baseJumpPower; 
float baseDamage; 
float baseAttackSpeed; 
float baseCrit;
float baseArmor; 
float baseJumpCount; 
float sprintingSpeedMultiplier; 
float autoCalculateLevelStats; 
float levelMaxHealth; 
float levelRegen; 
float levelMaxShield; 
float levelMoveSpeed; 
float levelJumpPower; 
float levelDamage; 
float levelAttackSpeed;
float levelCrit; 
float levelArmor;
float experience;
float level; 
float maxhealth; 
float maxBarrier;
float barrierDecayRate; 
float regen; 
float maxShield; 
float moveSpeed; 
float acceleration; 
float jumpPower; 
int32_t maxJumpCoun;
float maxJumpHeight;
float damage; 
float attackSpeed; 
float crit; 
float armor; 
float critHeal; 
float cursePenalty; 
bool hasOneShotProtection; 
bool isGlass; 
float oneShotProtectionFraction; 
bool statsDirty;
float aimTimer; 
float warCryTimer; 
bool _warCryReady; 
int32_t killCount; 
float teslaBuffRollTimer; 
float teslaFireTimer; 
float teslaResetListTimer;
float teslaResetListInterval;
bool teslaCrit;
float helfireLifetime; 
bool wasLucky; 
bool guardResummonCooldown; 
float poisonballTimer; 
float wardResummonCooldown;
float spreadBloomDecayTime;
float spreadBloomInternal; 
bool hideCrosshair; 
float multiKillTimer; 
int32_t multiKillCount; 
float radius;
bool isChampion; 
bool isElite; 
int32_t skinIndex; 
int32_t localStartTime; 
////////////////////////////////////////////////////////////////


bool bCheatInit = false;
bool bInGame = false;
bool bKillByCoursor = false;
bool bCameraSettingsEnable = false;
bool bWriteInPY = false;



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

