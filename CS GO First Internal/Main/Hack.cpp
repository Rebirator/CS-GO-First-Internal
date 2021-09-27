#include <Windows.h>
#include "Hack.hpp"
#include "..\Gui\Menu.hpp"
#include "..\Features\Aimbot.hpp"
#include "..\Features\TriggerBot.hpp"
#include "..\Features\Misc.hpp"
#include "..\Features\Glow.hpp"
#include "..\Utils\Defines.hpp"
#include "..\SDK\Offsets.hpp"

void Hack( ) {
	F_Aimbot aimbot;
	F_TriggerBot trigger_bot;
	F_Glow glow;
	F_Misc misc;

	if ( g_pLocalPlayer ) {
		aimbot.Aimbot( );

		trigger_bot.TriggerBot( );

		glow.Glow( );

		misc.BunnyHop( );
		misc.RadarHack( );
		misc.RecoilControlSystem( );
	}
}
