#include "hkEndScene.hpp"
#include "..\Hooks.hpp"
#include "..\..\..\SDK\DirectX\Render.hpp"
#include "..\..\..\SDK\DirectX\Imgui\imgui.h"
#include "..\..\..\SDK\DirectX\Imgui\Backend\imgui_impl_dx9.h"
#include "..\..\..\SDK\DirectX\Imgui\Backend\imgui_impl_win32.h"

#include "..\..\..\Gui\Menu.hpp"

Hook        EndScene;
EndSceneFn  oEndScene;
WNDPROC     oWndProc;

static HWND g_CSGOWindow;
bool        g_bImGuiInitialized;
bool        g_bImGuiUnloaded;
bool        g_bMenuOpened;

HRESULT WINAPI hkEndScene( LPDIRECT3DDEVICE9 device ) {
    if ( g_DirectDevice == nullptr )
        g_DirectDevice = device;

    if ( !g_bImGuiInitialized )
        ImGuiInit( device );

    if ( GetAsyncKeyState( VK_INSERT ) & 0x1 )
        g_bMenuOpened = !g_bMenuOpened;

    //
    g_Render::FilledRect( 100, 100, 150, 150, Color( 255, 255, 255, 255 ) );

    if ( !g_bImGuiUnloaded ) {
        ImGui_ImplDX9_NewFrame( );
        ImGui_ImplWin32_NewFrame( );
        ImGui::NewFrame( );

        if ( g_bMenuOpened ) {
            g_Menu.Render( );
        }

        ImGui::EndFrame( );
        ImGui::Render( );
        ImGui_ImplDX9_RenderDrawData( ImGui::GetDrawData( ) );
    }

    return oEndScene( device );
}

LRESULT CALLBACK WndProc( const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam ) {
    if ( g_bMenuOpened && ImGui_ImplWin32_WndProcHandler( hWnd, uMsg, wParam, lParam ) )
        return true;

    return CallWindowProcA( oWndProc, hWnd, uMsg, wParam, lParam );
}

void ImGuiInit( LPDIRECT3DDEVICE9 device ) {
    ImGui::CreateContext( );
    ImGui::StyleColorsDark( );
    ImGui_ImplWin32_Init( g_CSGOWindow );
    ImGui_ImplDX9_Init( device );

    g_bImGuiInitialized = true;
}

void ImGuiRelease( ) {
    g_bImGuiUnloaded = true;

    ImGui_ImplDX9_Shutdown( );
    ImGui_ImplWin32_Shutdown( );
    ImGui::DestroyContext( );
}

void g_Hooks::EndSceneInit( ) {
    if ( GetD3D9Device( D3D9Device, sizeof( D3D9Device ) ) ) {
        g_CSGOWindow = FindWindowA( "Valve001", "Counter-Strike: Global Offensive - Direct3D 9" );
        oWndProc = reinterpret_cast< WNDPROC >( SetWindowLongPtrA( g_CSGOWindow, GWL_WNDPROC, reinterpret_cast< LONG_PTR >( WndProc ) ) );

        EndScene = Hook( ( BYTE* )D3D9Device[ 42 ], ( BYTE* )hkEndScene, ( BYTE* )&oEndScene, 7 );
        EndScene.Enable( );
    }
}

void g_Hooks::EndSceneRelease( ) {
    ImGuiRelease( );
    EndScene.Disable( );

    SetWindowLongPtr( g_CSGOWindow, GWLP_WNDPROC, reinterpret_cast< LONG_PTR >( oWndProc ) );
}
