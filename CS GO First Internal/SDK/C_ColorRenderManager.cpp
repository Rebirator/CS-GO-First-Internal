#include "C_ColorRenderManager.hpp"

void C_ColorRenderManager::Set( C_Entity* Entity, BYTE R, BYTE G, BYTE B, float Brightness ) {
	C_ColorRenderDefinition ColorRender = *reinterpret_cast< C_ColorRenderDefinition* >( Entity + g_Game::Netvars::m_clrRender );

	ColorRender.R = R;
	ColorRender.G = G;
	ColorRender.B = B;

	*reinterpret_cast< C_ColorRenderDefinition* >( Entity + g_Game::Netvars::m_clrRender ) = ColorRender;

	if ( Brightness ) {
		static int CanChangeBrightness = -1;

		if ( !g_pLocalEntity->IsAlive( ) || CanChangeBrightness == -1 )
			CanChangeBrightness = true;

		if ( CanChangeBrightness && g_pLocalEntity->IsAlive( ) ) {
			*reinterpret_cast< int* >( this ) = *( int* )&Brightness ^ *reinterpret_cast< int* >( this );
			CanChangeBrightness = false;
		}
	}
}

C_ColorRenderManager* C_ColorRenderManager::Get( ) {
	return reinterpret_cast< C_ColorRenderManager* >( g_Game::EngineDll + g_Game::Signatures::model_ambient_min );
}

uintptr C_ColorRenderManager::Get( bool thisaddr ) {
	return *reinterpret_cast< uintptr* >( this );
}
