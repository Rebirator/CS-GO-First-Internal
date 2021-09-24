#include "Offsets.hpp"
#include "C_Entity.hpp"
#include "C_Weapon.hpp"
#include "C_Client.hpp"

int C_Entity::GetHealth( ) {
	return *reinterpret_cast< int* >( this + g_Game::Netvars::m_iHealth );
}

int C_Entity::GetFlags( ) {
	return *reinterpret_cast< int* >( this + g_Game::Netvars::m_fFlags );
}

int C_Entity::GetTeam( ) {
	return *reinterpret_cast< int* >( this + g_Game::Netvars::m_iTeamNum );
}

Vector3 C_Entity::GetPosition( ) {
	return *reinterpret_cast< Vector3* >( this + g_Game::Netvars::m_vecOrigin );
}

int C_Entity::GetCrosshairEntityID( ) {
	return *reinterpret_cast< int* >( this->Get( g_LocalPlayer ) + g_Game::Netvars::m_iCrosshairId );
}

bool C_Entity::IsAlive( ) {
	if ( !this )
		return false;

	if ( this->GetTeam( ) != 1 && this->GetHealth( ) > 0 )
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

void C_Entity::SetSpotted( bool Value ) {
	*reinterpret_cast< bool* >( this + g_Game::Netvars::m_bSpotted ) = Value;
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
	if ( this->GetCrosshairEntityID( ) > 0 && this->GetCrosshairEntityID( ) <= g_Client->GetMaxClients( ) )
		return *reinterpret_cast< C_Entity** >( g_Game::ClientDll + g_Game::Signatures::dwEntityList +
											  ( ( this->GetCrosshairEntityID( ) - 1 ) * 0x10 ) );

	return nullptr;
}

C_Entity* C_Entity::Get( uintptr Entity ) {
	return *reinterpret_cast< C_Entity** >( Entity );
}

uintptr C_Entity::Get( ) {
	return reinterpret_cast< uintptr >( this );
}
