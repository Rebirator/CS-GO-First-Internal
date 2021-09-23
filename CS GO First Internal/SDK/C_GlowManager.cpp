#include "C_GlowManager.hpp"

void C_GlowManager::Set( C_Entity* Entity, float r, float g, float b, float a ) {
	*reinterpret_cast< float* >( this + ( C_GlowManager::G( ).GetIndex( Entity ) * 0x38 ) + 0x08 ) = r;
	*reinterpret_cast< float* >( this + ( C_GlowManager::G( ).GetIndex( Entity ) * 0x38 ) + 0x0C ) = g;
	*reinterpret_cast< float* >( this + ( C_GlowManager::G( ).GetIndex( Entity ) * 0x38 ) + 0x10 ) = b;
	*reinterpret_cast< float* >( this + ( C_GlowManager::G( ).GetIndex( Entity ) * 0x38 ) + 0x14 ) = a;

	*reinterpret_cast< bool* >( this + ( C_GlowManager::G( ).GetIndex( Entity ) * 0x38 ) + 0x28 ) = true;
	*reinterpret_cast< bool* >( this + ( C_GlowManager::G( ).GetIndex( Entity ) * 0x38 ) + 0x29 ) = false;
}

uintptr C_GlowManager::GetIndex( C_Entity* Entity ) {
	return *reinterpret_cast< uintptr* >( Entity + g_Game::Netvars::m_iGlowIndex );
}

C_GlowManager* C_GlowManager::Get( ) {
	return *reinterpret_cast< C_GlowManager** >( g_Game::ClientDll + g_Game::Signatures::dwGlowObjectManager );
}