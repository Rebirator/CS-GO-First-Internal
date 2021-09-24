#include "Misc.hpp"
#include "..\SDK\C_Entity.hpp"
#include "..\SDK\C_Client.hpp"

void F_Misc::BunnyHop( ) {
	if ( GetAsyncKeyState( VK_SPACE ) ) {
 		if ( g_pLocalEntity->GetFlags( ) & ( 1 << 0 ) ) {
			g_pLocalEntity->DoJump( );
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
