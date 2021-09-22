#ifndef __DEFINES__
#define __DEFINES__

#define uintptr			uintptr_t
#define g_LocalPlayer   *reinterpret_cast< uintptr* >( g_Game::ClientDll + g_Game::g_Signatures::dwLocalPlayer )
#define g_Client		C_Client::G( ).Get( )
#define g_pLocalEntity	C_Entity::G( ).GetLocalPlayer( )
#define g_pLocalWeapon	C_Weapon::G( ).GetLocalPlayer( )
#define CS_INCH_TO_METERS( a ) ( ( float )( a * 0.0254f ) )

#define KEY_TOGGLE 1
#define KEY_UNHOLD 0
#define KEY_HOLD   -32768

#endif//__DEFINES__
