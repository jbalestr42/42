#include "Vector3.hpp"
#include <cmath>

Vector3::Vector3(void) :
	Vector3(0.f, 0.f, 0.f)
{}

Vector3::Vector3(float x, float y, float z) :
	x(x),
	y(y),
	z(z)
{}

Vector3::Vector3(Vector3 const & vector)
{
	*this = vector;
}

float Vector3::length(void)
{
	return (std::sqrt(x * x + y * y + z * z));
}

void Vector3::normalize(void)
{
	float len = length();
	x /= len;
	y /= len;
	z /= len;
}

Vector3 & Vector3::operator=(Vector3 const & vector)
{
	x = vector.x;
	y = vector.y;
	z = vector.z;
	return (*this);
}

Vector3 & Vector3::operator+=(Vector3 const & vector3)
{
	x += vector3.x;
	y += vector3.y;
	z += vector3.z;
	return (*this);
}

Vector3 & Vector3::operator*=(Vector3 const & vector3)
{
	x *= vector3.x;
	y *= vector3.y;
	z *= vector3.z;
	return (*this);
}

Vector3 & Vector3::operator-=(Vector3 const & vector3)
{
	x -= vector3.x;
	y -= vector3.y;
	z -= vector3.z;
	return (*this);
}

Vector3 Vector3::operator+(Vector3 const & vector3)
{
	return (Vector3(x + vector3.x, y + vector3.y, z + vector3.z));
}

Vector3 Vector3::operator*(Vector3 const & vector3)
{
	return (Vector3(x * vector3.x, y * vector3.y, z * vector3.z));
}

Vector3 Vector3::operator*(float factor)
{
	return (Vector3(x * factor, y * factor, z * factor));
}

Vector3 Vector3::operator-(Vector3 const & vector3)
{
	return (Vector3(x - vector3.x, y - vector3.y, z - vector3.z));
}

Vector3 Vector3::operator-(void)
{
	return (Vector3(-x, -y, -z));
}

std::ostream & operator<<(std::ostream & out, Vector3 const & vector)
{
	out << "Vector3(" << vector.x  << ", " << vector.y << ", " << vector.z << ")";
	return out;
}
