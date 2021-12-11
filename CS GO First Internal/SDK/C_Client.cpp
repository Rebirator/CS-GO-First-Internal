#include "C_Client.hpp"

C_Client g_client { };

char* C_Client::GetMapName( ) {
	C_Client* client_state = *reinterpret_cast< C_Client** >( g_Game::EngineDll + g_Game::Signatures::dwClientState );
	return reinterpret_cast< char* >( client_state + g_Game::Signatures::dwClientState_Map );
}

char* C_Client::GetMapDirectory( ) {
	C_Client* client_state = *reinterpret_cast< C_Client** >( g_Game::EngineDll + g_Game::Signatures::dwClientState );
	return reinterpret_cast< char* >( client_state + g_Game::Signatures::dwClientState_MapDirectory );
}

int C_Client::GetMaxClients( ) {
	C_Client* client_state = *reinterpret_cast< C_Client** >( g_Game::EngineDll + g_Game::Signatures::dwClientState );
	return *reinterpret_cast< int* >( client_state + g_Game::Signatures::dwClientState_MaxPlayer );
}

Vector3 C_Client::GetViewAngles( ) {
	C_Client* client_state = *reinterpret_cast< C_Client** >( g_Game::EngineDll + g_Game::Signatures::dwClientState );
	return *reinterpret_cast< Vector3* >( client_state + g_Game::Signatures::dwClientState_ViewAngles );
}

void C_Client::SetViewAngles( Vector3 Angles ) {
	C_Client* client_state = *reinterpret_cast< C_Client** >( g_Game::EngineDll + g_Game::Signatures::dwClientState );
	*reinterpret_cast< Vector3* >( client_state + g_Game::Signatures::dwClientState_ViewAngles ) = Angles;
}

void C_Client::DoJump( ) {
	*reinterpret_cast< BYTE* >( g_Game::ClientDll + g_Game::Signatures::dwForceJump ) = 6;
}

void C_Client::DoAttack1( ) {
	*reinterpret_cast< BYTE* >( g_Game::ClientDll + g_Game::Signatures::dwForceAttack ) = 6;
}

void C_Client::DoAttack2( ) {
	*reinterpret_cast< BYTE* >( g_Game::ClientDll + g_Game::Signatures::dwForceAttack2 ) = 6;
}
