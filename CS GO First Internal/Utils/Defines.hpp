#ifndef __DEFINES__
#define __DEFINES__

#define g_LocalPlayer		g_Game::ClientDll + g_Game::Signatures::dwLocalPlayer
#define g_pLocalPlayer		*reinterpret_cast< uintptr_t* >( g_Game::ClientDll + g_Game::Signatures::dwLocalPlayer )
#define g_pLocalEntity		g_entity.Get( g_LocalPlayer )
#define g_pLocalWeapon		g_weapon.GetWeapon( g_pLocalPlayer )

#define PI 3.14159265358
#define CS_INCH_TO_METERS( a ) ( ( float )( a * 0.0254f ) )

#define KEY_TOGGLE 1
#define KEY_UNHOLD 0
#define KEY_HOLD   -32768

#endif//__DEFINES__
