#ifndef __SDK_INTERFACES_ICLIENTENTITYLIST_HPP__
#define __SDK_INTERFACES_ICLIENTENTITYLIST_HPP__

#include "IClientNetworkable.hpp"
#include "IClientUnknown.hpp"
#include "../C_Entity.hpp"

class IClientEntityList {
public:
	virtual IClientNetworkable*	GetClientNetworkable( int entnum )					= 0;
	virtual IClientNetworkable*	GetClientNetworkableFromHandle( void* hEnt )		= 0;
	virtual IClientUnknown*		GetClientUnknownFromHandle( void* hEnt )			= 0;

	virtual C_Entity*			GetClientEntity( int ent_id )						= 0;
	virtual C_Entity*			GetClientEntityFromHandle( void* h_ent )			= 0;
	virtual int					NumberOfEntities( bool include_non_networkable )	= 0;
	virtual int					GetHighestEntityIndex( void )						= 0;
	virtual void				SetMaxEntities( int max_ents )						= 0;
	virtual int					GetMaxEntities( )									= 0;
	virtual void*				GetClientNetworkableArray( )						= 0; // virtual EntityCacheInfo_t
};

#endif//__SDK_INTERFACES_ICLIENTENTITYLIST_HPP__
