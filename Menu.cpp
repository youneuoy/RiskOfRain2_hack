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
        if (menuMainShow || menuCameraSettingsShow || menuCharacterSettingsShow)
        {
            ImGui::GetIO().MouseDrawCursor = true;
        }
        else
        {
            ImGui::GetIO().MouseDrawCursor = false;
        }

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
                ImGui::Checkbox("God Mode", &bGodModEnable);
				ImGui::TreePop();
			};
			
			ImGui::End();

		}
        if (menuCameraSettingsShow) // MenuPlayerCRC
        {

            ImGui::Begin("CAMERA SETTINGS WINDOW", &menuCameraSettingsShow);
            ImGui::Checkbox(u8"Write in field's", &bCameraSettingsEnable);

            ImGui::SliderFloat(u8"Base FOV", &MenuPlayerCRC.baseFov, 0, 300.f);
            ImGui::SliderFloat(u8"Current FOV", &MenuPlayerCRC.currentFov, 0, 300.f);
            ImGui::SliderFloat(u8"FOV Velocity", &MenuPlayerCRC.fovVelocity, 0, 300.f);
            ImGui::Checkbox(u8"Enable Fading", &MenuPlayerCRC.enableFading);
            ImGui::SliderFloat(u8"Start Fade Distance", &MenuPlayerCRC.fadeStartDistance, 0, 300.f);
            ImGui::SliderFloat(u8"End Fade Distance", &MenuPlayerCRC.fadeEndDistance, 0, 3000.f);
            ImGui::Checkbox(u8"Disable Spectating", &MenuPlayerCRC.disableSpectating);
            ImGui::SliderFloat(u8"Max Aim Raycast Distance", &MenuPlayerCRC.maxAimRaycastDistance, 500.f, 30000.f);
            ImGui::Checkbox(u8"Write in PitchYaw", &bWriteInPY);
            ImGui::SliderFloat(u8"Pitch", &MenuPlayerCRC.pitch, -70.f, 70.f);
            ImGui::SliderFloat(u8"Yaw", &MenuPlayerCRC.yaw, 0.f, 180.f);
            ImGui::DragFloat3(u8"Crosshair World Position (only read)", &MenuPlayerCRC.crosshairWorldPosition.x, 3.f, -100.f, 360.f);
            ImGui::SliderFloat(u8"Current Camera Distance", &MenuPlayerCRC.currentCameraDistance, 0.f, 1000.f);
            ImGui::SliderFloat(u8"Camera Distance Velocity", &MenuPlayerCRC.cameraDistanceVelocity, -10.f, 1000.f);
            //ImGui::SliderFloat(u8"Hitmarker Alpha", &fHitmarkerAlpha, 0.f, 1000.f);
            //ImGui::SliderFloat(u8"Hitmarker Timer", &fHitmarkerTimer, 0.f, 1000.f);
            ImGui::End();
        }
        if (menuCharacterSettingsShow) // MenuPlayerCB
        {
            ImGui::Begin("CHARACTER SETTINGS WINDOW", &menuCharacterSettingsShow);
            ImGui::Checkbox("Write in field's", &bCharacterSettingsWrite);
            ImGui::SliderInt("Body Index", &MenuPlayerCB.bodyIndex, 0, 4);
            ImGui::Checkbox("Linked to master", &MenuPlayerCB.linkedToMaster);
            ImGui::Checkbox("Is Player Controlled", &MenuPlayerCB.isPlayerControlled);
            ImGui::Checkbox("Disabling HurtBoxes", &MenuPlayerCB.disablingHurtBoxes);
            ImGui::SliderInt("Previous Eqipment Index", &MenuPlayerCB.previousEquipmentIndex, 0, 5);
            ImGui::Checkbox("Has Effective Authority", &MenuPlayerCB.hasEffectiveAuthority);
            ImGui::Checkbox("Is Sprinting", &MenuPlayerCB._isSprinting);
            ImGui::SliderFloat("Out Of Combat Stopwatch", &MenuPlayerCB.outOfCombatStopwatch, 0.f, 999.f);
            ImGui::SliderFloat("Out Of Danger Stopwatch", &MenuPlayerCB.outOfDangerStopwatch, 0.f, 999.f);
            ImGui::Checkbox(" Out Of Combat", &MenuPlayerCB.outOfCombat);
            ImGui::Checkbox(" Out Of Danger", &MenuPlayerCB._outOfDanger);
            ImGui::SliderFloat3("PreviosPosition (Only Read)", &MenuPlayerCB.previousPosition.x, -180, 360);
            ImGui::SliderFloat("Not Moving Stopwatch", &MenuPlayerCB.notMovingStopwatch, 0.f, 999.f);
            ImGui::Checkbox(" Root Motion In Main State", &MenuPlayerCB.rootMotionInMainState);
            if (ImGui::TreeNode("Player's parameters "))
            {

                
                ImGui::SliderFloat("Main Root Speed", &MenuPlayerCB.mainRootSpeed, 0, 999.f);
                if (ImGui::TreeNode("Base parameters"))
                {


                    ImGui::SliderFloat("Base Max Health", &MenuPlayerCB.baseMaxHealth, 0, 999.f);
                    ImGui::SliderFloat("Base Regen", &MenuPlayerCB.baseRegen, 0, 999.f);
                    ImGui::SliderFloat("Base Max Regen", &MenuPlayerCB.regen, 0, 999.f);
                    ImGui::SliderFloat("Base Move Speed", &MenuPlayerCB.baseMoveSpeed, 0, 999.f);
                    ImGui::SliderFloat("Base Acceleration", &MenuPlayerCB.baseAcceleration, 0, 999.f);
                    ImGui::SliderFloat("Base Jump Power", &MenuPlayerCB.baseJumpPower, 0, 999.f);
                    ImGui::SliderFloat("Base Damage", &MenuPlayerCB.baseDamage, 0, 999.f);
                    ImGui::SliderFloat("Base Attack Speed", &MenuPlayerCB.baseAttackSpeed, 0, 999.f);
                    ImGui::SliderFloat("Base Crit Chance", &MenuPlayerCB.baseCrit, 0, 100.f);
                    ImGui::SliderFloat("Base Armor", &MenuPlayerCB.baseArmor, 0, 999.f);
                    ImGui::SliderFloat("Base Jump Count", &MenuPlayerCB.baseJumpCount, 0, 999.f);
                    ImGui::TreePop();
                };
                if (ImGui::TreeNode("Level Parameters"))
                {
                    ImGui::SliderFloat("Sprinting Speed Multiplier", &MenuPlayerCB.sprintingSpeedMultiplier, 0, 999.f);
                    ImGui::SliderFloat("Auto Calculate Level Stats", &MenuPlayerCB.autoCalculateLevelStats, 0, 999.f);
                    ImGui::SliderFloat("Level Max Health", &MenuPlayerCB.levelMaxHealth, 0, 999.f);
                    ImGui::SliderFloat("Level Regen", &MenuPlayerCB.levelRegen, 0, 999.f);
                    ImGui::SliderFloat("Level Max Shield", &MenuPlayerCB.levelMaxShield, 0, 999.f);
                    ImGui::SliderFloat("Level Move Speed", &MenuPlayerCB.levelMoveSpeed, 0, 999.f);
                    ImGui::SliderFloat("Level Jump Power", &MenuPlayerCB.levelJumpPower, 0, 999.f);
                    ImGui::SliderFloat("Level Damage", &MenuPlayerCB.levelDamage, 0, 999.f);
                    ImGui::SliderFloat("Level Attack Speed", &MenuPlayerCB.levelAttackSpeed, 0, 999.f);
                    ImGui::SliderFloat("Level Crit Chance", &MenuPlayerCB.levelCrit, 0, 999.f);
                    ImGui::SliderFloat("Level Armor", &MenuPlayerCB.levelArmor, 0, 999.f);
                    ImGui::SliderFloat("Level Experience", &MenuPlayerCB.experience, 0, 999.f);
                    ImGui::SliderFloat("Level", &MenuPlayerCB.level, 0, 999.f);
                    ImGui::TreePop();
                };
                if (ImGui::TreeNode("Current parameters"))
                {
                    ImGui::SliderFloat("Max Health", &MenuPlayerCB.maxhealth, 0, 999.f);
                    ImGui::SliderFloat("Max Barrier", &MenuPlayerCB.maxBarrier, 0, 999.f);
                    ImGui::SliderFloat("Barrier Decay Rate", &MenuPlayerCB.barrierDecayRate, 0, 999.f);
                    ImGui::SliderFloat("Regen", &MenuPlayerCB.regen, 0, 999.f);
                    ImGui::SliderFloat("MaxShield", &MenuPlayerCB.maxShield, 0, 999.f);
                    ImGui::SliderFloat("Move Speed", &MenuPlayerCB.moveSpeed, 0, 999.f);
                    ImGui::SliderFloat("Acceleration", &MenuPlayerCB.acceleration, 0, 999.f);
                    ImGui::SliderFloat("JumpPower", &MenuPlayerCB.jumpPower, 0, 999.f);
                    ImGui::SliderInt("Max Jump Count", &MenuPlayerCB.maxJumpCoun, 0, 999);
                    ImGui::SliderFloat("Max Jump Height", &MenuPlayerCB.maxJumpHeight, 0, 999);
                    ImGui::SliderFloat("Damage", &MenuPlayerCB.damage, 0, 999);
                    ImGui::SliderFloat("AttackSpeed", &MenuPlayerCB.attackSpeed, 0, 999);
                    ImGui::SliderFloat("Crit Chance", &MenuPlayerCB.crit, 0, 999);
                    ImGui::SliderFloat("Armor", &MenuPlayerCB.armor, 0, 999);
                    ImGui::SliderFloat("Crit Heal", &MenuPlayerCB.critHeal, 0, 999);
                    ImGui::SliderFloat("Curse Penalty", &MenuPlayerCB.cursePenalty, 0, 999);
                    ImGui::Checkbox("Has One Shot Protection", &MenuPlayerCB.hasOneShotProtection);
                    ImGui::Checkbox("Is Glass", &MenuPlayerCB.isGlass);
                    ImGui::SliderFloat("One Shot Protection Fraction", &MenuPlayerCB.oneShotProtectionFraction, 0, 999);
                    ImGui::Checkbox("Stats Dirty", &MenuPlayerCB.statsDirty);
                    ImGui::SliderFloat("Aim Timer", &MenuPlayerCB.aimTimer, 0, 999);
                    ImGui::SliderFloat("WarCry Timer", &MenuPlayerCB.warCryTimer, 0, 999);
                    ImGui::Checkbox("WarCry Ready", &MenuPlayerCB._warCryReady);
                    ImGui::SliderInt("Kill Count", &MenuPlayerCB.killCount, 0, 999);
                    ImGui::SliderFloat("Tesla Buff Roll Timer", &MenuPlayerCB.teslaBuffRollTimer, 0, 999);
                    ImGui::SliderFloat("Tesla Fire Timer", &MenuPlayerCB.teslaFireTimer, 0, 999);
                    ImGui::SliderFloat("Tesla Reset List Timer", &MenuPlayerCB.teslaResetListTimer, 0, 999);
                    ImGui::SliderFloat("Tesla Reset List Interval", &MenuPlayerCB.teslaResetListInterval, 0, 999);
                    ImGui::Checkbox("Tesla Crit", &MenuPlayerCB.teslaCrit);
                    ImGui::SliderFloat("Hellfire Life Time", &MenuPlayerCB.helfireLifetime, 0, 999);
                    ImGui::Checkbox("Was Lucky", &MenuPlayerCB.wasLucky);
                    ImGui::Checkbox("Guard Resummon Cooldown", &MenuPlayerCB.guardResummonCooldown);
                    ImGui::SliderFloat("Poisonball Timer", &MenuPlayerCB.poisonballTimer, 0, 999);
                    ImGui::SliderFloat("Ward Resummon Cooldown", &MenuPlayerCB.wardResummonCooldown, 0, 999);
                    ImGui::SliderFloat("Spread Bloom Decay Time", &MenuPlayerCB.spreadBloomDecayTime, 0, 999);
                    ImGui::SliderFloat("Spread Bloom Internal", &MenuPlayerCB.spreadBloomInternal, 0, 999);
                    ImGui::Checkbox("Hide Crosshair", &MenuPlayerCB.hideCrosshair);
                    ImGui::SliderFloat("Milti Kill Timer", &MenuPlayerCB.multiKillTimer, 0, 999);
                    ImGui::SliderInt("MultiKillCount", &MenuPlayerCB.multiKillCount, 0, 999);
                    ImGui::SliderFloat("Radius", &MenuPlayerCB.radius, 0, 999);
                    ImGui::Checkbox("Is Champion", &MenuPlayerCB.isChampion);
                    ImGui::Checkbox("Is Elite", &MenuPlayerCB.isElite);
                    ImGui::SliderInt("Skin Index", &MenuPlayerCB.skinIndex, 0, 999);
                    ImGui::SliderInt("Local Start Time", &MenuPlayerCB.localStartTime, 0, 999);
                    ImGui::TreePop();
                }






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
	if (menuMainShow || menuCameraSettingsShow || menuCharacterSettingsShow) // если вызывается хендлер
	{
		ImGui_ImplWin32_WndProcHandler(hwnd, uMsg, wParam, lParam);
	}
	return CallWindowProc(oWndProc, hwnd, uMsg, wParam, lParam); // если же нет, вызываем оригинальный процесс
}