#include "..\..\Offsets.hpp"
#include "CEntityPlayer.hpp"
#include "..\..\C_Client.hpp"

CEntityPlayer g_entity { };

bool CEntityPlayer::Alive( ) {
	if ( this && this->Health( ) > 0 && this->Team( ) )
		return true;

	return false;
}

void CEntityPlayer::SetSpotted( bool val ) {
	*reinterpret_cast< bool* >( this + g_NetVar.GetPropOffset( "DT_BaseEntity", "m_bSpotted" ) ) = val;
}

int CEntityPlayer::GetCrosshairEntityID( ) {
	return *reinterpret_cast< int* >( this->Get( g_LocalPlayer ) + g_Game::Netvars::m_iCrosshairId );
}

bool CEntityPlayer::IsDormant( ) {
	return *reinterpret_cast< bool* >( this + g_Game::Signatures::m_bDormant );
}

CEntityPlayer* CEntityPlayer::GetByID( short entity_id ) {
	return *reinterpret_cast< CEntityPlayer** >( g_Game::ClientDll + g_Game::Signatures::dwEntityList + ( entity_id * 0x10 ) );
}

CEntityPlayer* CEntityPlayer::GetByCrosshairID( ) {
	if ( this->CrosshairEntityID( ) > 0 && this->CrosshairEntityID( ) <= g_client.GetMaxClients( ) )
		return *reinterpret_cast< CEntityPlayer** >( g_Game::ClientDll + g_Game::Signatures::dwEntityList +
											  ( ( this->CrosshairEntityID( ) - 1 ) * 0x10 ) );
	return nullptr;
}

CEntityPlayer* CEntityPlayer::GetClosestEntity( ) {
	float closest_distance = 0.0f;
	short closest_ent_id = NULL;

	for ( short i = 1; i < g_client.GetMaxClients( ); i++ ) {
		CEntityPlayer* entity = this->GetByID( i );

		if ( !entity->Alive( ) )
			continue;

		if ( g_pLocalEntity->Position( ).DistanceMeters( entity->Position( ) ) < 5 || closest_distance == 0.0f ) {
			closest_distance = g_pLocalEntity->Position( ).DistanceMeters( entity->Position( ) );
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
