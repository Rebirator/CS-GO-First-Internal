#include "TriggerBot.hpp"
#include "..\SDK\C_Entity.hpp"
#include "..\SDK\C_Weapon.hpp"
#include "..\Utils\Vector3.hpp"
#include "..\SDK\C_Client.hpp"

F_TriggerBot g_triggerbot { };

void F_TriggerBot::TriggerBot( ) {
	C_Entity* entity = g_entity.GetByCrosshairID( );

	if ( entity->IsAlive( ) && entity->GetTeam( ) != g_pLocalEntity->GetTeam( ) ) {
		//std::this_thread::sleep_for( std::chrono::milliseconds( ( DWORD )g_Vector3->Distance( g_pLocalEntity->GetPosition( ), entity->GetPosition( ) ) * 5 ) );

		g_client.DoAttack1( );
	}
}
