#ifndef __VECTOR__
#define __VECTOR__

#include "Singleton.hpp"

class Vector3_t {
public:
	float x, y, z;

	Vector3_t( void );
	Vector3_t( float X, float Y, float Z );

	void Init( float X = 0.f, float Y = 0.f, float Z = 0.f );

	float Distance( Vector3_t a, Vector3_t b );
};

#endif//__VECTOR__
