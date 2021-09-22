#include "Misc.hpp"
#include "..\SDK\C_Entity.hpp"
#include <iostream>

void Misc_t::BunnyHop( ) {
	if ( GetAsyncKeyState( VK_SPACE ) ) {
		if ( g_pLocalEntity->GetFlags( ) & ( 1 << 0 ) ) {
			g_pLocalEntity->DoJump( );
		}
	}
}
