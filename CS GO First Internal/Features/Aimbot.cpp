#include "Aimbot.hpp"
#include "..\SDK\CSGO\Cheat\CEntityPlayer.hpp"
#include "..\Utils\DataTypes\Vector3.hpp"
#include "..\SDK\C_Client.hpp"

C_Aimbot g_aimbot { };

void C_Aimbot::Aimbot( ) {
	if ( GetAsyncKeyState( VK_RBUTTON ) ) {
		CEntityPlayer* entity = g_entity.GetClosestEntity( );

		if ( !entity->Alive( ) || entity->Team( ) == g_pLocalEntity->Team( ) )
			return;

		Vector3 aim_angles = g_pLocalEntity->GetPosition( ).CalculateAngles( entity->GetPosition( ) );
		Vector3 diff_smoothed = ( aim_angles - g_client.GetViewAngles( ) ) / 40;

		Vector3 viewangles( g_client.GetViewAngles( ) + diff_smoothed );
		g_client.SetViewAngles( viewangles.NormalizeAngles( ) );
	}
}
