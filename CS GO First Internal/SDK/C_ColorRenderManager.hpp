#ifndef __C_COLORRENDERMANAGER__
#define __C_COLORRENDERMANAGER__

#include "Offsets.hpp"
#include "C_Entity.hpp"

struct ColorRenderDefinition_t {
	// Reset this address
	ColorRenderDefinition_t( ) {
		memset( this, 0, sizeof( this ) );
	}

	// Color render struct
	BYTE r;		// 0x01
	BYTE g;		// 0x02
	BYTE b;		// 0x03
};

class C_ColorRenderManager {
public:
	bool can_change_brightness = true;

	void Set( C_Entity* entity, BYTE r, BYTE g, BYTE b );
	void Brightness( float value );
}; extern C_ColorRenderManager g_color_render_manager;

#endif//__C_COLORRENDERMANAGER__
