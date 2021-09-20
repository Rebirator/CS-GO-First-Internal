#ifndef __OFFSETS__
#define __OFFSETS__

#include <Windows.h>
#include "Hazedumper.hpp"
#include "..\Utils\Defines.hpp"
#include "Entity.hpp"

namespace g_Game {
	const uintptr GameModule						= ( uintptr )GetModuleHandle( L"client.dll" );
}

namespace g_Netvars {
	const uintptr cs_gamerules_data					= hazedumper::netvars::cs_gamerules_data;
	const uintptr m_ArmorValue						= hazedumper::netvars::m_ArmorValue;
	const uintptr m_Collision						= hazedumper::netvars::m_Collision;
	const uintptr m_CollisionGroup					= hazedumper::netvars::m_CollisionGroup;
	const uintptr m_Local							= hazedumper::netvars::m_Local;
	const uintptr m_MoveType						= hazedumper::netvars::m_MoveType;
	const uintptr m_OriginalOwnerXuidHigh			= hazedumper::netvars::m_OriginalOwnerXuidHigh;
	const uintptr m_OriginalOwnerXuidLow			= hazedumper::netvars::m_OriginalOwnerXuidLow;
	const uintptr m_SurvivalGameRuleDecisionTypes	= hazedumper::netvars::m_SurvivalGameRuleDecisionTypes;
	const uintptr m_SurvivalRules					= hazedumper::netvars::m_SurvivalRules;
	const uintptr m_aimPunchAngle					= hazedumper::netvars::m_aimPunchAngle;
	const uintptr m_aimPunchAngleVel				= hazedumper::netvars::m_aimPunchAngleVel;
	const uintptr m_angEyeAnglesX					= hazedumper::netvars::m_angEyeAnglesX;
	const uintptr m_angEyeAnglesY					= hazedumper::netvars::m_angEyeAnglesY;
	const uintptr m_bBombDefused					= hazedumper::netvars::m_bBombDefused;
	const uintptr m_bBombPlanted					= hazedumper::netvars::m_bBombPlanted;
	const uintptr m_bBombTicking					= hazedumper::netvars::m_bBombTicking;
	const uintptr m_bFreezePeriod					= hazedumper::netvars::m_bFreezePeriod;
	const uintptr m_bGunGameImmunity				= hazedumper::netvars::m_bGunGameImmunity;
	const uintptr m_bHasDefuser						= hazedumper::netvars::m_bHasDefuser;
	const uintptr m_bHasHelmet						= hazedumper::netvars::m_bHasHelmet;
	const uintptr m_bInReload						= hazedumper::netvars::m_bInReload;
	const uintptr m_bIsDefusing						= hazedumper::netvars::m_bIsDefusing;
	const uintptr m_bIsQueuedMatchmaking			= hazedumper::netvars::m_bIsQueuedMatchmaking;
	const uintptr m_bIsScoped						= hazedumper::netvars::m_bIsScoped;
	const uintptr m_bIsValveDS						= hazedumper::netvars::m_bIsValveDS;
	const uintptr m_bSpotted						= hazedumper::netvars::m_bSpotted;
	const uintptr m_bSpottedByMask					= hazedumper::netvars::m_bSpottedByMask;
	const uintptr m_bStartedArming					= hazedumper::netvars::m_bStartedArming;
	const uintptr m_bUseCustomAutoExposureMax		= hazedumper::netvars::m_bUseCustomAutoExposureMax;
	const uintptr m_bUseCustomAutoExposureMin		= hazedumper::netvars::m_bUseCustomAutoExposureMin;
	const uintptr m_bUseCustomBloomScale			= hazedumper::netvars::m_bUseCustomBloomScale;
	const uintptr m_clrRender						= hazedumper::netvars::m_clrRender;
	const uintptr m_dwBoneMatrix					= hazedumper::netvars::m_dwBoneMatrix;
	const uintptr m_fAccuracyPenalty				= hazedumper::netvars::m_fAccuracyPenalty;
	const uintptr m_fFlags							= hazedumper::netvars::m_fFlags;
	const uintptr m_flC4Blow						= hazedumper::netvars::m_flC4Blow;
	const uintptr m_flCustomAutoExposureMax			= hazedumper::netvars::m_flCustomAutoExposureMax;
	const uintptr m_flCustomAutoExposureMin			= hazedumper::netvars::m_flCustomAutoExposureMin;
	const uintptr m_flCustomBloomScale				= hazedumper::netvars::m_flCustomBloomScale;
	const uintptr m_flDefuseCountDown				= hazedumper::netvars::m_flDefuseCountDown;
	const uintptr m_flDefuseLength					= hazedumper::netvars::m_flDefuseLength;
	const uintptr m_flFallbackWear					= hazedumper::netvars::m_flFallbackWear;
	const uintptr m_flFlashDuration					= hazedumper::netvars::m_flFlashDuration;
	const uintptr m_flFlashMaxAlpha					= hazedumper::netvars::m_flFlashMaxAlpha;
	const uintptr m_flLastBoneSetupTime				= hazedumper::netvars::m_flLastBoneSetupTime;
	const uintptr m_flLowerBodyYawTarget			= hazedumper::netvars::m_flLowerBodyYawTarget;
	const uintptr m_flNextAttack					= hazedumper::netvars::m_flNextAttack;
	const uintptr m_flNextPrimaryAttack				= hazedumper::netvars::m_flNextPrimaryAttack;
	const uintptr m_flSimulationTime				= hazedumper::netvars::m_flSimulationTime;
	const uintptr m_flTimerLength					= hazedumper::netvars::m_flTimerLength;
	const uintptr m_hActiveWeapon					= hazedumper::netvars::m_hActiveWeapon;
	const uintptr m_hBombDefuser					= hazedumper::netvars::m_hBombDefuser;
	const uintptr m_hMyWeapons						= hazedumper::netvars::m_hMyWeapons;
	const uintptr m_hObserverTarget					= hazedumper::netvars::m_hObserverTarget;
	const uintptr m_hOwner							= hazedumper::netvars::m_hOwner;
	const uintptr m_hOwnerEntity					= hazedumper::netvars::m_hOwnerEntity;
	const uintptr m_hViewModel						= hazedumper::netvars::m_hViewModel;
	const uintptr m_iAccountID						= hazedumper::netvars::m_iAccountID;
	const uintptr m_iClip1							= hazedumper::netvars::m_iClip1;
	const uintptr m_iCompetitiveRanking				= hazedumper::netvars::m_iCompetitiveRanking;
	const uintptr m_iCompetitiveWins				= hazedumper::netvars::m_iCompetitiveWins;
	const uintptr m_iCrosshairId					= hazedumper::netvars::m_iCrosshairId;
	const uintptr m_iDefaultFOV						= hazedumper::netvars::m_iDefaultFOV;
	const uintptr m_iEntityQuality					= hazedumper::netvars::m_iEntityQuality;
	const uintptr m_iFOVStart						= hazedumper::netvars::m_iFOVStart;
	const uintptr m_iGlowIndex						= hazedumper::netvars::m_iGlowIndex;
	const uintptr m_iHealth							= hazedumper::netvars::m_iHealth;
	const uintptr m_iItemDefinitionIndex			= hazedumper::netvars::m_iItemDefinitionIndex;
	const uintptr m_iItemIDHigh						= hazedumper::netvars::m_iItemIDHigh;
	const uintptr m_iMostRecentModelBoneCounter		= hazedumper::netvars::m_iMostRecentModelBoneCounter;
	const uintptr m_iObserverMode					= hazedumper::netvars::m_iObserverMode;
	const uintptr m_iShotsFired						= hazedumper::netvars::m_iShotsFired;
	const uintptr m_iState							= hazedumper::netvars::m_iState;
	const uintptr m_iTeamNum						= hazedumper::netvars::m_iTeamNum;
	const uintptr m_lifeState						= hazedumper::netvars::m_lifeState;
	const uintptr m_nBombSite						= hazedumper::netvars::m_nBombSite;
	const uintptr m_nFallbackPaintKit				= hazedumper::netvars::m_nFallbackPaintKit;
	const uintptr m_nFallbackSeed					= hazedumper::netvars::m_nFallbackSeed;
	const uintptr m_nFallbackStatTrak				= hazedumper::netvars::m_nFallbackStatTrak;
	const uintptr m_nForceBone						= hazedumper::netvars::m_nForceBone;
	const uintptr m_nTickBase						= hazedumper::netvars::m_nTickBase;
	const uintptr m_nViewModelIndex					= hazedumper::netvars::m_nViewModelIndex;
	const uintptr m_rgflCoordinateFrame				= hazedumper::netvars::m_rgflCoordinateFrame;
	const uintptr m_szCustomName					= hazedumper::netvars::m_szCustomName;
	const uintptr m_szLastPlaceName					= hazedumper::netvars::m_szLastPlaceName;
	const uintptr m_thirdPersonViewAngles			= hazedumper::netvars::m_thirdPersonViewAngles;
	const uintptr m_vecOrigin						= hazedumper::netvars::m_vecOrigin;
	const uintptr m_vecVelocity						= hazedumper::netvars::m_vecVelocity;
	const uintptr m_vecViewOffset					= hazedumper::netvars::m_vecViewOffset;
	const uintptr m_viewPunchAngle					= hazedumper::netvars::m_viewPunchAngle;
	const uintptr m_zoomLevel						= hazedumper::netvars::m_zoomLevel;
}

namespace g_Signatures {
	const uintptr anim_overlays						= hazedumper::signatures::anim_overlays;
	const uintptr clientstate_choked_commands		= hazedumper::signatures::clientstate_choked_commands;
	const uintptr clientstate_delta_ticks			= hazedumper::signatures::clientstate_delta_ticks;
	const uintptr clientstate_last_outgoing_command = hazedumper::signatures::clientstate_last_outgoing_command;
	const uintptr clientstate_net_channel			= hazedumper::signatures::clientstate_net_channel;
	const uintptr convar_name_hash_table			= hazedumper::signatures::convar_name_hash_table;
	const uintptr dwClientState						= hazedumper::signatures::dwClientState;
	const uintptr dwClientState_GetLocalPlayer		= hazedumper::signatures::dwClientState_GetLocalPlayer;
	const uintptr dwClientState_IsHLTV				= hazedumper::signatures::dwClientState_IsHLTV;
	const uintptr dwClientState_Map					= hazedumper::signatures::dwClientState_Map;
	const uintptr dwClientState_MapDirectory		= hazedumper::signatures::dwClientState_MapDirectory;
	const uintptr dwClientState_MaxPlayer			= hazedumper::signatures::dwClientState_MaxPlayer;
	const uintptr dwClientState_PlayerInfo			= hazedumper::signatures::dwClientState_PlayerInfo;
	const uintptr dwClientState_State				= hazedumper::signatures::dwClientState_State;
	const uintptr dwClientState_ViewAngles			= hazedumper::signatures::dwClientState_ViewAngles;
	const uintptr dwEntityList						= hazedumper::signatures::dwEntityList;
	const uintptr dwForceAttack						= hazedumper::signatures::dwForceAttack;
	const uintptr dwForceAttack2					= hazedumper::signatures::dwForceAttack2;
	const uintptr dwForceBackward					= hazedumper::signatures::dwForceBackward;
	const uintptr dwForceForward					= hazedumper::signatures::dwForceForward;
	const uintptr dwForceJump						= hazedumper::signatures::dwForceJump;
	const uintptr dwForceLeft						= hazedumper::signatures::dwForceLeft;
	const uintptr dwForceRight						= hazedumper::signatures::dwForceRight;
	const uintptr dwGameDir							= hazedumper::signatures::dwGameDir;
	const uintptr dwGameRulesProxy					= hazedumper::signatures::dwGameRulesProxy;
	const uintptr dwGetAllClasses					= hazedumper::signatures::dwGetAllClasses;
	const uintptr dwGlobalVars						= hazedumper::signatures::dwGlobalVars;
	const uintptr dwGlowObjectManager				= hazedumper::signatures::dwGlowObjectManager;
	const uintptr dwInput							= hazedumper::signatures::dwInput;
	const uintptr dwInterfaceLinkList				= hazedumper::signatures::dwInterfaceLinkList;
	const uintptr dwLocalPlayer						= hazedumper::signatures::dwLocalPlayer;
	const uintptr dwMouseEnable						= hazedumper::signatures::dwMouseEnable;
	const uintptr dwMouseEnablePtr					= hazedumper::signatures::dwMouseEnablePtr;
	const uintptr dwPlayerResource					= hazedumper::signatures::dwPlayerResource;
	const uintptr dwRadarBase						= hazedumper::signatures::dwRadarBase;
	const uintptr dwSensitivity						= hazedumper::signatures::dwSensitivity;
	const uintptr dwSensitivityPtr					= hazedumper::signatures::dwSensitivityPtr;
	const uintptr dwSetClanTag						= hazedumper::signatures::dwSetClanTag;
	const uintptr dwViewMatrix						= hazedumper::signatures::dwViewMatrix;
	const uintptr dwWeaponTable						= hazedumper::signatures::dwWeaponTable;
	const uintptr dwWeaponTableIndex				= hazedumper::signatures::dwWeaponTableIndex;
	const uintptr dwYawPtr							= hazedumper::signatures::dwYawPtr;
	const uintptr dwZoomSensitivityRatioPtr			= hazedumper::signatures::dwZoomSensitivityRatioPtr;
	const uintptr dwbSendPackets					= hazedumper::signatures::dwbSendPackets;
	const uintptr dwppDirect3DDevice9				= hazedumper::signatures::dwppDirect3DDevice9;
	const uintptr find_hud_element					= hazedumper::signatures::find_hud_element;
	const uintptr force_update_spectator_glow		= hazedumper::signatures::force_update_spectator_glow;
	const uintptr interface_engine_cvar				= hazedumper::signatures::interface_engine_cvar;
	const uintptr is_c4_owner						= hazedumper::signatures::is_c4_owner;
	const uintptr m_bDormant						= hazedumper::signatures::m_bDormant;
	const uintptr m_flSpawnTime						= hazedumper::signatures::m_flSpawnTime;
	const uintptr m_pStudioHdr						= hazedumper::signatures::m_pStudioHdr;
	const uintptr m_pitchClassPtr					= hazedumper::signatures::m_pitchClassPtr;
	const uintptr m_yawClassPtr						= hazedumper::signatures::m_yawClassPtr;
	const uintptr model_ambient_min					= hazedumper::signatures::model_ambient_min;
	const uintptr set_abs_angles					= hazedumper::signatures::set_abs_angles;
	const uintptr set_abs_origin					= hazedumper::signatures::set_abs_origin;
}

#endif//__OFFSETS__
