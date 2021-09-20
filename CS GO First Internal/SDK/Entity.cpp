#include "Offsets.h"
#include "Entity.h"

int Entity::GetTeam( ) {
	if ( !this )
		return NULL;

	return *reinterpret_cast< int* >( this + g_Netvars::m_iTeamNum );
}