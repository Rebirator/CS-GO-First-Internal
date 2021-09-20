#include <iostream>
#include "TriggerBot.hpp"
#include "..\SDK\Entity.hpp"
#include "..\Utils\Vector.hpp"

void TriggerBot_t::TriggerBot( ) {
	if ( g_pLocalPlayer->GetCrosshairEntityID( ) ) {
		if ( g_pLocalPlayer->GetCrosshairEntityID( ) > 0 && g_pLocalPlayer->GetCrosshairEntityID( ) <= 64 ) {
			Entity_t* Entity = Entity_t::Get( ).GetEntityByID( g_pLocalPlayer->GetCrosshairEntityID( ) );

			Vector3_t Distance;

			if ( Entity && Entity->GetHealth( ) > 0 ) {
				Sleep( Distance.Distance( g_pLocalPlayer->GetPosition( ), Entity->GetPosition( ) ) * 5 );
				g_pLocalPlayer->DoAttack1( );
			}
		}
	}
}