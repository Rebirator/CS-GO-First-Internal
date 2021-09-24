#ifndef __C_COLORRENDERMANAGER__
#define __C_COLORRENDERMANAGER__

#include "Offsets.hpp"
#include "..\Utils\Singleton.hpp"
#include "C_Entity.hpp"

struct C_ColorRenderDefinition {
	// Reset this address
	C_ColorRenderDefinition( ) {
		memset( this, 0, sizeof( this ) );
	}

	// Color render struct
	BYTE R;						// 0x01
	BYTE G;						// 0x02
	BYTE B;						// 0x03
};

class C_ColorRenderManager : public Singleton< C_ColorRenderManager > {
public:
	void					Set( C_Entity* Entity, BYTE R, BYTE G, BYTE B, float Brightness = 0.0f );

	C_ColorRenderManager*	Get( );
};

#endif//__C_COLORRENDERMANAGER__
