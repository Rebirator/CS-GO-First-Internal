#include "Aimbot.hpp"
#include "..\SDK\C_Entity.hpp"
#include "..\SDK\C_Weapon.hpp"
#include "..\Utils\Vector3.hpp"
#include "..\SDK\C_Client.hpp"

void F_Aimbot::Aimbot( ) {
	if ( GetAsyncKeyState( VK_RBUTTON ) ) {
		C_Entity* entity = C_Entity::G( ).GetClosestEntity( );

		if ( !entity->IsAlive( ) || entity->GetTeam( ) == g_pLocalEntity->GetTeam( ) )
			return;

		Vector3 aim_angles = g_Vector3->CalculateAngles( g_pLocalEntity->GetPosition( ), entity->GetPosition( ) );
		Vector3 diff_smoothed = ( aim_angles - g_Client->GetViewAngles( ) ) / 40;

		g_Client->SetViewAngles( 
			g_Vector3->NormalizeAngles( 
				Vector3( 
					g_Client->GetViewAngles( ).x + diff_smoothed.x, g_Client->GetViewAngles( ).y + diff_smoothed.y, 0.0f 
				) 
			) 
		);
	}
}
