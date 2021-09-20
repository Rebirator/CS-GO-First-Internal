#include "Misc.hpp"
#include "..\SDK\Entity.hpp"

void Misc_t::BunnyHop( ) {
	while ( GetAsyncKeyState( VK_SPACE ) ) {
		if ( g_pLocalPlayer->GetFlags( ) & ( 1 << 0 ) ) {
			g_pLocalPlayer->DoJump( );
		}
	}
}