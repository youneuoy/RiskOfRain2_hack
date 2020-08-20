#include "Menu.h"



void InitImgui(ID3D11Device* device, ID3D11DeviceContext* device_context)
{
	ImGui::CreateContext();
	
	window1 = FindMainWindow(GetCurrentProcessId());
	/*oWndProc = (WNDPROC)SetWindowLongPtr(window1, GWL_WNDPROC, (LONG_PTR)WndProc);*/
	oWndProc = (WNDPROC)SetWindowLongPtr(window1, -4, (LONG_PTR)WndProc);
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	io.IniFilename = NULL;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
	io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\Arial.ttf", 20.5f, NULL, io.Fonts->GetGlyphRangesCyrillic());
    io.MouseDrawCursor = true;


    ImGui::GetStyle().FrameRounding = 4.0f;
    ImGui::GetStyle().GrabRounding = 4.0f;

    ImVec4* colors = ImGui::GetStyle().Colors;
    colors[ImGuiCol_Text] = ImVec4(0.95f, 0.96f, 0.98f, 1.00f);
    colors[ImGuiCol_TextDisabled] = ImVec4(0.36f, 0.42f, 0.47f, 1.00f);
    colors[ImGuiCol_WindowBg] = ImVec4(0.11f, 0.15f, 0.17f, 1.00f);
    colors[ImGuiCol_ChildBg] = ImVec4(0.15f, 0.18f, 0.22f, 1.00f);
    colors[ImGuiCol_PopupBg] = ImVec4(0.08f, 0.08f, 0.08f, 0.94f);
    colors[ImGuiCol_Border] = ImVec4(0.08f, 0.10f, 0.12f, 1.00f);
    colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
    colors[ImGuiCol_FrameBg] = ImVec4(0.20f, 0.25f, 0.29f, 1.00f);
    colors[ImGuiCol_FrameBgHovered] = ImVec4(0.12f, 0.20f, 0.28f, 1.00f);
    colors[ImGuiCol_FrameBgActive] = ImVec4(0.09f, 0.12f, 0.14f, 1.00f);
    colors[ImGuiCol_TitleBg] = ImVec4(0.09f, 0.12f, 0.14f, 0.65f);
    colors[ImGuiCol_TitleBgActive] = ImVec4(0.08f, 0.10f, 0.12f, 1.00f);
    colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.00f, 0.00f, 0.00f, 0.51f);
    colors[ImGuiCol_MenuBarBg] = ImVec4(0.15f, 0.18f, 0.22f, 1.00f);
    colors[ImGuiCol_ScrollbarBg] = ImVec4(0.02f, 0.02f, 0.02f, 0.39f);
    colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.20f, 0.25f, 0.29f, 1.00f);
    colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.18f, 0.22f, 0.25f, 1.00f);
    colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.09f, 0.21f, 0.31f, 1.00f);
    colors[ImGuiCol_CheckMark] = ImVec4(0.28f, 0.56f, 1.00f, 1.00f);
    colors[ImGuiCol_SliderGrab] = ImVec4(0.28f, 0.56f, 1.00f, 1.00f);
    colors[ImGuiCol_SliderGrabActive] = ImVec4(0.37f, 0.61f, 1.00f, 1.00f);
    colors[ImGuiCol_Button] = ImVec4(0.20f, 0.25f, 0.29f, 1.00f);
    colors[ImGuiCol_ButtonHovered] = ImVec4(0.28f, 0.56f, 1.00f, 1.00f);
    colors[ImGuiCol_ButtonActive] = ImVec4(0.06f, 0.53f, 0.98f, 1.00f);
    colors[ImGuiCol_Header] = ImVec4(0.20f, 0.25f, 0.29f, 0.55f);
    colors[ImGuiCol_HeaderHovered] = ImVec4(0.26f, 0.59f, 0.98f, 0.80f);
    colors[ImGuiCol_HeaderActive] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
    colors[ImGuiCol_Separator] = ImVec4(0.20f, 0.25f, 0.29f, 1.00f);
    colors[ImGuiCol_SeparatorHovered] = ImVec4(0.10f, 0.40f, 0.75f, 0.78f);
    colors[ImGuiCol_SeparatorActive] = ImVec4(0.10f, 0.40f, 0.75f, 1.00f);
    colors[ImGuiCol_ResizeGrip] = ImVec4(0.26f, 0.59f, 0.98f, 0.25f);
    colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.26f, 0.59f, 0.98f, 0.67f);
    colors[ImGuiCol_ResizeGripActive] = ImVec4(0.26f, 0.59f, 0.98f, 0.95f);
    colors[ImGuiCol_Tab] = ImVec4(0.11f, 0.15f, 0.17f, 1.00f);
    colors[ImGuiCol_TabHovered] = ImVec4(0.26f, 0.59f, 0.98f, 0.80f);
    colors[ImGuiCol_TabActive] = ImVec4(0.20f, 0.25f, 0.29f, 1.00f);
    colors[ImGuiCol_TabUnfocused] = ImVec4(0.11f, 0.15f, 0.17f, 1.00f);
    colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.11f, 0.15f, 0.17f, 1.00f);
    colors[ImGuiCol_PlotLines] = ImVec4(0.61f, 0.61f, 0.61f, 1.00f);
    colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.00f, 0.43f, 0.35f, 1.00f);
    colors[ImGuiCol_PlotHistogram] = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
    colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
    colors[ImGuiCol_TextSelectedBg] = ImVec4(0.26f, 0.59f, 0.98f, 0.35f);
    colors[ImGuiCol_DragDropTarget] = ImVec4(1.00f, 1.00f, 0.00f, 0.90f);
    colors[ImGuiCol_NavHighlight] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
    colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.00f, 1.00f, 1.00f, 0.70f);
    colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.20f);
    colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.35f);


	ImGui_ImplDX11_Init(device, device_context);
	ImGui_ImplWin32_Init(window1);
	initialized_imgui = true;
	return;
	
}

void MenuMainFunc(ID3D11Device* device, ID3D11DeviceContext* device_context)
{
	if (!initialized_imgui)
	{
		InitImgui(device, device_context);
	}
	else
	{
		ImGui::CreateContext();
		ImGui_ImplDX11_NewFrame();
		ImGui_ImplWin32_NewFrame();
		ImGui::NewFrame();

		if (menuMainShow)
		{

			ImGui::Begin("Risk Of Rain 2 Trainer (gamehacklab.ru)", &menuMainShow);
			ImGui::Text(u8"by KRYPTOPUNK");
			ImGui::Text(u8"Cheat Settings");
			ImGui::Checkbox(u8"In game", &bInGame);
            if (ImGui::Button(u8"Open camera settings"))
            {
                menuCameraSettingsShow = true;
            }
            if (ImGui::Button("Open character settings"))
            {
                menuCharacterSettingsShow = true;
            }

			if (ImGui::TreeNode(u8"Extra"))
			{
				ImGui::Checkbox(u8"Kill by coursor", &bKillByCoursor);
				ImGui::TreePop();
			};
			
			ImGui::End();

		}
        if (menuCameraSettingsShow)
        {

            ImGui::Begin("CAMERA SETTINGS WINDOW", &menuCameraSettingsShow);
            ImGui::Checkbox(u8"Write in field's", &bCameraSettingsEnable);
            ImGui::SliderFloat(u8"Base FOV", &fBaseFOV, 0, 300.f);
            ImGui::SliderFloat(u8"Current FOV", &fCurrentFOV, 0, 300.f);
            ImGui::SliderFloat(u8"FOV Velocity", &fFOVVelocity, 0, 300.f);
            ImGui::Checkbox(u8"Enable Fading", &bEnableFading);
            ImGui::SliderFloat(u8"Start Fade Distance", &fStartFadeDistance, 0, 300.f);
            ImGui::SliderFloat(u8"End Fade Distance", &fEndFadeDistance, 0, 3000.f);
            ImGui::Checkbox(u8"Disable Spectating", &bDisableSpectating);
            ImGui::SliderFloat(u8"Max Aim Raycast Distance", &fmaxAimRaycastDistance, 500.f, 30000.f);
            ImGui::Checkbox(u8"Write in PitchYaw", &bWriteInPY);
            ImGui::SliderFloat(u8"Pitch", &fPitch, -70.f, 70.f);
            ImGui::SliderFloat(u8"Yaw", &fYaw, 0.f, 180.f);
            ImGui::DragFloat3(u8"Crosshair World Position (only read)", &v3_crosshairWorldPosition.x, 3.f, -100.f, 360.f);
            ImGui::SliderFloat(u8"Current Camera Distance", &fCurrentCameraDistance, 0.f, 1000.f);
            ImGui::SliderFloat(u8"Camera Distance Velocity", &fCameraDistanceVelocity, -10.f, 1000.f);
            //ImGui::SliderFloat(u8"Hitmarker Alpha", &fHitmarkerAlpha, 0.f, 1000.f);
            //ImGui::SliderFloat(u8"Hitmarker Timer", &fHitmarkerTimer, 0.f, 1000.f);
            ImGui::End();
        }
        if (menuCharacterSettingsShow)
        {
            ImGui::Begin("CHARACTER SETTINGS SHOW", &menuCharacterSettingsShow);
            ImGui::Checkbox("Write in field's", &bCharacterSettingsWrite);
            ImGui::SliderInt("Body Index", &iBodyIndex, 0, 4);
            ImGui::Checkbox("Linked to master", &bLinkedToMaster);
            ImGui::Checkbox("Is Player Controlled", &bIsPlayerControlled);
            ImGui::Checkbox("Disabling HurtBoxes", &bDisablingHurtBoxes);
            ImGui::SliderInt("Previous Eqipment Index", &iPreviousEquipmentIndex, 0, 5);
            ImGui::Checkbox("Has Effective Authority", &bHasEffectiveAuthority);
            ImGui::Checkbox("Is Sprinting", &b_isSprinting);
            ImGui::SliderFloat("Out Of Combat Stopwatch", &fOutOfCombatStopwatch, 0.f, 999.f);
            ImGui::SliderFloat("Out Of Danger Stopwatch", &fOutOfDangerStopwatch, 0.f, 999.f);
            ImGui::Checkbox(" Out Of Combat", &bOutOfCombat);
            ImGui::Checkbox(" Out Of Danger", &b_outOfDanger);
            ImGui::SliderFloat3("PreviosPosition (Only Read)", &vec3_previousPosition.x, -180, 360);
            ImGui::SliderFloat("Not Moving Stopwatch", &fNotMovingStopwatch, 0.f, 999.f);
            ImGui::Checkbox(" Root Motion In Main State", &bRootMotionInMainState);
            if (ImGui::TreeNode("Player's parameters "))
            {

                
                ImGui::SliderFloat("Main Root Speed", &fMainRootSpeed, 0, 999.f);
                ImGui::SliderFloat("Base Max Health", &fBaseMaxHealth, 0, 999.f);
                ImGui::SliderFloat("Base Regen", &fBaseRegen, 0, 999.f);
                ImGui::SliderFloat("Base Max Regen", &fBaseMaxShield, 0, 999.f);
                ImGui::SliderFloat("Base Move Speed", &fBaseMoveSpeed, 0, 999.f);
                ImGui::SliderFloat("Base Acceleration", &fBaseAcceleration, 0, 999.f);
                ImGui::SliderFloat("Base Jump Power", &fBaseJumpPower, 0, 999.f);
                ImGui::SliderFloat("Base Damage", &fBaseDamage, 0, 999.f);
                ImGui::SliderFloat("Base Attack Speed", &fBaseAttackSpeed, 0, 999.f);
                ImGui::SliderFloat("Base Crit Chance", &fBaseCrit, 0, 100.f);
                ImGui::SliderFloat("Base Armor", &fBaseArmor, 0, 999.f);
                ImGui::SliderFloat("Base Jump Count", &fBaseJumpCount, 0, 999.f);
                ImGui::SliderFloat("Sprinting Speed Multiplier", &fSprintingSpeedMultiplier, 0, 999.f);
                ImGui::SliderFloat("Auto Calculate Level Stats", &fAutoCalculateLevelStats, 0, 999.f);
                ImGui::SliderFloat("Level Max Health", &fLevelMaxHealth, 0, 999.f);
                ImGui::SliderFloat("Level Regen", &fLevelRegen, 0, 999.f);
                ImGui::SliderFloat("Level Max Shield", &fLevelMaxShield, 0, 999.f);
                ImGui::SliderFloat("Level Move Speed", &fLevelMoveSpeed, 0, 999.f);
                ImGui::SliderFloat("Level Jump Power", &fLevelJumpPower, 0, 999.f);
                ImGui::SliderFloat("Level Damage", &fLevelDamage, 0, 999.f);
                ImGui::SliderFloat("Level Attack Speed", &fLevelAttackSpeed, 0, 999.f);
                ImGui::SliderFloat("Level Crit Chance", &fLevelCrit, 0, 999.f);
                ImGui::SliderFloat("Level Armor", &fLevelArmor, 0, 999.f);
                ImGui::SliderFloat("Level Experience", &fExperience, 0, 999.f);
                ImGui::SliderFloat("Level", &fLevel, 0, 999.f);
                ImGui::SliderFloat("Max Health", &fMaxhealth, 0, 999.f);
                ImGui::SliderFloat("Max Barrier", &fMaxBarrier, 0, 999.f);
                ImGui::SliderFloat("Barrier Decay Rate", &fBarrierDecayRate, 0, 999.f);
                ImGui::SliderFloat("Regen", &fRegen, 0, 999.f);
                ImGui::SliderFloat("MaxShield", &fMaxShield, 0, 999.f);
                ImGui::SliderFloat("Move Speed", &fMoveSpeed, 0, 999.f);
                ImGui::SliderFloat("Acceleration", &fAcceleration, 0, 999.f);
                ImGui::SliderFloat("JumpPower", &fJumpPower, 0, 999.f);
                ImGui::SliderInt("Max Jump Count", &iMaxJumpCoun, 0, 999);
                ImGui::SliderFloat("Max Jump Height", &fMaxJumpHeight, 0, 999);
                ImGui::SliderFloat("Damage", &fDamage, 0, 999);
                ImGui::SliderFloat("AttackSpeed", &fAttackSpeed, 0, 999);
                ImGui::SliderFloat("Crit Chance", &fCrit, 0, 999);
                ImGui::SliderFloat("Armor", &fArmor, 0, 999);
                ImGui::SliderFloat("Crit Heal", &fCritHeal, 0, 999);
                ImGui::SliderFloat("Curse Penalty", &fCursePenalty, 0, 999);
                ImGui::Checkbox("Has One Shot Protection", &bHasOneShotProtection);
                ImGui::Checkbox("Is Glass", &bIsGlass);
                ImGui::SliderFloat("One Shot Protection Fraction", &fOneShotProtectionFraction, 0, 999);
                ImGui::Checkbox("Stats Dirty", &bStatsDirty);
                ImGui::SliderFloat("Aim Timer", &fAimTimer, 0, 999);
                ImGui::SliderFloat("WarCry Timer", &fWarCryTimer, 0, 999);
                ImGui::Checkbox("WarCry Ready", &b_warCryReady);
                ImGui::SliderInt("Kill Count", &iKillCount, 0, 999);
                ImGui::SliderFloat("Tesla Buff Roll Timer", &fTeslaBuffRollTimer, 0, 999);
                ImGui::SliderFloat("Tesla Fire Timer", &fTeslaFireTimer, 0, 999);
                ImGui::SliderFloat("Tesla Reset List Timer", &fTeslaResetListTimer, 0, 999);
                ImGui::SliderFloat("Tesla Reset List Interval", &fTeslaResetListInterval, 0, 999);
                ImGui::Checkbox("Tesla Crit", &bTeslaCrit);
                ImGui::SliderFloat("Hellfire Life Time", &fHelfireLifetime, 0, 999);
                ImGui::Checkbox("Was Lucky", &bWasLucky);
                ImGui::Checkbox("Guard Resummon Cooldown", &bGuardResummonCooldown);
                ImGui::SliderFloat("Poisonball Timer", &fPoisonballTimer, 0, 999);
                ImGui::SliderFloat("Ward Resummon Cooldown", &fWardResummonCooldown, 0, 999);
                ImGui::SliderFloat("Spread Bloom Decay Time", &fSpreadBloomDecayTime, 0, 999);
                ImGui::SliderFloat("Spread Bloom Internal", &fSpreadBloomInternal, 0, 999);
                ImGui::Checkbox("Hide Crosshair", &bHideCrosshair);
                ImGui::SliderFloat("Milti Kill Timer", &fMultiKillTimer, 0, 999);
                ImGui::SliderInt("MultiKillCount", &iMultiKillCount, 0, 999);
                ImGui::SliderFloat("Radius", &fRadius, 0, 999);
                ImGui::Checkbox("Is Champion", &bIsChampion);
                ImGui::Checkbox("Is Elite", &bIsElite);
                ImGui::SliderInt("Skin Index", &iSkinIndex, 0, 999);
                ImGui::SliderInt("Local Start Time", &iLocalStartTime, 0, 999);






                ImGui::TreePop();
            }

            ImGui::End();

        }

		ImGui::EndFrame();
		ImGui::Render();
		ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
	}
}
LRESULT __stdcall WndProc(const HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	if (menuMainShow) // если вызывается хендлер
	{
		ImGui_ImplWin32_WndProcHandler(hwnd, uMsg, wParam, lParam);
	}
	return CallWindowProc(oWndProc, hwnd, uMsg, wParam, lParam); // если же нет, вызываем оригинальный процесс
}