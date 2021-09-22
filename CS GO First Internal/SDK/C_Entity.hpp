#ifndef __ENTITY__
#define __ENTITY__

#include "Offsets.hpp"
#include "..\Utils\Singleton.hpp"
#include "..\Utils\Vector.hpp"
#include "C_Weapon.hpp"

class C_Entity : public Singleton< C_Entity >
{
public:
	C_Entity( void ) { };

	int			GetHealth( );
	int			GetFlags( );
	int			GetTeam( );
	Vector3_t	GetPosition( );
	bool		IsDormant( );
	bool		IsSpotted( );
	void		DoJump( );
	void		DoAttack1( );
	void		DoAttack2( );

	C_Entity*	GetByID( short int EntityID );
	int			GetCrosshairEntityID( );
	C_Entity*	GetByCrosshairID( );
	C_Entity*	GetLocalPlayer( );
	uintptr		Get( );
};

#endif//__Entity_t__