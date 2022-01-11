#include <Windows.h>
#include "Misc.hpp"
#include "..\SDK\CSGO\Cheat\CEntityPlayer.hpp"
#include "..\SDK\C_Client.hpp"
#include <iostream>
#include <Psapi.h>
#include <vector>

C_Misc g_misc { };

void C_Misc::BunnyHop( ) {
	if ( GetAsyncKeyState( VK_SPACE ) ) {
		if ( g_pLocalEntity->Flags( ) & ( 1 << 0 ) ) {
			g_client.DoJump( );
		}
	}
}

void C_Misc::RadarHack( ) {
	for ( short i = 1; i < g_client.GetMaxClients( ); i++ ) {
		CEntityPlayer* entity = g_entity.GetByID( i );

		if ( entity && !entity->Spotted( ) && entity->Team( ) != g_pLocalEntity->Team( ) ) {
			entity->SetSpotted( true );
		}
	}
}

void C_Misc::RecoilControlSystem( ) {
	static Vector3 old_punch;
	Vector3 punch_angle = g_pLocalEntity->AimPunch( ) * 2.1f;

	if ( g_pLocalEntity->ShotsFired( ) > 1 ) {
		Vector3 new_viewangles = g_client.GetViewAngles( ) + old_punch - punch_angle;
		g_client.SetViewAngles( new_viewangles.NormalizeAngles( ) );
	}

	old_punch = punch_angle;
}
