#include "hkEndScene.hpp"
#include "..\Hooks.hpp"
#include "..\..\..\SDK\DirectX\Render.hpp"

Hook              EndScene;
EndSceneFn        oEndScene = nullptr;

void APIENTRY hkEndScene( LPDIRECT3DDEVICE9 device ) {
    if ( g_DirectDevice == nullptr )
        g_DirectDevice = device;

    g_Render::FilledRect( 100, 100, 150, 150, Color( 255, 255, 255, 255 ) );

    oEndScene( g_DirectDevice );
}

void InitEndScene( ) {
    if ( GetD3D9Device( D3D9Device, sizeof( D3D9Device ) ) ) {
        EndScene = Hook( ( BYTE* )D3D9Device[ 42 ], ( BYTE* )hkEndScene, ( BYTE* )&oEndScene, 7 );
        EndScene.Enable( );
    }
}

void DeinitEndScene( ) {
    EndScene.Disable( );
}
