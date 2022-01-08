#ifndef __CORE_TARGETS_HKENDSCENE_HPP__
#define __CORE_TARGETS_HKENDSCENE_HPP__

#include "..\..\..\SDK\DirectX\D3DX9.hpp"

using EndSceneFn = HRESULT( APIENTRY* )( LPDIRECT3DDEVICE9 device );

void InitEndScene( );
void DeinitEndScene( );

#endif  __CORE_TARGETS_HKENDSCENE_HPP__
