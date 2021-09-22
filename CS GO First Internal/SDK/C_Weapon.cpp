#include "Offsets.hpp"
#include "C_Weapon.hpp"
#include "C_Entity.hpp"

int C_Weapon::GetID( ) {
	return *reinterpret_cast< int* >( this + g_Game::g_Netvars::m_iItemDefinitionIndex );
}

C_Weapon* C_Weapon::GetEntity( uintptr EntityWeapon ) {
	return *reinterpret_cast< C_Weapon** >( g_Game::ClientDll + g_Game::g_Signatures::dwEntityList + ( EntityWeapon - 1 ) * 0x10 );
}

C_Weapon* C_Weapon::GetWeapon( uintptr Entity )
{
	return this->GetEntity( *reinterpret_cast< uintptr* >( Entity + g_Game::g_Netvars::m_hActiveWeapon ) & 0xFFF );
}

uintptr C_Weapon::Get( )
{
	return reinterpret_cast< uintptr >( this );
}
