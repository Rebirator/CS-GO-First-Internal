#include "Offsets.hpp"
#include "Entity.hpp"

int Entity_t::GetHealth( ) {
	return *reinterpret_cast< int* >( this + g_Netvars::m_iHealth );
}

int Entity_t::GetFlags( ) {
	return *reinterpret_cast< int* >( this + g_Netvars::m_fFlags );
}

int Entity_t::GetTeam( ) {
	return *reinterpret_cast< int* >( this + g_Netvars::m_iTeamNum );
}

Vector3 Entity_t::GetPosition( ) {
	return *reinterpret_cast< Vector3* >( this + g_Netvars::m_vecOrigin );
}

int Entity_t::GetCrosshairEntityID( ) {
	return *reinterpret_cast< int* >( this + g_Netvars::m_iCrosshairId ) - 1;
}

bool Entity_t::IsDormant( ) {
	return *reinterpret_cast< int* >( this + g_Signatures::m_bDormant );
}

bool Entity_t::IsSpotted( ) {
	return *reinterpret_cast< int* >( this + g_Netvars::m_bSpotted );
}

void Entity_t::DoJump( ) {
	*reinterpret_cast< BYTE* >( g_Game::GameModule + g_Signatures::dwForceJump ) = 5;
	Sleep( 10 );
	*reinterpret_cast< BYTE* >( g_Game::GameModule + g_Signatures::dwForceJump ) = 4;
}

void Entity_t::DoAttack1( ) {
	*reinterpret_cast< BYTE* >( g_Game::GameModule + g_Signatures::dwForceAttack ) = 5;
	Sleep( 10 );
	*reinterpret_cast< BYTE* >( g_Game::GameModule + g_Signatures::dwForceAttack ) = 4;
}

Entity_t* Entity_t::GetEntityByID( short int EntityID ) {
	return *reinterpret_cast< Entity_t** >( g_Game::GameModule + g_Signatures::dwEntityList + ( EntityID * 0x10 ) );
}

Entity_t* Entity_t::GetLocalPlayer( ) {
	return *reinterpret_cast< Entity_t** >( g_Game::GameModule + g_Signatures::dwLocalPlayer );
}