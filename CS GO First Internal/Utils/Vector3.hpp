#ifndef __VECTOR__
#define __VECTOR__

class Vector3 {
public:
	float x, y, z;

	Vector3( );
	Vector3( float x, float y, float z );

	void Init( float X = 0.f, float Y = 0.f, float Z = 0.f );

	Vector3 operator + ( Vector3 a ) { return { x + a.x, y + a.y, z + a.z }; }
	Vector3 operator - ( Vector3 a ) { return { x - a.x, y - a.y, z - a.z }; }
	Vector3 operator * ( float a ) { return { x * a, y * a, z * a }; }
	Vector3 operator / ( float a ) { return { x / a, y / a, z / a }; }

	float Distance( Vector3 a, Vector3 b );
	float DistanceInchs( Vector3 a, Vector3 b );
	Vector3 CalculateAngles( Vector3 a, Vector3 b );

	void NormalizeAngles( );
	Vector3 NormalizeAngles( Vector3 angles );
}; extern Vector3 g_vector3;

#endif//__VECTOR__
