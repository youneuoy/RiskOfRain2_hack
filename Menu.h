#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <iostream>
#include "d3d11draw/rD3D11.h"
#include "d3d11draw/pch.h"
#include "imgui/imgui_impl_dx11.h"
#include "imgui/imgui_impl_win32.h"
#include "sdk.h"
template <typename T>
T* SetPointerTo(T*& _where,uintptr_t baseaddr, std::vector<uintptr_t>& vec);
bool bCheatInit = false;
bool bInGame = false;
bool bKillByCoursor = false;
bool bInit = false;
bool initialized_imgui = false;
bool menuShow = false;
bool PlayerSettings = false;

ImGuiContext* context = 0;
WNDPROC		oWndProc = NULL;																		// текущий хендл процесса
HWND		window1 = NULL;
typedef LRESULT(CALLBACK* WNDPROC)(HWND, UINT, WPARAM, LPARAM);
extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

void InitImgui(ID3D11Device* device, ID3D11DeviceContext* device_context);
void MenuMainFunc(ID3D11Device* device, ID3D11DeviceContext* device_context);
LRESULT __stdcall WndProc(const HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

