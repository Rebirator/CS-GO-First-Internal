#include "C_ColorRenderManager.hpp"
#include <iostream>

void C_ColorRenderManager::Set( C_Entity* Entity, BYTE R, BYTE G, BYTE B ) {
	S_ColorRenderDefinition ColorRender = *reinterpret_cast< S_ColorRenderDefinition* >( Entity + g_Game::Netvars::m_clrRender );

	ColorRender.R = R;
	ColorRender.G = G;
	ColorRender.B = B;

	*reinterpret_cast< S_ColorRenderDefinition* >( Entity + g_Game::Netvars::m_clrRender ) = ColorRender;
}

void C_ColorRenderManager::Brightness( float Value ) {
	if ( CanChangeBrightness && g_pLocalEntity->IsAlive( ) ) {
		*reinterpret_cast< int* >( this ) = *( int* )&Value ^ *reinterpret_cast< int* >( this );
		CanChangeBrightness = false;
	}
}

C_ColorRenderManager* C_ColorRenderManager::Get( ) {
	return reinterpret_cast< C_ColorRenderManager* >( g_Game::EngineDll + g_Game::Signatures::model_ambient_min );
}
