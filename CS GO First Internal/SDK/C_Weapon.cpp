#include "Offsets.hpp"
#include "C_Weapon.hpp"
#include "C_Entity.hpp"

int C_Weapon::GetID( ) {
	return *reinterpret_cast< int* >( this + g_Game::Netvars::m_iItemDefinitionIndex );
}

C_Weapon* C_Weapon::GetEntity( uintptr pEntityWeapon ) {
	return *reinterpret_cast< C_Weapon** >( g_Game::ClientDll + g_Game::Signatures::dwEntityList + ( pEntityWeapon - 1 ) * 0x10 );
}

C_Weapon* C_Weapon::GetWeapon( uintptr pEntity )
{
	return this->GetEntity( *reinterpret_cast< uintptr* >( pEntity + g_Game::Netvars::m_hActiveWeapon ) & 0xFFF );
}

uintptr C_Weapon::Get( )
{
	return reinterpret_cast< uintptr >( this );
}
