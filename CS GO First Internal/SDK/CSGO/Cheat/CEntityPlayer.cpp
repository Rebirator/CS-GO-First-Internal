#include "..\..\Offsets.hpp"
#include "CEntityPlayer.hpp"
#include "..\..\C_Client.hpp"

CEntityPlayer g_entity { };

bool CEntityPlayer::Alive( ) {
	if ( !this )
		return false;

	if ( this->Health( ) > 0 && this->Team( ) )
		return true;

	return false;
}

int CEntityPlayer::GetCrosshairEntityID( ) {
	return *reinterpret_cast< int* >( this->Get( g_LocalPlayer ) + g_Game::Netvars::m_iCrosshairId );
}

Vector3 CEntityPlayer::GetPosition( ) {
	return *reinterpret_cast< Vector3* >( this + g_Game::Netvars::m_vecOrigin );
}

Vector3 CEntityPlayer::GetViewAngles( ) {
	return *reinterpret_cast< Vector3* >( this->Get( g_LocalPlayer ) + g_Game::Netvars::m_vecViewOffset );
}

Vector3 CEntityPlayer::GetAimPunch( ) {
	return *reinterpret_cast< Vector3* >( this->Get( g_LocalPlayer ) + g_Game::Netvars::m_aimPunchAngle );
}

bool CEntityPlayer::IsDormant( ) {
	return *reinterpret_cast< bool* >( this + g_Game::Signatures::m_bDormant );
}

bool CEntityPlayer::IsSpotted( ) {
	return *reinterpret_cast< bool* >( this + g_Game::Netvars::m_bSpotted );
}

bool CEntityPlayer::IsDefusing( ) {
	return *reinterpret_cast< bool* >( this + g_Game::Netvars::m_bIsDefusing );
}

void CEntityPlayer::SetSpotted( bool value ) {
	*reinterpret_cast< bool* >( this + g_Game::Netvars::m_bSpotted ) = value;
}

CEntityPlayer* CEntityPlayer::GetByID( short entity_id ) {
	return *reinterpret_cast< CEntityPlayer** >( g_Game::ClientDll + g_Game::Signatures::dwEntityList + ( entity_id * 0x10 ) );
}

CEntityPlayer* CEntityPlayer::GetByCrosshairID( ) {
	if ( this->GetCrosshairEntityID( ) > 0 && this->GetCrosshairEntityID( ) <= g_client.GetMaxClients( ) )
		return *reinterpret_cast< CEntityPlayer** >( g_Game::ClientDll + g_Game::Signatures::dwEntityList +
											  ( ( this->GetCrosshairEntityID( ) - 1 ) * 0x10 ) );
	return nullptr;
}

CEntityPlayer* CEntityPlayer::GetClosestEntity( ) {
	float closest_distance = 0.0f;
	short closest_ent_id = NULL;

	for ( short i = 1; i < g_client.GetMaxClients( ); i++ ) {
		CEntityPlayer* entity = this->GetByID( i );

		if ( !entity->Alive( ) )
			continue;

		if ( g_pLocalEntity->GetPosition( ).DistanceMeters( entity->GetPosition( ) ) < 5 || closest_distance == 0.0f ) {
			closest_distance = g_pLocalEntity->GetPosition( ).DistanceMeters( entity->GetPosition( ) );
			closest_ent_id = i;
		}
	}

	return this->GetByID( closest_ent_id );
}

CEntityPlayer* CEntityPlayer::Get( uintptr_t entity ) {
	return *reinterpret_cast< CEntityPlayer** >( entity );
}

uintptr_t CEntityPlayer::Get( ) {
	return reinterpret_cast< uintptr_t >( this );
}
