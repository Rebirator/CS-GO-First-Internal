#include "Offsets.hpp"
#include "C_Entity.hpp"
#include "C_Weapon.hpp"
#include "C_Client.h"

int C_Entity::GetHealth( ) {
	return *reinterpret_cast< int* >( this + g_Game::g_Netvars::m_iHealth );
}

int C_Entity::GetFlags( ) {
	return *reinterpret_cast< int* >( this + g_Game::g_Netvars::m_fFlags );
}

int C_Entity::GetTeam( ) {
	return *reinterpret_cast< int* >( this + g_Game::g_Netvars::m_iTeamNum );
}

Vector3_t C_Entity::GetPosition( ) {
	return *reinterpret_cast< Vector3_t* >( this + g_Game::g_Netvars::m_vecOrigin );
}

int C_Entity::GetCrosshairEntityID( ) {
	return *reinterpret_cast< int* >( this->GetLocalPlayer( ) + g_Game::g_Netvars::m_iCrosshairId );
}

bool C_Entity::IsDormant( ) {
	return *reinterpret_cast< int* >( this + g_Game::g_Signatures::m_bDormant );
}

bool C_Entity::IsSpotted( ) {
	return *reinterpret_cast< int* >( this + g_Game::g_Netvars::m_bSpotted );
}

void C_Entity::DoJump( ) {
	*reinterpret_cast< BYTE* >( g_Game::ClientDll + g_Game::g_Signatures::dwForceJump ) = 6;
}

void C_Entity::DoAttack1( ) {
	*reinterpret_cast< BYTE* >( g_Game::ClientDll + g_Game::g_Signatures::dwForceAttack ) = 6;
}

void C_Entity::DoAttack2( ) {
	*reinterpret_cast< BYTE* >( g_Game::ClientDll + g_Game::g_Signatures::dwForceAttack2) = 6;
}

C_Entity* C_Entity::GetByID( short int EntityID ) {
	return *reinterpret_cast< C_Entity** >( g_Game::ClientDll + g_Game::g_Signatures::dwEntityList +
										  ( EntityID * 0x10 ) );
}

C_Entity* C_Entity::GetByCrosshairID( ) {
	if ( this->GetCrosshairEntityID( ) > 0 && this->GetCrosshairEntityID( ) <= g_Client->GetMaxClients( ) )
		return *reinterpret_cast< C_Entity** >( g_Game::ClientDll + g_Game::g_Signatures::dwEntityList +
											  ( ( this->GetCrosshairEntityID( ) - 1 ) * 0x10 ) );
	return nullptr;
}

C_Entity* C_Entity::GetLocalPlayer( ) {
	return *reinterpret_cast< C_Entity** >( g_Game::ClientDll + g_Game::g_Signatures::dwLocalPlayer );
}

uintptr C_Entity::Get( ) {
	return reinterpret_cast< uintptr >( this );
}
