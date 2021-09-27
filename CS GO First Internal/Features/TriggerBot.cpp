#include "TriggerBot.hpp"
#include "..\SDK\C_Entity.hpp"
#include "..\SDK\C_Weapon.hpp"
#include "..\Utils\Vector3.hpp"
#include "..\SDK\C_Client.hpp"
#include <thread>

void F_TriggerBot::TriggerBot( ) {
	C_Entity* Entity = C_Entity::G( ).GetByCrosshairID( );

	if ( Entity->IsAlive( ) && Entity->GetTeam( ) != g_pLocalEntity->GetTeam( ) ) {
		std::chrono::microseconds( ( DWORD )g_Vector3->Distance( g_pLocalEntity->GetPosition( ), Entity->GetPosition( ) ) * 5 );

		g_Client->DoAttack1( );
	}
}
