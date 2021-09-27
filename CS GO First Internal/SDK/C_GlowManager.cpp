#include "C_GlowManager.hpp"
#include <iostream>

void C_GlowManager::Set( C_Entity* entity, float r, float g, float b, float a ) {
	S_GlowDefinition glow = *reinterpret_cast< S_GlowDefinition* >( this + ( C_GlowManager::G( ).GetIndex( entity ) * 0x38 ) );

	glow.r = r;
	glow.g = g;
	glow.b = b;
	glow.a = a;
	glow.when_occluded = true;
	glow.when_unoccluded = false;

	*reinterpret_cast< S_GlowDefinition* >( this + ( C_GlowManager::G( ).GetIndex( entity ) * 0x38 ) ) = glow;
}

uintptr C_GlowManager::GetIndex( C_Entity* entity ) {
	return *reinterpret_cast< uintptr* >( entity + g_Game::Netvars::m_iGlowIndex );
}

C_GlowManager* C_GlowManager::Get( ) {
	return *reinterpret_cast< C_GlowManager** >( g_Game::ClientDll + g_Game::Signatures::dwGlowObjectManager );
}