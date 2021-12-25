#include "Init.hpp"
#include "..\SDK\Interfaces.hpp"

Init g_init { };

void Init::Initialization( ) {
    Init::Interfaces( );
}

void Init::Interfaces( ) {
    g_interface.GetInterface< IClientEntityList >( g_interfaces.p_client_entitylist, "client.dll", "VClientEntityList003" );
}
