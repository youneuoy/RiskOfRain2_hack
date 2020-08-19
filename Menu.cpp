#include "Menu.h"
extern void InitializeVars();


void InitImgui(ID3D11Device* device, ID3D11DeviceContext* device_context)
{
	rD3D11 d3d11;
	ImGui::CreateContext();
	
	window1 = FindMainWindow(GetCurrentProcessId());
	/*oWndProc = (WNDPROC)SetWindowLongPtr(window1, GWL_WNDPROC, (LONG_PTR)WndProc);*/
	oWndProc = (WNDPROC)SetWindowLongPtr(window1, -4, (LONG_PTR)WndProc);
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	io.IniFilename = NULL;
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
	io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\Arial.ttf", 10.5f, NULL, io.Fonts->GetGlyphRangesCyrillic());
	
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

		if (menuShow)
		{
			ImGui::Begin(u8"Risk Of Rain 2 Trainer (gamehacklab.ru)", &menuShow, ImGuiWindowFlags_MenuBar);
			ImGui::Text(u8"by KRYPTOPUNK");
			ImGui::Text(u8"Настройки чита");
			ImGui::Checkbox(u8"В игре", &bInGame);
			if (ImGui::TreeNode(u8"Настройки персонажа"))
			{
				ImGui::Checkbox(u8"Убийство Курсором", &bKillByCoursor);
				ImGui::TreePop();
			};
			
			ImGui::End();
		}


		ImGui::EndFrame();
		ImGui::Render();
		ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
	}
}
LRESULT __stdcall WndProc(const HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	if (menuShow) // если вызывается хендлер
	{
		ImGui_ImplWin32_WndProcHandler(hwnd, uMsg, wParam, lParam);
	}
	return CallWindowProc(oWndProc, hwnd, uMsg, wParam, lParam); // если же нет, вызываем оригинальный процесс
}