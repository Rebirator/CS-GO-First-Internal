#include "Aimbot.hpp"
#include "..\SDK\C_Entity.hpp"
#include "..\SDK\C_Weapon.hpp"
#include "..\Utils\Vector3.hpp"
#include "..\SDK\C_Client.hpp"

void F_Aimbot::Aimbot( ) {
	if ( GetAsyncKeyState( VK_RBUTTON ) ) {
		C_Entity* Entity = C_Entity::G( ).GetClosestEntity( );

		if ( !Entity->IsAlive( ) || Entity->GetTeam( ) == g_pLocalEntity->GetTeam( ) )
			return;

		Vector3 LocalPos = g_pLocalEntity->GetPosition( );
		Vector3 EnemyPos = Entity->GetPosition( );

		Vector3 AimAngles = g_Vector3->CalculateAngles( LocalPos, EnemyPos );
		Vector3 DiffAimAngles = AimAngles - g_Client->GetViewAngles( );
		Vector3 DiffAimAnglesSmoothed = DiffAimAngles / 40;
		Vector3 NewAngles = Vector3( g_Client->GetViewAngles( ).x + DiffAimAnglesSmoothed.x, g_Client->GetViewAngles( ).y + DiffAimAnglesSmoothed.y, 0.0f );

		NewAngles.NormalizeAngles( );

		g_Client->SetViewAngles( NewAngles );
	}
}
