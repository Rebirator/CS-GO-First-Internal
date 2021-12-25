#include "Glow.hpp"
#include "..\SDK\C_GlowManager.hpp"
#include "..\SDK\C_ColorRenderManager.hpp"
#include "..\SDK\C_Client.hpp"
#include "..\SDK\C_Entity.hpp"
#include "..\SDK\Interfaces.hpp"

F_Glow g_glow { };

void F_Glow::Glow( ) {
	for ( short i = 1; i < g_interfaces.p_client_entitylist->GetHighestEntityIndex( ); i++ ) {
		C_Entity* entity = g_interfaces.p_client_entitylist->GetClientEntity( i );

		if ( entity->IsAlive( ) ) {
			if ( entity->GetTeam( ) != g_pLocalEntity->GetTeam( ) ) {
				g_glow_manager.Set( entity, 1.0f, 0.1f, 0.1f, 0.6f );
				g_color_render_manager.Set( entity, ( BYTE )( 255 - entity->GetHealth( ) * 2.55 ), ( BYTE )( entity->GetHealth( ) * 2.55 ), 0 );
			}
			else {
				g_glow_manager.Set( entity, 0.1f, 0.33f, 1.0f, 0.6f );
			}
		}
	}

	g_color_render_manager.Brightness( 1.0f );
}
