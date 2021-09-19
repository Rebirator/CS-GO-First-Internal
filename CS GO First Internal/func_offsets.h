#include <Windows.h>
#include "offsets.h"

using namespace hazedumper;

template< class ReturnType >
ReturnType GetValue( uintptr_t address )
{
	return *reinterpret_cast< ReturnType* >( address );
}

template< class SetType >
void SetValue( uintptr_t Address, SetType value )
{
	*reinterpret_cast< SetType* >( Address ) = value;
}

namespace g_Game
{
	uintptr_t GameModule = ( uintptr_t )GetModuleHandle( L"client.dll" );
}

struct r_offsets
{
	uintptr_t GetEntityByIndex( short int ent_index ) {
		return GetValue< uintptr_t >( g_Game::GameModule + signatures::dwEntityList + ( ent_index * 0x10 ) ); 
	};

	int GetEntityTeam( uintptr_t entity ) {
		return GetValue< int >( entity + netvars::m_iTeamNum );
	};

	bool GetIsEntityDormant( uintptr_t entity )	{
		return GetValue< bool >( entity + signatures::m_bDormant );
	};

	bool GetIsEntitySpotted( uintptr_t entity )	{ 
		return GetValue< bool >( entity + netvars::m_bSpotted );
	};

	BYTE GetEntityFlags( uintptr_t entity ) {
		return GetValue< BYTE >( entity + netvars::m_fFlags );
	};
} Funcs;

uintptr_t GetLocalPlayer()
{
	return GetValue< uintptr_t >( g_Game::GameModule + signatures::dwLocalPlayer );
}