#ifndef __ENTITY__
#define __ENTITY__

#include "..\..\Offsets.hpp"
#include "..\..\..\Utils\DataTypes\Vector3.hpp"
#include "..\NetVarManager.hpp"

class CEntityPlayer {
public:
	bool Alive( );

	NETVAR( int, Health, "DT_BasePlayer", "m_iHealth" );
	NETVAR( int, Flags, "DT_BasePlayer", "m_fFlags" );
	NETVAR( int, Team, "DT_BaseEntity", "m_iTeamNum" );
	NETVAR( int, ShotsFired, "DT_BasePlayer", "m_iShotsFired" );

	int			GetCrosshairEntityID( );
	Vector3		GetPosition( );
	Vector3		GetViewAngles( );
	Vector3		GetAimPunch( );
	bool		IsDormant( );
	bool		IsSpotted( );
	bool		IsDefusing( );
	void		SetSpotted( bool Value );

	CEntityPlayer*	GetByID( short EntityID );
	CEntityPlayer*	GetByCrosshairID( );
	CEntityPlayer*	GetClosestEntity( );

	CEntityPlayer*	Get( uintptr_t Entity );
	uintptr_t	Get( );
}; extern CEntityPlayer g_entity;

#endif//__ENTITY__
