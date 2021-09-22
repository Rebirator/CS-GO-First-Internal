#include <cmath>
#include "Vector.hpp"
#include "Defines.hpp"

Vector3_t::Vector3_t( float X, float Y, float Z ) 
{
	this->x = X;
	this->y = Y;
	this->z = Z;
}

Vector3_t::Vector3_t( void ) 
{
	Vector3_t::Init( );
};

void Vector3_t::Init( float X, float Y, float Z ) 
{
	this->x = X;
	this->y = Y;
	this->z = Z;
}

float Vector3_t::Distance( Vector3_t a, Vector3_t b ) 
{
	return CS_INCH_TO_METERS ( 
		sqrt( pow( a.x - b.x, 2) + pow( a.y - b.y, 2) + pow( a.z - b.z, 2) )
	);
}