#include "Init.hpp"
#include "..\..\SDK\CSGO\Interfaces.hpp"

Init g_init { };

void Init::InitAll( ) {
    Init::Interfaces( );
}

void Init::Interfaces( ) {
    g_interface.GetInterface< IClientEntityList >( g_interfaces.m_pClientEntityList, "client.dll", "VClientEntityList003" );
    g_interface.GetInterface< ICHLClient >( g_interfaces.m_pClient, "client.dll", "VClient018" );
}
