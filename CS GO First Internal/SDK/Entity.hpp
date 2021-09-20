#ifndef __ENTITY__
#define __ENTITY__

#include "Offsets.hpp"
#include "..\Utils\Singleton.hpp"

class Entity_t : public Singleton< Entity_t >
{
public:
	int			GetFlags( );
	int			GetTeam( );
	bool		IsDormant( );
	bool		IsSpotted( );
	void		DoJump( );

	Entity_t*	GetEntityByID( short int EntityID );
	Entity_t*	GetLocalPlayer( );
};

#endif//__Entity_t__