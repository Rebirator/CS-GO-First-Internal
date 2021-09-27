#include "Glow.hpp"
#include "..\SDK\C_GlowManager.hpp"
#include "..\SDK\C_ColorRenderManager.hpp"
#include "..\SDK\C_Client.hpp"
#include "..\SDK\C_Entity.hpp"

void F_Glow::Glow( ) {
	for ( short i = 1; i < g_Client->GetMaxClients( ); i++ ) {
		C_Entity* Entity = C_Entity::G( ).GetByID( i );

		if ( Entity ) {
			if ( Entity->GetTeam( ) != g_pLocalEntity->GetTeam( ) ) {
				g_GlowManager->Set( Entity, 1.0f, 0.1f, 0.1f, 0.6f );
				g_ColorRenderManager->Set( Entity, ( BYTE )( 255 - Entity->GetHealth( ) * 2.55 ), ( BYTE )( Entity->GetHealth( ) * 2.55 ), 0 );
			}
			else {
				g_GlowManager->Set( Entity, 0.1f, 0.33f, 1.0f, 0.6f );
			}
		}
	}

	g_ColorRenderManager->Brightness( 1.0f );
}
