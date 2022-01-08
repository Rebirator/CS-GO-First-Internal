#include "TriggerBot.hpp"
#include "..\SDK\CSGO\Cheat\CEntityPlayer.hpp"
#include "..\Utils\DataTypes\Vector3.hpp"
#include "..\SDK\C_Client.hpp"
#include <thread>

C_TriggerBot g_triggerbot { };

void C_TriggerBot::TriggerBot( ) {
	CEntityPlayer* entity = g_entity.GetByCrosshairID( );

	if ( entity->Alive( ) && entity->Team( ) != g_pLocalEntity->Team( ) ) {
		//DWORD distance = DWORD( g_vector3.Distance( g_pLocalEntity->GetPosition( ), entity->GetPosition( ) ) * 8 );
		//std::this_thread::sleep_for( std::chrono::milliseconds( distance ) );

		g_client.DoAttack1( );
	}
}
