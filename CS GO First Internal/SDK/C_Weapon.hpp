#ifndef __WEAPON__
#define __WEAPON__

#include "Offsets.hpp"
#include "..\Utils\Vector3.hpp"
#include "C_Entity.hpp"

class C_Weapon {
public:
	int			GetID( );
	C_Weapon*	GetEntity( uintptr_t pEntityWeapon );
	C_Weapon*	GetWeapon( uintptr_t pEntity );
	uintptr_t	Get( );
}; extern C_Weapon g_weapon;

#endif//__WEAPON__
