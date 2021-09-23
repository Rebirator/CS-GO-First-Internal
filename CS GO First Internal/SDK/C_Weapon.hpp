#ifndef __WEAPON__
#define __WEAPON__

#include "Offsets.hpp"
#include "..\Utils\Singleton.hpp"
#include "..\Utils\Vector3.hpp"
#include "C_Entity.hpp"

class C_Weapon : public Singleton< C_Weapon > {
public:
	int			GetID( );
	C_Weapon*	GetEntity( uintptr pEntityWeapon );
	C_Weapon*	GetWeapon( uintptr pEntity );
	uintptr		Get( );
};

enum {
	CS_WEAPON_DESERTEAGLE = 1,
	CS_WEAPON_DUALBERETTAS = 2,

};

#endif//__WEAPON__
