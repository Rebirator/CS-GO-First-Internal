#include <iostream>
#include "TriggerBot.hpp"
#include "..\SDK\Entity.hpp"
#include "..\Utils\Vector.hpp"

void TriggerBot_t::TriggerBot( ) {
	if ( g_pLocalPlayer->GetCrosshairEntityID( ) ) {
		if ( g_pLocalPlayer->GetCrosshairEntityID( ) > 0 && g_pLocalPlayer->GetCrosshairEntityID( ) <= 64 ) {
			Entity_t* Entity = Entity_t::Get( ).GetEntityByID( g_pLocalPlayer->GetCrosshairEntityID( ) );

			Vector3 LocalPos = g_pLocalPlayer->GetPosition( );
			Vector3 EntityPos = Entity->GetPosition( );

			float Distance = abs( LocalPos.x - EntityPos.x + LocalPos.y - EntityPos.y + LocalPos.z - EntityPos.z ) * 0.0254f;

			if ( Entity && Entity->GetHealth( ) > 0 ) {
				Sleep( ( int )Distance * 5 );
				g_pLocalPlayer->DoAttack1( );
			}
		}
	}
}