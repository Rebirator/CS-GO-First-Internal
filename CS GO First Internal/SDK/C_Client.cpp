#include "C_Client.h"

char* C_Client::GetMapName( ) {
	return reinterpret_cast< char* >( this + g_Game::g_Signatures::dwClientState_Map );
}

char* C_Client::GetMapDirectory( ) {
	return reinterpret_cast< char* >( this + g_Game::g_Signatures::dwClientState_MapDirectory );
}

int C_Client::GetMaxClients( ) {
	return *reinterpret_cast< int* >( this + g_Game::g_Signatures::dwClientState_MaxPlayer );
}

C_Client* C_Client::Get( ) {
	return *reinterpret_cast< C_Client** >( g_Game::EngineDll + g_Game::g_Signatures::dwClientState );
}
