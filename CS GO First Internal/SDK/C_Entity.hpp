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
	int			GetShotsFired( );
	int			GetCrosshairEntityID( );
	Vector3		GetPosition( );
	Vector3		GetViewAngles( );
	Vector3		GetAimPunch( );
	bool		IsAlive( );
	bool		IsDormant( );
	bool		IsSpotted( );
	bool		IsDefusing( );
	void		SetSpotted( bool Value );

	C_Entity*	GetByID( short EntityID );
	C_Entity*	GetByCrosshairID( );
	C_Entity*	GetClosestEntity( );

	C_Entity*	Get( uintptr Entity );
	uintptr		Get( );
};

#endif//__ENTITY__
