#include "Glow.hpp"
#include "..\SDK\C_GlowManager.hpp"
#include "..\SDK\C_ColorRenderManager.hpp"
#include "..\SDK\C_Client.hpp"
#include "..\SDK\CSGO\Cheat\CEntityPlayer.hpp"
#include "..\SDK\CSGO\Interfaces.hpp"
#include "..\SDK\CSGO\NetvarManager.hpp"

C_Glow g_glow { };

void C_Glow::Glow( ) {
	for ( short i = 1; i < g_Interfaces.m_pClientEntityList->GetHighestEntityIndex( ); i++ ) {
		CEntityPlayer* entity = g_Interfaces.m_pClientEntityList->GetClientEntity( i );

		if ( entity->Alive( ) ) {
			if ( entity->Team( ) != g_pLocalEntity->Team( ) ) {
				g_glow_manager.Set( entity, 1.0f, 0.1f, 0.1f, 0.6f );
				g_color_render_manager.Set( entity, ( BYTE )( 255 - entity->Health( ) * 2.55 ), ( BYTE )( entity->Health( ) * 2.55 ), 0 );
			}
			else {
				g_glow_manager.Set( entity, 0.1f, 0.33f, 1.0f, 0.6f );
			}
		}
	}

	g_color_render_manager.Brightness( 1.0f );
}
