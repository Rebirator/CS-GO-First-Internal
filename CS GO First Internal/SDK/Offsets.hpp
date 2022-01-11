#ifndef __OFFSETS__
#define __OFFSETS__

#include <Windows.h>
#include "Hazedumper.hpp"
#include "..\Utils\Defines.hpp"

namespace g_Game {
	const uintptr_t ClientDll								= ( uintptr_t )GetModuleHandle( L"client.dll" );
	const uintptr_t EngineDll								= ( uintptr_t )GetModuleHandle( L"engine.dll" );

	namespace Netvars {
		const uintptr_t cs_gamerules_data				= hazedumper::netvars::cs_gamerules_data;
		const uintptr_t m_ArmorValue					= hazedumper::netvars::m_ArmorValue;
		const uintptr_t m_Collision						= hazedumper::netvars::m_Collision;
		const uintptr_t m_CollisionGroup				= hazedumper::netvars::m_CollisionGroup;
		const uintptr_t m_Local							= hazedumper::netvars::m_Local;
		const uintptr_t m_MoveType						= hazedumper::netvars::m_MoveType;
		const uintptr_t m_OriginalOwnerXuidHigh			= hazedumper::netvars::m_OriginalOwnerXuidHigh;
		const uintptr_t m_OriginalOwnerXuidLow			= hazedumper::netvars::m_OriginalOwnerXuidLow;
		const uintptr_t m_SurvivalGameRuleDecisionTypes	= hazedumper::netvars::m_SurvivalGameRuleDecisionTypes;
		const uintptr_t m_SurvivalRules					= hazedumper::netvars::m_SurvivalRules;
		const uintptr_t m_aimPunchAngle					= hazedumper::netvars::m_aimPunchAngle;
		const uintptr_t m_aimPunchAngleVel				= hazedumper::netvars::m_aimPunchAngleVel;
		const uintptr_t m_angEyeAnglesX					= hazedumper::netvars::m_angEyeAnglesX;
		const uintptr_t m_angEyeAnglesY					= hazedumper::netvars::m_angEyeAnglesY;
		const uintptr_t m_bBombDefused					= hazedumper::netvars::m_bBombDefused;
		const uintptr_t m_bBombPlanted					= hazedumper::netvars::m_bBombPlanted;
		const uintptr_t m_bBombTicking					= hazedumper::netvars::m_bBombTicking;
		const uintptr_t m_bFreezePeriod					= hazedumper::netvars::m_bFreezePeriod;
		const uintptr_t m_bGunGameImmunity				= hazedumper::netvars::m_bGunGameImmunity;
		const uintptr_t m_bHasDefuser					= hazedumper::netvars::m_bHasDefuser;
		const uintptr_t m_bHasHelmet					= hazedumper::netvars::m_bHasHelmet;
		const uintptr_t m_bInReload						= hazedumper::netvars::m_bInReload;
		const uintptr_t m_bIsDefusing					= hazedumper::netvars::m_bIsDefusing;
		const uintptr_t m_bIsQueuedMatchmaking			= hazedumper::netvars::m_bIsQueuedMatchmaking;
		const uintptr_t m_bIsScoped						= hazedumper::netvars::m_bIsScoped;
		const uintptr_t m_bIsValveDS					= hazedumper::netvars::m_bIsValveDS;
		const uintptr_t m_bSpotted						= hazedumper::netvars::m_bSpotted;
		const uintptr_t m_bSpottedByMask				= hazedumper::netvars::m_bSpottedByMask;
		const uintptr_t m_bStartedArming				= hazedumper::netvars::m_bStartedArming;
		const uintptr_t m_bUseCustomAutoExposureMax		= hazedumper::netvars::m_bUseCustomAutoExposureMax;
		const uintptr_t m_bUseCustomAutoExposureMin		= hazedumper::netvars::m_bUseCustomAutoExposureMin;
		const uintptr_t m_bUseCustomBloomScale			= hazedumper::netvars::m_bUseCustomBloomScale;
		const uintptr_t m_clrRender						= hazedumper::netvars::m_clrRender;
		const uintptr_t m_dwBoneMatrix					= hazedumper::netvars::m_dwBoneMatrix;
		const uintptr_t m_fAccuracyPenalty				= hazedumper::netvars::m_fAccuracyPenalty;
		const uintptr_t m_fFlags						= hazedumper::netvars::m_fFlags;
		const uintptr_t m_flC4Blow						= hazedumper::netvars::m_flC4Blow;
		const uintptr_t m_flCustomAutoExposureMax		= hazedumper::netvars::m_flCustomAutoExposureMax;
		const uintptr_t m_flCustomAutoExposureMin		= hazedumper::netvars::m_flCustomAutoExposureMin;
		const uintptr_t m_flCustomBloomScale			= hazedumper::netvars::m_flCustomBloomScale;
		const uintptr_t m_flDefuseCountDown				= hazedumper::netvars::m_flDefuseCountDown;
		const uintptr_t m_flDefuseLength				= hazedumper::netvars::m_flDefuseLength;
		const uintptr_t m_flFallbackWear				= hazedumper::netvars::m_flFallbackWear;
		const uintptr_t m_flFlashDuration				= hazedumper::netvars::m_flFlashDuration;
		const uintptr_t m_flFlashMaxAlpha				= hazedumper::netvars::m_flFlashMaxAlpha;
		const uintptr_t m_flLastBoneSetupTime			= hazedumper::netvars::m_flLastBoneSetupTime;
		const uintptr_t m_flLowerBodyYawTarget			= hazedumper::netvars::m_flLowerBodyYawTarget;
		const uintptr_t m_flNextAttack					= hazedumper::netvars::m_flNextAttack;
		const uintptr_t m_flNextPrimaryAttack			= hazedumper::netvars::m_flNextPrimaryAttack;
		const uintptr_t m_flSimulationTime				= hazedumper::netvars::m_flSimulationTime;
		const uintptr_t m_flTimerLength					= hazedumper::netvars::m_flTimerLength;
		const uintptr_t m_hActiveWeapon					= hazedumper::netvars::m_hActiveWeapon;
		const uintptr_t m_hBombDefuser					= hazedumper::netvars::m_hBombDefuser;
		const uintptr_t m_hMyWeapons					= hazedumper::netvars::m_hMyWeapons;
		const uintptr_t m_hObserverTarget				= hazedumper::netvars::m_hObserverTarget;
		const uintptr_t m_hOwner						= hazedumper::netvars::m_hOwner;
		const uintptr_t m_hOwnerEntity					= hazedumper::netvars::m_hOwnerEntity;
		const uintptr_t m_hViewModel					= hazedumper::netvars::m_hViewModel;
		const uintptr_t m_iAccountID					= hazedumper::netvars::m_iAccountID;
		const uintptr_t m_iClip1						= hazedumper::netvars::m_iClip1;
		const uintptr_t m_iCompetitiveRanking			= hazedumper::netvars::m_iCompetitiveRanking;
		const uintptr_t m_iCompetitiveWins				= hazedumper::netvars::m_iCompetitiveWins;
		const uintptr_t m_iCrosshairId					= hazedumper::netvars::m_iCrosshairId;
		const uintptr_t m_iDefaultFOV					= hazedumper::netvars::m_iDefaultFOV;
		const uintptr_t m_iEntityQuality				= hazedumper::netvars::m_iEntityQuality;
		const uintptr_t m_iFOV 							= hazedumper::netvars::m_iFOV;
		const uintptr_t m_iFOVStart						= hazedumper::netvars::m_iFOVStart;
		const uintptr_t m_iGlowIndex					= hazedumper::netvars::m_iGlowIndex;
		const uintptr_t m_iHealth						= hazedumper::netvars::m_iHealth;
		const uintptr_t m_iItemDefinitionIndex			= hazedumper::netvars::m_iItemDefinitionIndex;
		const uintptr_t m_iItemIDHigh					= hazedumper::netvars::m_iItemIDHigh;
		const uintptr_t m_iMostRecentModelBoneCounter	= hazedumper::netvars::m_iMostRecentModelBoneCounter;
		const uintptr_t m_iObserverMode					= hazedumper::netvars::m_iObserverMode;
		const uintptr_t m_iShotsFired					= hazedumper::netvars::m_iShotsFired;
		const uintptr_t m_iState						= hazedumper::netvars::m_iState;
		const uintptr_t m_iTeamNum						= hazedumper::netvars::m_iTeamNum;
		const uintptr_t m_lifeState						= hazedumper::netvars::m_lifeState;
		const uintptr_t m_nBombSite						= hazedumper::netvars::m_nBombSite;
		const uintptr_t m_nFallbackPaintKit				= hazedumper::netvars::m_nFallbackPaintKit;
		const uintptr_t m_nFallbackSeed					= hazedumper::netvars::m_nFallbackSeed;
		const uintptr_t m_nFallbackStatTrak				= hazedumper::netvars::m_nFallbackStatTrak;
		const uintptr_t m_nForceBone					= hazedumper::netvars::m_nForceBone;
		const uintptr_t m_nTickBase						= hazedumper::netvars::m_nTickBase;
		const uintptr_t m_nViewModelIndex				= hazedumper::netvars::m_nViewModelIndex;
		const uintptr_t m_rgflCoordinateFrame			= hazedumper::netvars::m_rgflCoordinateFrame;
		const uintptr_t m_szCustomName					= hazedumper::netvars::m_szCustomName;
		const uintptr_t m_szLastPlaceName				= hazedumper::netvars::m_szLastPlaceName;
		const uintptr_t m_thirdPersonViewAngles			= hazedumper::netvars::m_thirdPersonViewAngles;
		const uintptr_t m_vecOrigin						= hazedumper::netvars::m_vecOrigin;
		const uintptr_t m_vecVelocity					= hazedumper::netvars::m_vecVelocity;
		const uintptr_t m_vecViewOffset					= hazedumper::netvars::m_vecViewOffset;
		const uintptr_t m_viewPunchAngle				= hazedumper::netvars::m_viewPunchAngle;
		const uintptr_t m_zoomLevel						= hazedumper::netvars::m_zoomLevel;
	}

	namespace Signatures {
		const uintptr_t anim_overlays						= hazedumper::signatures::anim_overlays;
		const uintptr_t clientstate_choked_commands			= hazedumper::signatures::clientstate_choked_commands;
		const uintptr_t clientstate_delta_ticks				= hazedumper::signatures::clientstate_delta_ticks;
		const uintptr_t clientstate_last_outgoing_command	= hazedumper::signatures::clientstate_last_outgoing_command;
		const uintptr_t clientstate_net_channel				= hazedumper::signatures::clientstate_net_channel;
		const uintptr_t convar_name_hash_table				= hazedumper::signatures::convar_name_hash_table;
		const uintptr_t dwClientState						= hazedumper::signatures::dwClientState;
		const uintptr_t dwClientState_GetLocalPlayer		= hazedumper::signatures::dwClientState_GetLocalPlayer;
		const uintptr_t dwClientState_IsHLTV				= hazedumper::signatures::dwClientState_IsHLTV;
		const uintptr_t dwClientState_Map					= hazedumper::signatures::dwClientState_Map;
		const uintptr_t dwClientState_MapDirectory			= hazedumper::signatures::dwClientState_MapDirectory;
		const uintptr_t dwClientState_MaxPlayer				= hazedumper::signatures::dwClientState_MaxPlayer;
		const uintptr_t dwClientState_PlayerInfo			= hazedumper::signatures::dwClientState_PlayerInfo;
		const uintptr_t dwClientState_State					= hazedumper::signatures::dwClientState_State;
		const uintptr_t dwClientState_ViewAngles			= hazedumper::signatures::dwClientState_ViewAngles;
		const uintptr_t dwEntityList						= hazedumper::signatures::dwEntityList;
		const uintptr_t dwForceAttack						= hazedumper::signatures::dwForceAttack;
		const uintptr_t dwForceAttack2						= hazedumper::signatures::dwForceAttack2;
		const uintptr_t dwForceBackward						= hazedumper::signatures::dwForceBackward;
		const uintptr_t dwForceForward						= hazedumper::signatures::dwForceForward;
		const uintptr_t dwForceJump							= hazedumper::signatures::dwForceJump;
		const uintptr_t dwForceLeft							= hazedumper::signatures::dwForceLeft;
		const uintptr_t dwForceRight						= hazedumper::signatures::dwForceRight;
		const uintptr_t dwGameDir							= hazedumper::signatures::dwGameDir;
		const uintptr_t dwGameRulesProxy					= hazedumper::signatures::dwGameRulesProxy;
		const uintptr_t dwGetAllClasses						= hazedumper::signatures::dwGetAllClasses;
		const uintptr_t dwGlobalVars						= hazedumper::signatures::dwGlobalVars;
		const uintptr_t dwGlowObjectManager					= hazedumper::signatures::dwGlowObjectManager;
		const uintptr_t dwInput								= hazedumper::signatures::dwInput;
		const uintptr_t dwInterfaceLinkList					= hazedumper::signatures::dwInterfaceLinkList;
		const uintptr_t dwLocalPlayer						= hazedumper::signatures::dwLocalPlayer;
		const uintptr_t dwMouseEnable						= hazedumper::signatures::dwMouseEnable;
		const uintptr_t dwMouseEnablePtr					= hazedumper::signatures::dwMouseEnablePtr;
		const uintptr_t dwPlayerResource					= hazedumper::signatures::dwPlayerResource;
		const uintptr_t dwRadarBase							= hazedumper::signatures::dwRadarBase;
		const uintptr_t dwSensitivity						= hazedumper::signatures::dwSensitivity;
		const uintptr_t dwSensitivityPtr					= hazedumper::signatures::dwSensitivityPtr;
		const uintptr_t dwSetClanTag						= hazedumper::signatures::dwSetClanTag;
		const uintptr_t dwViewMatrix						= hazedumper::signatures::dwViewMatrix;
		const uintptr_t dwWeaponTable						= hazedumper::signatures::dwWeaponTable;
		const uintptr_t dwWeaponTableIndex					= hazedumper::signatures::dwWeaponTableIndex;
		const uintptr_t dwYawPtr							= hazedumper::signatures::dwYawPtr;
		const uintptr_t dwZoomSensitivityRatioPtr			= hazedumper::signatures::dwZoomSensitivityRatioPtr;
		const uintptr_t dwbSendPackets						= hazedumper::signatures::dwbSendPackets;
		const uintptr_t dwppDirect3DDevice9					= hazedumper::signatures::dwppDirect3DDevice9;
		const uintptr_t find_hud_element					= hazedumper::signatures::find_hud_element;
		const uintptr_t force_update_spectator_glow			= hazedumper::signatures::force_update_spectator_glow;
		const uintptr_t interface_engine_cvar				= hazedumper::signatures::interface_engine_cvar;
		const uintptr_t is_c4_owner							= hazedumper::signatures::is_c4_owner;
		const uintptr_t m_bDormant							= hazedumper::signatures::m_bDormant;
		const uintptr_t m_flSpawnTime						= hazedumper::signatures::m_flSpawnTime;
		const uintptr_t m_pStudioHdr						= hazedumper::signatures::m_pStudioHdr;
		const uintptr_t m_pitchClassPtr						= hazedumper::signatures::m_pitchClassPtr;
		const uintptr_t m_yawClassPtr						= hazedumper::signatures::m_yawClassPtr;
		const uintptr_t model_ambient_min					= hazedumper::signatures::model_ambient_min;
		const uintptr_t set_abs_angles						= hazedumper::signatures::set_abs_angles;
		const uintptr_t set_abs_origin						= hazedumper::signatures::set_abs_origin;
	}
}

#endif//__OFFSETS__
