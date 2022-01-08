#ifndef __SDK_DIRECTX_D3DX9_HPP__
#define __SDK_DIRECTX_D3DX9_HPP__

#include <d3d9.h>
#include <d3dx9.h>

#pragma comment( lib, "d3d9.lib" )
#pragma comment( lib, "d3dx9.lib" )

extern void* D3D9Device[ 119 ];
extern LPDIRECT3DDEVICE9 g_DirectDevice;

bool GetD3D9Device( void** table, size_t size );

static HWND g_hwndWindow = 0;
       HWND GetProcessWindow( );

#endif  __SDK_DIRECTX_D3DX9_HPP__
