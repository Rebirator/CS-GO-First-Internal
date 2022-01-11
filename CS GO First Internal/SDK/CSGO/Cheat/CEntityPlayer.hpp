#ifndef __ENTITY__
#define __ENTITY__

#include "..\..\Offsets.hpp"
#include "..\..\..\Utils\DataTypes\Vector3.hpp"
#include "..\NetVarManager.hpp"

class CEntityPlayer {
public:
	bool Alive( );
	void SetSpotted( bool val );

	NETVAR( int, Health, "DT_BasePlayer", "m_iHealth", this );
	NETVAR( int, Flags, "DT_BasePlayer", "m_fFlags", this );
	NETVAR( int, Team, "DT_BaseEntity", "m_iTeamNum", this );
	NETVAR( int, ShotsFired, "DT_BasePlayer", "m_iShotsFired", this );
	NETVARA( int, CrosshairEntityID, "DT_CSPlayer", "m_bHasDefuser", 0x5C, g_LocalPlayer );
	NETVAR( Vector3, Position, "DT_BaseEntity", "m_vecOrigin", this );
	NETVAR( Vector3, ViewAngles, "DT_CSPlayer", "m_vecViewOffset[0]", this );
	NETVAR( Vector3, AimPunch, "DT_BasePlayer", "m_aimPunchAngle", this );
	NETVAR( bool, Spotted, "DT_BaseEntity", "m_bSpotted", this );
	NETVAR( bool, Defusing, "DT_CSPlayer", "m_bIsDefusing", this );
	NETVAR( bool, HasDefuser, "DT_CSPlayer", "m_bHasDefuser", this );

	int			GetCrosshairEntityID( );
	bool		IsDormant( );

	CEntityPlayer*	GetByID( short EntityID );
	CEntityPlayer*	GetByCrosshairID( );
	CEntityPlayer*	GetClosestEntity( );

	CEntityPlayer*	Get( uintptr_t Entity );
	uintptr_t	Get( );
}; extern CEntityPlayer g_entity;

#endif//__ENTITY__
