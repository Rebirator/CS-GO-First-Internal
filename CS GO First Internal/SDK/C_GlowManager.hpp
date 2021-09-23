#ifndef __C_GLOWOBJECT__
#define __C_GLOWOBJECT__

#include "Offsets.hpp"
#include "..\Utils\Singleton.hpp"
#include "C_Entity.hpp"

class C_GlowManager : public Singleton< C_GlowManager > {
public:
	void			Set( C_Entity* Entity, float r, float g, float b, float a );

	uintptr			GetIndex( C_Entity* Entity );

	C_GlowManager*	Get( );
};

#endif//__C_GLOWOBJECT__
