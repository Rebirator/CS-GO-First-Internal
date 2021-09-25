#include "Misc.hpp"
#include "..\SDK\C_Entity.hpp"
#include "..\SDK\C_Client.hpp"
#include <iostream>

void F_Misc::BunnyHop( ) {
	if ( GetAsyncKeyState( VK_SPACE ) ) {
 		if ( g_pLocalEntity->GetFlags( ) & ( 1 << 0 ) ) {
			g_Client->DoJump( );
		}
	}
}

void F_Misc::RadarHack( ) {
	for ( short i = 1; i < g_Client->GetMaxClients( ); i++ ) {
		C_Entity* Entity = C_Entity::G( ).GetByID( i );

		if ( Entity && !Entity->IsSpotted( ) && Entity->GetTeam( ) != g_pLocalEntity->GetTeam( ) ) {
			Entity->SetSpotted( true );
		}
	}
}

void F_Misc::RecoilControlSystem( ) {
	Vector3 PunchAngle = g_pLocalEntity->GetAimPunch( ) * 2.1f;

	if ( g_pLocalEntity->GetShotsFired( ) > 1 ) {
		Vector3 NewAngle = Vector3( g_Client->GetViewAngles( ).x + OldPunch.x - PunchAngle.x, g_Client->GetViewAngles( ).y + OldPunch.y - PunchAngle.y, 0.0f );

		NewAngle.Normalize( );

		g_Client->SetViewAngles( NewAngle );
	}
	OldPunch = PunchAngle;
}
