#include <cmath>
#include "Vector3.hpp"
#include "Defines.hpp"

Vector3::Vector3( float X, float Y, float Z ) {
	this->x = X;
	this->y = Y;
	this->z = Z;
}

Vector3::Vector3( void ) {
	Vector3::Init( );
};

void Vector3::Init( float X, float Y, float Z ) {
	this->x = X;
	this->y = Y;
	this->z = Z;
}

float Vector3::Distance( Vector3 a, Vector3 b ) {
	return CS_INCH_TO_METERS ( 
		sqrt( pow( a.x - b.x, 2) + pow( a.y - b.y, 2) + pow( a.z - b.z, 2) )
	);
}

void Vector3::Normalize( ) {
	while ( y < -180 ) y += 360;
	while ( y > 180 ) y -= 360;
	if ( x < -89 ) y = -89;
	if ( x > 89 ) x = 89;
}
