#ifndef __ENTITY__
#define __ENTITY__

#include "Offsets.hpp"
#include "..\Utils\Singleton.hpp"
#include "..\Utils\Vector.hpp"

class Entity_t : public Singleton< Entity_t >
{
public:
	int			GetHealth( );
	int			GetFlags( );
	int			GetTeam( );
	Vector3		GetPosition( );
	int			GetCrosshairEntityID( );
	bool		IsDormant( );
	bool		IsSpotted( );
	void		DoJump( );
	void		DoAttack1( );

	Entity_t*	GetEntityByID( short int EntityID );
	Entity_t*	GetLocalPlayer( );
};

#endif//__Entity_t__