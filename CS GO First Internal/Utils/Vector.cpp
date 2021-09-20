#include <cmath>
#include "Vector.hpp"
#include "Defines.hpp"

Vector3_t::Vector3_t( void ) 
{

};

Vector3_t::Vector3_t( float X, float Y, float Z ) 
{
	this->x = X;
	this->y = Y;
	this->z = Z;
}

void Vector3_t::Init(float X, float Y, float Z) 
{
	this->x = X;
	this->y = Y;
	this->z = Z;
}

float Vector3_t::Distance( Vector3_t a, Vector3_t b ) 
{
	return float 
	( 
		CS_INCH_TO_METERS (
			abs( ( a.x - b.x ) + ( a.y - b.y ) + ( a.z - b.z ) ) 
		) 
	);
}