#include "Offsets.hpp"
#include "C_Weapon.hpp"
#include "C_Entity.hpp"

C_Weapon g_weapon { };

int C_Weapon::GetID( ) {
	return *reinterpret_cast< int* >( this + g_Game::Netvars::m_iItemDefinitionIndex );
}

C_Weapon* C_Weapon::GetEntity( uintptr_t p_entity_weapon ) {
	return *reinterpret_cast< C_Weapon** >( g_Game::ClientDll + g_Game::Signatures::dwEntityList + ( p_entity_weapon - 1 ) * 0x10 );
}

C_Weapon* C_Weapon::GetWeapon( uintptr_t p_entity ) {
	return this->GetEntity( *reinterpret_cast< uintptr_t* >( p_entity + g_Game::Netvars::m_hActiveWeapon ) & 0xFFF );
}

uintptr_t C_Weapon::Get( ) {
	return reinterpret_cast< uintptr_t >( this );
}
