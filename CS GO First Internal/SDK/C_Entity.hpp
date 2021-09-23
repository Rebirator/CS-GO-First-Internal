#ifndef __ENTITY__
#define __ENTITY__

#include "Offsets.hpp"
#include "..\Utils\Singleton.hpp"
#include "..\Utils\Vector3.hpp"
#include "C_Weapon.hpp"

class C_Entity : public Singleton< C_Entity >
{
public:
	C_Entity( void ) { };

	int			GetHealth( );
	int			GetFlags( );
	int			GetTeam( );
	Vector3		GetPosition( );
	bool		IsDormant( );
	bool		IsSpotted( );
	void		DoJump( );
	void		DoAttack1( );
	void		DoAttack2( );

	C_Entity*	GetByID( short EntityID );
	int			GetCrosshairEntityID( );
	C_Entity*	GetByCrosshairID( );

	C_Entity*	Get( uintptr Entity );
	uintptr		Get( );
};

#endif//__Entity_t__
