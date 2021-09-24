#include <Windows.h>
#include "..\Gui\Menu.hpp"
#include "..\Features\TriggerBot.hpp"
#include "..\Features\Misc.hpp"
#include "..\Features\Glow.h"
#include "..\Utils\Defines.hpp"
#include "..\SDK\Offsets.hpp"

void Hack( ) {
	if ( g_pLocalPlayer ) {
		F_TriggerBot::G( ).TriggerBot( );
		F_Glow::G( ).Glow( );
		F_Misc::G( ).BunnyHop( );
		F_Misc::G( ).RadarHack( );
		F_Misc::G( ).RecoilControlSystem( );
	}
}
