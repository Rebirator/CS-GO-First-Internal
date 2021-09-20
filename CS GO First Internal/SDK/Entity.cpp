#include "Offsets.hpp"
#include "Entity.hpp"

int Entity::GetFlags( ) {
	if ( !this )
		return NULL;

	return *reinterpret_cast< int* >( this + g_Netvars::m_fFlags );
}

int Entity::GetTeam( ) {
	if ( !this )
		return NULL;

	return *reinterpret_cast< int* >( this + g_Netvars::m_iTeamNum );
}

bool Entity::IsDormant( ) {
	if ( !this )
		return NULL;

	return *reinterpret_cast< int* >( this + g_Signatures::m_bDormant );
}

bool Entity::IsSpotted( ) {
	if ( !this )
		return NULL;

	return *reinterpret_cast< int* >( this + g_Netvars::m_bSpotted );
}

Entity* Entity::GetLocalPlayer( ) {
	return *reinterpret_cast< Entity** >( g_Game::GameModule + g_Signatures::dwLocalPlayer );
}