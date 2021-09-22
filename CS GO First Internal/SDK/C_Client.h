#ifndef __CLIENT__
#define __CLIENT__

#include "Offsets.hpp"
#include "..\Utils\Singleton.hpp"
#include <string>
#include <array>

class C_Client : public Singleton< C_Client > {
public:
	char*	GetMapName( );
	char*	GetMapDirectory();
	int		GetMaxClients( );

	C_Client*	Get( );
};

#endif//__CLIENT__
