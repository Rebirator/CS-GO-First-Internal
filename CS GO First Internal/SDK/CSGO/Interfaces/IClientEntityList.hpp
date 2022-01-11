#ifndef __SDK_INTERFACES_ICLIENTENTITYLIST_HPP__
#define __SDK_INTERFACES_ICLIENTENTITYLIST_HPP__

#include "../Cheat\CEntityPlayer.hpp"

#include "..\..\VirtualMethod.hpp"
#include "IClientNetworkable.hpp"
#include "IClientUnknown.hpp"

class IClientEntityList {
	enum Indicies : size_t {
		GETCLIENTNETWORKABLE			= 0,
		GETCLIENTNETWORKABLEFROMHANDLE  = 1,
		GETCLIENTUNKNOWNFROMHANDLE		= 2,
		GETCLIENTENTITY					= 3,
		GETCLIENTENTITYFROMHANDLE		= 4,
		NUMBEROFENTITIES				= 5,
		GETHIGHESTENTITYINDEX			= 6,
		SETMAXENTITIES					= 7,
		GETMAXENTITIES					= 8,
		GETCLIENTNETWORKABLEARRAY		= 9
	};
public:
	VIRTUAL_METHOD( IClientNetworkable*, GetClientNetworkable, GETCLIENTNETWORKABLE, ( this, entity_id ), int entity_id );

	VIRTUAL_METHOD( IClientNetworkable*, GetClientNetworkableFromHandle, GETCLIENTNETWORKABLEFROMHANDLE, ( this, entity ), void* entity );

	VIRTUAL_METHOD( IClientUnknown*, GetClientUnknownFromHandle, GETCLIENTUNKNOWNFROMHANDLE, ( this, entity ), void* entity );

	VIRTUAL_METHOD( CEntityPlayer*, GetClientEntity, GETCLIENTENTITY, ( this, entity_id ), int entity_id );

	VIRTUAL_METHOD( CEntityPlayer*, GetClientEntityFromHandle, GETCLIENTENTITYFROMHANDLE, ( this, entity ), void* entity );

	VIRTUAL_METHOD( int, NumberOfEntities, NUMBEROFENTITIES, ( this, include_non_networkable ), bool include_non_networkable );

	VIRTUAL_METHOD( int, GetHighestEntityIndex, GETHIGHESTENTITYINDEX, ( this ) );

	VIRTUAL_METHOD( void, SetMaxEntities, SETMAXENTITIES, ( this, max_ents ), int max_ents );

	VIRTUAL_METHOD( int, GetMaxEntities, GETMAXENTITIES, ( this ) );

	VIRTUAL_METHOD( void*, GetClientNetworkableArray, GETCLIENTNETWORKABLEARRAY, ( this ) );
};

#endif//__SDK_INTERFACES_ICLIENTENTITYLIST_HPP__
