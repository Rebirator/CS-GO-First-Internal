#include "TriggerBot.hpp"
#include "..\SDK\C_Entity.hpp"
#include "..\SDK\C_Weapon.hpp"
#include "..\Utils\Vector.hpp"

void TriggerBot_t::TriggerBot( ) {
	C_Entity* Entity = C_Entity::G( ).GetByCrosshairID( );

	if ( Entity && Entity->GetHealth( ) > 0 ) {
		Vector3_t Distance;
		Sleep( ( DWORD )Distance.Distance( g_pLocalEntity->GetPosition( ), Entity->GetPosition( ) ) * 5 );

		g_pLocalEntity->DoAttack1( );
	}
}