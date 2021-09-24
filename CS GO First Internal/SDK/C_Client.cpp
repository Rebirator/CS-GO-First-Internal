#include "C_Client.hpp"

char* C_Client::GetMapName( ) {
	if ( !this )
		return nullptr;

	return reinterpret_cast< char* >( this + g_Game::Signatures::dwClientState_Map );
}

char* C_Client::GetMapDirectory( ) {
	if ( !this )
		return nullptr;

	return reinterpret_cast< char* >( this + g_Game::Signatures::dwClientState_MapDirectory );
}

int C_Client::GetMaxClients( ) {
	if ( !this )
		return NULL;

	return *reinterpret_cast< int* >( this + g_Game::Signatures::dwClientState_MaxPlayer );
}

C_Client* C_Client::Get( ) {
	return *reinterpret_cast< C_Client** >( g_Game::EngineDll + g_Game::Signatures::dwClientState );
}
