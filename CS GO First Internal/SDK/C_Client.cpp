#include "C_Client.hpp"

char* C_Client::GetMapName( ) {
	return reinterpret_cast< char* >( this + g_Game::Signatures::dwClientState_Map );
}

char* C_Client::GetMapDirectory( ) {
	return reinterpret_cast< char* >( this + g_Game::Signatures::dwClientState_MapDirectory );
}

int C_Client::GetMaxClients( ) {
	return *reinterpret_cast< int* >( this + g_Game::Signatures::dwClientState_MaxPlayer );
}

Vector3 C_Client::GetViewAngles( ) {
	return *reinterpret_cast< Vector3* >( this + g_Game::Signatures::dwClientState_ViewAngles );
}

void C_Client::SetViewAngles( Vector3 Angles ) {
	*reinterpret_cast< Vector3* >( this + g_Game::Signatures::dwClientState_ViewAngles ) = Angles;
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

C_Client* C_Client::Get( ) {
	return *reinterpret_cast< C_Client** >( g_Game::EngineDll + g_Game::Signatures::dwClientState );
}
