#ifndef __UTILS_VECTOR3_HP__
#define __UTILS_VECTOR3_HP__

#include <cmath>
#include "..\Defines.hpp"

class Vector3 {
public:
	float x, y, z;

	Vector3( ) { Vector3( 0.f, 0.f, 0.f ); }
	Vector3( float _x, float _y, float _z ) {
		this->x = _x;
		this->y = _y;
		this->z = _z;
	}

	Vector3 operator + ( Vector3 a ) { return { x + a.x, y + a.y, z + a.z }; }
	Vector3 operator - ( Vector3 a ) { return { x - a.x, y - a.y, z - a.z }; }
	Vector3 operator * ( float a ) { return { x * a, y * a, z * a }; }
	Vector3 operator / ( float a ) { return { x / a, y / a, z / a }; }

	float Distance( Vector3 target ) {
		return sqrt( pow( this->x - target.x, 2 ) + pow( this->y - target.y, 2 ) + pow( this->z - target.z, 2 ) );
	}

	float DistanceMeters( Vector3 target ) {
		return CS_INCH_TO_METERS( sqrt( pow( this->x - target.x, 2 ) + pow( this->y - target.y, 2 ) + pow( this->z - target.z, 2 ) ) );
	}

	Vector3 CalculateAngles( Vector3 target ) {
		Vector3 delta = target - *this;
		double hypotenuse = target.Distance( *this );

		double pitch = -atan2( delta.z, hypotenuse ) * ( 180 / PI );
		double yaw = atan2( delta.y, delta.x ) * ( 180 / PI );

		Vector3 angles = Vector3( ( float )pitch, ( float )yaw, 0.0f );
		angles.NormalizeAngles( );

		return angles;
	}

	Vector3 NormalizeAngles( ) {
		while ( this->y < -180 ) this->y = -180;
		while ( this->y > 180 ) this->y = 180;
		if ( this->x < -89 ) this->x = -89;
		if ( this->x > 89 ) this->x = 89;
		return *this;
	}
};

#endif __UTILS_VECTOR3_HP__
