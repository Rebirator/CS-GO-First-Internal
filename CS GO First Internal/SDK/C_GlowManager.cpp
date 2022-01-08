#include "C_GlowManager.hpp"
#include <iostream>
#include "CSGO\NetVarManager.hpp"

C_GlowManager g_glow_manager { };

void C_GlowManager::Set( CEntityPlayer* entity, float r, float g, float b, float a ) {
	C_GlowManager* glow_object_manager = *reinterpret_cast< C_GlowManager** >( g_Game::ClientDll + g_Game::Signatures::dwGlowObjectManager );
	GlowDefinition_t glow = *reinterpret_cast< GlowDefinition_t* >( glow_object_manager + ( g_glow_manager.GetIndex( entity ) * 0x38 ) );

	glow.m_r = r;
	glow.m_g = g;
	glow.m_b = b;
	glow.m_a = a;
	glow.m_when_occluded = true;
	glow.m_when_unoccluded = false;

	*reinterpret_cast< GlowDefinition_t* >( glow_object_manager + ( g_glow_manager.GetIndex( entity ) * 0x38 ) ) = glow;
}

uintptr_t C_GlowManager::GetIndex( CEntityPlayer* entity ) {
	return *reinterpret_cast< uintptr_t* >( entity + g_Game::Netvars::m_iGlowIndex );
}
