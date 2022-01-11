#ifndef __CORE_TARGETS_HKENDSCENE_HPP__
#define __CORE_TARGETS_HKENDSCENE_HPP__

#include "..\..\..\SDK\DirectX\D3DX9.hpp"

using EndSceneFn = HRESULT( WINAPI* )( LPDIRECT3DDEVICE9 device );
extern LRESULT ImGui_ImplWin32_WndProcHandler( HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam );

void ImGuiInit( LPDIRECT3DDEVICE9 device );
void ImGuiRelease( );

namespace g_Hooks {
    void EndSceneInit( );
    void EndSceneRelease( );
}

#endif  __CORE_TARGETS_HKENDSCENE_HPP__
