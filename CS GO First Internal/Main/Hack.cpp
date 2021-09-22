#include <Windows.h>
#include "..\Features\TriggerBot.hpp"
#include "..\Features\Misc.hpp"
#include "..\Utils\Defines.hpp"
#include "..\SDK\Offsets.hpp"

void Hack( ) {
	if ( g_LocalPlayer ) {
		TriggerBot_t::G().TriggerBot();
		Misc_t::G().BunnyHop();
	}
}