#ifndef __ENTITY__
#define __ENTITY__

#include "Offsets.hpp"
#include "..\Utils\Singleton.hpp"

class Entity : public Singleton< Entity >
{
public:
	int		GetFlags( );
	int		GetTeam( );
	bool	IsDormant( );
	bool	IsSpotted( );

	Entity* GetLocalPlayer( );
};

#endif