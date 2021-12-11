#ifndef __C_GLOWMANAGER__
#define __C_GLOWMANAGER__

#include "Offsets.hpp"
#include "../Utils/Pad.hpp"
#include "C_Entity.hpp"

struct GlowDefinition_t {
	// Reset this address
	GlowDefinition_t( ) {
		memset( this, 0, sizeof( this ) );
	}

	// Glow struct
	int		m_next_free_slot;	 // 0x00
	PAD( 0x4 );					 // 0x04
	float	m_r;				 // 0x08
	float	m_g;				 // 0x0C
	float	m_b;				 // 0x10
	float	m_a;				 // 0x14
	PAD( 0x10 )					 // 0x18
	bool	m_when_occluded;	 // 0x28
	bool	m_when_unoccluded;	 // 0x29
	bool	m_full_bloom;		 // 0x30
	int		m_style;			 // 0x38
	int		m_split_screen_slot; // 0x3C

	// [ FLOAT ] SomeFloat		 // 0x1C
	// [ FLOAT ] AnotherFloat	 // 0x24
};

class C_GlowManager {
public:
	void	Set( C_Entity* Entity, float R, float G, float B, float A );

	uintptr_t	GetIndex( C_Entity* Entity );
}; extern C_GlowManager g_glow_manager;

#endif//__C_GLOWMANAGER__
