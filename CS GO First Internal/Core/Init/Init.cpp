#include "Init.hpp"
#include "..\..\SDK\CSGO\Interfaces.hpp"
#include "..\Hooks\Targets\hkEndScene.hpp"

Init g_Init { };

void Init::InitAll( ) {
    InterfacesInit( );
    HooksInit( );
}

void Init::ReleaseAll( ) {
    HooksRelease( );
}

void Init::InterfacesInit( ) {
    g_Interface.GetInterface< IClientEntityList >( g_Interfaces.m_pClientEntityList, "client.dll", "VClientEntityList003" );
    g_Interface.GetInterface< ICHLClient >( g_Interfaces.m_pClient, "client.dll", "VClient018" );
}

void Init::HooksInit( ) {
    g_Hooks::EndSceneInit( );
}

void Init::HooksRelease( ) {
    g_Hooks::EndSceneRelease( );
}

