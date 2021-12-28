#include "TriggerBot.hpp"
#include "..\SDK\C_Entity.hpp"
#include "..\SDK\C_Weapon.hpp"
#include "..\Utils\Vector3.hpp"
#include "..\SDK\C_Client.hpp"
#include <thread>

C_TriggerBot g_triggerbot { };

void C_TriggerBot::TriggerBot( ) {
	C_Entity* entity = g_entity.GetByCrosshairID( );

	if ( entity->IsAlive( ) && entity->GetTeam( ) != g_pLocalEntity->GetTeam( ) ) {
		DWORD distance = DWORD( g_vector3.Distance( g_pLocalEntity->GetPosition( ), entity->GetPosition( ) ) * 8 );
		std::this_thread::sleep_for( std::chrono::milliseconds( distance ) );

		g_client.DoAttack1( );
	}
}
