#ifndef __C_GLOWMANAGER__
#define __C_GLOWMANAGER__

#include "Offsets.hpp"
#include "..\Utils\Singleton.hpp"
#include "C_Entity.hpp"

struct S_GlowDefinition {
	// Reset this address
	S_GlowDefinition( ) {
		memset( this, 0, sizeof( this ) );
	}

	// Glow struct
	BYTE Buffer1[ 8 ];			// 0x00
	float r;					// 0x08
	float g;					// 0x0C
	float b;					// 0x10
	float a;					// 0x14
	BYTE Buffer2[ 16 ];			// 0x18
	bool when_occluded;			// 0x28
	bool when_unoccluded;		// 0x29

	// [UINT] NextFreeSlot		// 0x04
	// [FLOAT]SomeFloat			// 0x1C
	// [FLOAT]AnotherFloat		// 0x24
	// [BOOL] FullBloom			// 0x30
	// [UINT] Style				// 0x38
	// [UINT] SplitScreenSlot	// 0x3C
};

class C_GlowManager : public Singleton< C_GlowManager > {
public:
	void			Set( C_Entity* Entity, float R, float G, float B, float A );

	uintptr			GetIndex( C_Entity* Entity );

	C_GlowManager*	Get( );
};

#endif//__C_GLOWMANAGER__
