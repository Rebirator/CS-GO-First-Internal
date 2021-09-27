#ifndef __MISC__
#define __MISC__

#include "..\Utils\Singleton.hpp"
#include "..\Utils\Defines.hpp"
#include "..\Utils\Vector3.hpp"

class F_Misc : public Singleton< F_Misc >  {
public:
	void BunnyHop( );
	void RadarHack( );
	void RecoilControlSystem( );
};

#endif//__MISC__
