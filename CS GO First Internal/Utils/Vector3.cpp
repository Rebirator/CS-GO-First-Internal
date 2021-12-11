#include <cmath>
#include "Vector3.hpp"
#include "Defines.hpp"

Vector3 g_vector3 { };

Vector3::Vector3( ) {
	Vector3::Init( 0.0f, 0.0f, 0.0f );
}
	
Vector3::Vector3( float x, float y, float z ) {
	this->x = x;
	this->y = y;
	this->z = z;
}

void Vector3::Init( float x, float y, float z ) {
	this->x = x;
	this->y = y;
	this->z = z;
}

float Vector3::Distance( Vector3 a, Vector3 b ) {
	return CS_INCH_TO_METERS ( 
		sqrt( pow( a.x - b.x, 2) + pow( a.y - b.y, 2) + pow( a.z - b.z, 2) )
	);
}

float Vector3::DistanceInchs( Vector3 a, Vector3 b ) {
	return ( float )( sqrt( pow( a.x - b.x, 2) + pow( a.y - b.y, 2) + pow( a.z - b.z, 2) ) );
}

Vector3 Vector3::CalculateAngles( Vector3 a, Vector3 b ) {
	Vector3 delta = b - a;
	double hypotenuse = this->DistanceInchs( b, a );

	double pitch = -atan2( delta.z, hypotenuse ) * ( 180 / PI );
	double yaw = atan2( delta.y, delta.x ) * ( 180 / PI );

	Vector3 angles = Vector3( ( float )pitch, ( float )yaw, 0.0f );
	angles.NormalizeAngles( );

	return Vector3( angles );
}

void Vector3::NormalizeAngles( ) {
	while ( this->y < -180 ) this->y = -180;
	while ( this->y > 180 ) this->y = 180;
	if ( this->x < -89 ) this->x = -89;
	if ( this->x > 89 ) this->x = 89;
}

Vector3 Vector3::NormalizeAngles( Vector3 angles ) {
	while ( angles.y < -180 ) angles.y = -180;
	while ( angles.y > 180 ) angles.y = 180;
	if ( angles.x < -89 ) angles.x = -89;
	if ( angles.x > 89 ) angles.x = 89;

	return angles;
}
