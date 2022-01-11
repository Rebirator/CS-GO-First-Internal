#ifndef __SDK_INTERFACES_ICHLCLIENT_HPP__
#define __SDK_INTERFACES_ICHLCLIENT_HPP__

#include "..\..\VirtualMethod.hpp"

#include "../Game/ClientClass.hpp"

class ICHLClient {
    enum Indices : size_t {
		INIT						= 0,
		LEVELINITPREENTITY			= 5,
		LEVELINITPOSTENTITY			= 6,
		LEVELSHUTDOWN				= 7,
		GETALLCLASSES				= 8,
		HUDPROCESSINPUT				= 10,
		INACTIVATEMOUSE				= 16,
		INKEYEVENT					= 20,
		CREATEMOVE					= 21,
		WRITEUSERCMDDELTATOBUFFER	= 24,
		RENDERVIEW					= 27,
		FRAMESTAGENOTIFY			= 37,
		DISPATCHUSERMESSAGE			= 38,
    };
public:
	VIRTUAL_METHOD( CClientClass*, GetAllClasses, GETALLCLASSES, ( this ) );
	VIRTUAL_METHOD( bool, WriteUsercmdDeltaToBuffer, WRITEUSERCMDDELTATOBUFFER, ( this, slot, buf, from, to, is_new_command ), int slot, void* buf, int from, int to, bool is_new_command );
};

#endif  __SDK_INTERFACES_ICHLCLIENT_HPP__
