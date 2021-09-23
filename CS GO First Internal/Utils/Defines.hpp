#ifndef __DEFINES__
#define __DEFINES__

#define uintptr			uintptr_t
#define DWINAPI			DWORD WINAPI

#define g_Client		C_Client::G( ).Get( )
#define g_GlowManager	C_GlowManager::G( ).Get( )
#define g_Vector3		Vector3::pG( )

#define g_LocalPlayer   g_Game::ClientDll + g_Game::Signatures::dwLocalPlayer
#define g_pLocalPlayer  *reinterpret_cast< uintptr* >( g_Game::ClientDll + g_Game::Signatures::dwLocalPlayer )
#define g_pLocalEntity	C_Entity::G( ).Get( g_LocalPlayer )
#define g_pLocalWeapon	C_Weapon::G( ).GetWeapon( g_pLocalPlayer )

#define CS_INCH_TO_METERS( a ) ( ( float )( a * 0.0254f ) )

#define KEY_TOGGLE 1
#define KEY_UNHOLD 0
#define KEY_HOLD   -32768

#endif//__DEFINES__
