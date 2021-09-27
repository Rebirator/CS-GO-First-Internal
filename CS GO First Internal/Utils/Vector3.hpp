#ifndef __VECTOR__
#define __VECTOR__

#include "Singleton.hpp"

class Vector3 : public _Singleton_< Vector3 > {
public:
	float x, y, z;

	Vector3( void );
	Vector3( float X, float Y, float Z );

	void Init( float X = 0.f, float Y = 0.f, float Z = 0.f );

	Vector3 operator + ( Vector3 a ) { return { x + a.x, y + a.y, z + a.z }; }
	Vector3 operator - ( Vector3 a ) { return { x - a.x, y - a.y, z - a.z }; }
	Vector3 operator * ( float a ) { return { x * a, y * a, z * a }; }
	Vector3 operator / ( float a ) { return { x / a, y / a, z / a }; }

	float Distance( Vector3 a, Vector3 b );
	float DistanceInchs( Vector3 a, Vector3 b );
	Vector3 CalculateAngles( Vector3 a, Vector3 b );

	void NormalizeAngles( );
};

#endif//__VECTOR__
