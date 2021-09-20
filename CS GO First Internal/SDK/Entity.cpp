#include "Offsets.hpp"
#include "Entity.hpp"

int Entity_t::GetFlags( ) {
	return *reinterpret_cast< int* >( this + g_Netvars::m_fFlags );
}

int Entity_t::GetTeam( ) {
	return *reinterpret_cast< int* >( this + g_Netvars::m_iTeamNum );
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

Entity_t* Entity_t::GetEntityByID( short int EntityID ) {
	Entity_t* Entity = *reinterpret_cast< Entity_t** >( g_Game::GameModule + g_Signatures::dwEntity_tList + ( EntityID * 0x10 ) );

	if ( Entity )
		return Entity;
	else
		return nullptr;
}

Entity_t* Entity_t::GetLocalPlayer( ) {
	return *reinterpret_cast< Entity_t** >( g_Game::GameModule + g_Signatures::dwLocalPlayer );
}