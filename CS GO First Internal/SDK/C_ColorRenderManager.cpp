#include "C_ColorRenderManager.hpp"
#include <iostream>

void C_ColorRenderManager::Set( C_Entity* entity, BYTE r, BYTE g, BYTE b ) {
	S_ColorRenderDefinition color_render = *reinterpret_cast< S_ColorRenderDefinition* >( entity + g_Game::Netvars::m_clrRender );

	color_render.r = r;
	color_render.g = g;
	color_render.b = b;

	*reinterpret_cast< S_ColorRenderDefinition* >( entity + g_Game::Netvars::m_clrRender ) = color_render;
}

void C_ColorRenderManager::Brightness( float value ) {
	if ( can_change_brightness && g_pLocalEntity->IsAlive( ) ) {
		*reinterpret_cast< int* >( this ) = *( int* )&value ^ *reinterpret_cast< int* >( this );
		can_change_brightness = false;
	}
}

C_ColorRenderManager* C_ColorRenderManager::Get( ) {
	return reinterpret_cast< C_ColorRenderManager* >( g_Game::EngineDll + g_Game::Signatures::model_ambient_min );
}
