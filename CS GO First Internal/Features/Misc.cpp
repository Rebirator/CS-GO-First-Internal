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
		C_Entity* entity = C_Entity::G( ).GetByID( i );

		if ( entity && !entity->IsSpotted( ) && entity->GetTeam( ) != g_pLocalEntity->GetTeam( ) ) {
			entity->SetSpotted( true );
		}
	}
}

void F_Misc::RecoilControlSystem( ) {
	static Vector3 old_punch;
	Vector3 punch_angle = g_pLocalEntity->GetAimPunch( ) * 2.1f;

	if ( g_pLocalEntity->GetShotsFired( ) > 1 ) {
		g_Client->SetViewAngles( 
			g_Vector3->NormalizeAngles( 
				Vector3( 
					g_Client->GetViewAngles( ).x + old_punch.x - punch_angle.x, g_Client->GetViewAngles( ).y + old_punch.y - punch_angle.y, 0.0f 
				) 
			) 
		);
	}

	old_punch = punch_angle;
}
