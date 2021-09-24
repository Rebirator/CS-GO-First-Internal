#ifndef __CLIENT__
#define __CLIENT__

#include "Offsets.hpp"
#include "..\Utils\Singleton.hpp"
#include "..\Utils\Vector3.hpp"

class C_Client : public Singleton< C_Client > {
public:
	char*		GetMapName( );
	char*		GetMapDirectory();
	int			GetMaxClients( );
	Vector3		GetViewAngles( );
	void		SetViewAngles( Vector3 Angles );

	void		DoJump( );
	void		DoAttack1( );
	void		DoAttack2( );

	C_Client*	Get( );
};

#endif//__CLIENT__
