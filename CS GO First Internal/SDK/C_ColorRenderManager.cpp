#include "C_ColorRenderManager.hpp"
#include <iostream>

C_ColorRenderManager g_color_render_manager { };

void C_ColorRenderManager::Set( CEntityPlayer* entity, BYTE r, BYTE g, BYTE b ) {
	ColorRenderDefinition_t color_render = *reinterpret_cast< ColorRenderDefinition_t* >( entity + g_Game::Netvars::m_clrRender );

	color_render.r = r;
	color_render.g = g;
	color_render.b = b;

	*reinterpret_cast< ColorRenderDefinition_t* >( entity + g_Game::Netvars::m_clrRender ) = color_render;
}

void C_ColorRenderManager::Brightness( float value ) {
	uintptr_t* model_ambient_min = reinterpret_cast< uintptr_t* >( g_Game::EngineDll + g_Game::Signatures::model_ambient_min );

	if ( can_change_brightness && g_pLocalEntity->Alive( ) ) {
		*reinterpret_cast< int* >( model_ambient_min ) = *( int* )&value ^ *reinterpret_cast< int* >( model_ambient_min );
		can_change_brightness = false;
	}
}
