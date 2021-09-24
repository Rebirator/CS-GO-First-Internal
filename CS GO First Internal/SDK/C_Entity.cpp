#include "Offsets.hpp"
#include "C_Entity.hpp"
#include "C_Weapon.hpp"
#include "C_Client.hpp"

int C_Entity::GetHealth( ) {
	if ( !this )
		return NULL;

	return *reinterpret_cast< int* >( this + g_Game::Netvars::m_iHealth );
}

int C_Entity::GetFlags( ) {
	if ( !this )
		return NULL;

	return *reinterpret_cast< int* >( this + g_Game::Netvars::m_fFlags );
}

int C_Entity::GetTeam( ) {
	if ( !this )
		return NULL;

	return *reinterpret_cast< int* >( this + g_Game::Netvars::m_iTeamNum );
}

Vector3 C_Entity::GetPosition( ) {
	if ( !this )
		return Vector3( NULL, NULL, NULL );

	return *reinterpret_cast< Vector3* >( this + g_Game::Netvars::m_vecOrigin );
}

int C_Entity::GetCrosshairEntityID( ) {
	if ( !this )
		return NULL;

	return *reinterpret_cast< int* >( this->Get( g_LocalPlayer ) + g_Game::Netvars::m_iCrosshairId );
}

bool C_Entity::IsDormant( ) {
	if ( !this )
		return NULL;

	return *reinterpret_cast< int* >( this + g_Game::Signatures::m_bDormant );
}

bool C_Entity::IsSpotted( ) {
	if ( !this )
		return NULL;

	return *reinterpret_cast< int* >( this + g_Game::Netvars::m_bSpotted );
}

void C_Entity::DoJump( ) {
	*reinterpret_cast< BYTE* >( g_Game::ClientDll + g_Game::Signatures::dwForceJump ) = 6;
}

void C_Entity::DoAttack1( ) {
	*reinterpret_cast< BYTE* >( g_Game::ClientDll + g_Game::Signatures::dwForceAttack ) = 6;
}

void C_Entity::DoAttack2( ) {
	*reinterpret_cast< BYTE* >( g_Game::ClientDll + g_Game::Signatures::dwForceAttack2 ) = 6;
}

C_Entity* C_Entity::GetByID( short EntityID ) {
	return *reinterpret_cast< C_Entity** >( g_Game::ClientDll + g_Game::Signatures::dwEntityList + ( EntityID * 0x10 ) );
}

C_Entity* C_Entity::GetByCrosshairID( ) {
	if ( !this )
		return nullptr;

	if ( this->GetCrosshairEntityID( ) > 0 && this->GetCrosshairEntityID( ) <= g_Client->GetMaxClients( ) )
		return *reinterpret_cast< C_Entity** >( g_Game::ClientDll + g_Game::Signatures::dwEntityList +
											  ( ( this->GetCrosshairEntityID( ) - 1 ) * 0x10 ) );
	return nullptr;
}

C_Entity* C_Entity::Get( uintptr Entity ) {
	if ( !this )
		return nullptr;

	return *reinterpret_cast< C_Entity** >( Entity );
}

uintptr C_Entity::Get( ) {
	return reinterpret_cast< uintptr >( this );
}
