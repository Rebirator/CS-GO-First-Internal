#include "Glow.hpp"
#include "..\SDK\C_GlowManager.hpp"
#include "..\SDK\C_ColorRenderManager.hpp"
#include "..\SDK\C_Client.hpp"
#include "..\SDK\C_Entity.hpp"

void F_Glow::Glow( ) {
	for ( short i = 1; i < g_Client->GetMaxClients( ); i++ ) {
		C_Entity* entity = C_Entity::G( ).GetByID( i );

		if ( entity->IsAlive( ) ) {
			if ( entity->GetTeam( ) != g_pLocalEntity->GetTeam( ) ) {
				g_GlowManager->Set( entity, 1.0f, 0.1f, 0.1f, 0.6f );
				g_ColorRenderManager->Set( entity, ( BYTE )( 255 - entity->GetHealth( ) * 2.55 ), ( BYTE )( entity->GetHealth( ) * 2.55 ), 0 );
			}
			else {
				g_GlowManager->Set( entity, 0.1f, 0.33f, 1.0f, 0.6f );
			}
		}
	}

	g_ColorRenderManager->Brightness( 1.0f );
}
