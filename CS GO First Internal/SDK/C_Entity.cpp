#include "Offsets.hpp"
#include "C_Entity.hpp"
#include "C_Weapon.hpp"
#include "C_Client.hpp"

C_Entity g_entity { };

int C_Entity::GetHealth( ) {
	return *reinterpret_cast< int* >( this + g_Game::Netvars::m_iHealth );
}

int C_Entity::GetFlags( ) {
	return *reinterpret_cast< int* >( this + g_Game::Netvars::m_fFlags );
}

int C_Entity::GetTeam( ) {
	return *reinterpret_cast< int* >( this + g_Game::Netvars::m_iTeamNum );
}

int C_Entity::GetShotsFired( ) {
	return *reinterpret_cast< int* >( this + g_Game::Netvars::m_iShotsFired );
}

int C_Entity::GetCrosshairEntityID( ) {
	return *reinterpret_cast< int* >( this->Get( g_LocalPlayer ) + g_Game::Netvars::m_iCrosshairId );
}

Vector3 C_Entity::GetPosition( ) {
	return *reinterpret_cast< Vector3* >( this + g_Game::Netvars::m_vecOrigin );
}

Vector3 C_Entity::GetViewAngles( ) {
	return *reinterpret_cast< Vector3* >( this->Get( g_LocalPlayer ) + g_Game::Netvars::m_vecViewOffset );
}

Vector3 C_Entity::GetAimPunch( ) {
	return *reinterpret_cast< Vector3* >( this->Get( g_LocalPlayer ) + g_Game::Netvars::m_aimPunchAngle );
}

bool C_Entity::IsAlive( ) {
	if ( !this )
		return false;

	if ( this->GetHealth( ) > 0 && this->GetTeam( ) )
		return true;

	return false;
}

bool C_Entity::IsDormant( ) {
	return *reinterpret_cast< bool* >( this + g_Game::Signatures::m_bDormant );
}

bool C_Entity::IsSpotted( ) {
	return *reinterpret_cast< bool* >( this + g_Game::Netvars::m_bSpotted );
}

bool C_Entity::IsDefusing( ) {
	return *reinterpret_cast< bool* >( this + g_Game::Netvars::m_bIsDefusing );
}

void C_Entity::SetSpotted( bool value ) {
	*reinterpret_cast< bool* >( this + g_Game::Netvars::m_bSpotted ) = value;
}

C_Entity* C_Entity::GetByID( short entity_id ) {
	return *reinterpret_cast< C_Entity** >( g_Game::ClientDll + g_Game::Signatures::dwEntityList + ( entity_id * 0x10 ) );
}

C_Entity* C_Entity::GetByCrosshairID( ) {
	if ( this->GetCrosshairEntityID( ) > 0 && this->GetCrosshairEntityID( ) <= g_client.GetMaxClients( ) )
		return *reinterpret_cast< C_Entity** >( g_Game::ClientDll + g_Game::Signatures::dwEntityList +
											  ( ( this->GetCrosshairEntityID( ) - 1 ) * 0x10 ) );
	return nullptr;
}

C_Entity* C_Entity::GetClosestEntity( ) {
	float closest_distance = 0.0f;
	short closest_ent_id = NULL;

	for ( short i = 1; i < g_client.GetMaxClients( ); i++ ) {
		C_Entity* entity = this->GetByID( i );

		if ( !entity->IsAlive( ) )
			continue;

		if ( g_vector3.Distance( g_pLocalEntity->GetPosition( ), entity->GetPosition( ) ) < closest_distance || closest_distance == 0.0f ) {
			closest_distance = g_vector3.Distance( g_pLocalEntity->GetPosition( ), entity->GetPosition( ) );
			closest_ent_id = i;
		}
	}

	return this->GetByID( closest_ent_id );
}

C_Entity* C_Entity::Get( uintptr_t entity ) {
	return *reinterpret_cast< C_Entity** >( entity );
}

uintptr_t C_Entity::Get( ) {
	return reinterpret_cast< uintptr_t >( this );
}
