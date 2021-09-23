#include "TriggerBot.hpp"
#include "..\SDK\C_Entity.hpp"
#include "..\SDK\C_Weapon.hpp"
#include "..\Utils\Vector3.hpp"

void F_TriggerBot::TriggerBot( ) {
	C_Entity* Entity = C_Entity::G( ).GetByCrosshairID( );

	if ( Entity && Entity->GetHealth( ) > 0 && Entity->GetTeam( ) != g_pLocalEntity->GetTeam( ) ) {
		Sleep( ( DWORD )g_Vector3->Distance( g_pLocalEntity->GetPosition( ), Entity->GetPosition( ) ) * 5 );

		g_pLocalEntity->DoAttack1( );
	}
}
