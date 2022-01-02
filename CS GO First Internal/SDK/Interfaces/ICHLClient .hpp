#ifndef __SDK_INTERFACES_ICHLCLIENT_HPP__
#define __SDK_INTERFACES_ICHLCLIENT_HPP__

#include "../../Utils/Misc.hpp"

#include "../VirtualMethod.hpp"
#include "../Game/ClientClass.hpp"

class ICHLClient {
    enum Indices : size_t {
		INIT				= 0,
		LEVELINITPREENTITY	= 5,
		LEVELINITPOSTENTITY = 6,
		LEVELSHUTDOWN		= 7,
		GETALLCLASSES		= 8,
		HUDPROCESSINPUT		= 10,
		INACTIVATEMOUSE		= 16,
		INKEYEVENT			= 20,
		CREATEMOVE			= 21,
		RENDERVIEW			= 27,
		FRAMESTAGENOTIFY	= 37,
		DISPATCHUSERMESSAGE = 38,
		USRCMDTODELTABUFFER = 24
    };
public:
	VIRTUAL_METHOD( CClientClass*, GetAllClasses, GETALLCLASSES, ( this ) );
};

#endif  __SDK_INTERFACES_ICHLCLIENT_HPP__
