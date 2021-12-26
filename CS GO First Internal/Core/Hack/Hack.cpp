#include <Windows.h>

#include "Hack.hpp"
#include "..\..\Utils\Defines.hpp"
#include "..\..\Features\Aimbot.hpp"
#include "..\..\Features\TriggerBot.hpp"
#include "..\..\Features\Misc.hpp"
#include "..\..\Features\Glow.hpp"

void Hack( ) {
	if ( g_pLocalPlayer ) {
		g_aimbot.Aimbot( );

		g_triggerbot.TriggerBot( );

		g_glow.Glow( );

		g_misc.BunnyHop( );
		g_misc.RadarHack( );
		g_misc.RecoilControlSystem( );
	}
}
