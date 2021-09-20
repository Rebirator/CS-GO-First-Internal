#include "Offsets.h"
#include "Entity.h"

BYTE Entity::GetFlags( ) {
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