#ifndef __VECTOR__
#define __VECTOR__

#include "Singleton.hpp"

class Vector3 : public _Singleton_< Vector3 > {
public:
	float x, y, z;

	Vector3( void );
	Vector3( float X, float Y, float Z );

	void Init( float X = 0.f, float Y = 0.f, float Z = 0.f );

	float Distance( Vector3 a, Vector3 b );
};

#endif//__VECTOR__
