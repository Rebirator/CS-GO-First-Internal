#include "C_GlowManager.hpp"
#include <iostream>

void C_GlowManager::Set( C_Entity* Entity, float R, float G, float B, float A ) {
	C_GlowDefinition Glow = *reinterpret_cast< C_GlowDefinition* >( this + ( C_GlowManager::G( ).GetIndex( Entity ) * 0x38 ) );

	Glow.R = R;
	Glow.G = G;
	Glow.B = B;
	Glow.A = A;
	Glow.WhenOccluded = true;
	Glow.WhenUnOccluded = false;

	*reinterpret_cast< C_GlowDefinition* >( this + ( C_GlowManager::G( ).GetIndex( Entity ) * 0x38 ) ) = Glow;
}

uintptr C_GlowManager::GetIndex( C_Entity* Entity ) {
	return *reinterpret_cast< uintptr* >( Entity + g_Game::Netvars::m_iGlowIndex );
}

C_GlowManager* C_GlowManager::Get( ) {
	return *reinterpret_cast< C_GlowManager** >( g_Game::ClientDll + g_Game::Signatures::dwGlowObjectManager );
}