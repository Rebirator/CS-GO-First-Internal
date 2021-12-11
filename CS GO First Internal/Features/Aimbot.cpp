#include "Aimbot.hpp"
#include "..\SDK\C_Entity.hpp"
#include "..\SDK\C_Weapon.hpp"
#include "..\Utils\Vector3.hpp"
#include "..\SDK\C_Client.hpp"

F_Aimbot g_aimbot { };

void F_Aimbot::Aimbot( ) {
	if ( GetAsyncKeyState( VK_RBUTTON ) ) {
		C_Entity* entity = g_entity.GetClosestEntity( );

		if ( !entity->IsAlive( ) || entity->GetTeam( ) == g_pLocalEntity->GetTeam( ) )
			return;

		Vector3 aim_angles = g_vector3.CalculateAngles( g_pLocalEntity->GetPosition( ), entity->GetPosition( ) );
		Vector3 diff_smoothed = ( aim_angles - g_client.GetViewAngles( ) ) / 40;

		g_client.SetViewAngles( 
			g_vector3.NormalizeAngles( 
				Vector3( 
					g_client.GetViewAngles( ).x + diff_smoothed.x, g_client.GetViewAngles( ).y + diff_smoothed.y, 0.0f 
				) 
			) 
		);
	}
}
