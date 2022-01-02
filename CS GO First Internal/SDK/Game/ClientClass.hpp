#ifndef __SDK_GAME_CLIENTCLASS_HPP__
#define __SDK_GAME_CLIENTCLASS_HPP__

#include "DTRecv.hpp"
#include "../Interfaces/IClientNetworkable.hpp"

using CreateClientClassFn = void*( * )( int entnum, int serialNum );
using CreateEventFn		  = void*( * )( );

class CClientClass {
public:
	CreateClientClassFn	m_pCreateFn;
	CreateEventFn		m_pCreateEventFn;	// Only called for event objects.
	char*				m_pNetworkName;
	RecvTable*			m_pRecvTable;
	CClientClass*		m_pNext;
	int					m_ClassID;			// Managed by the engine.
	const char*			m_pMapClassname;
};

#endif  __SDK_GAME_CLIENTCLASS_HPP__
