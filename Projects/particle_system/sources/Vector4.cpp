#include "Vector4.hpp"
#include <cmath>

Vector4::Vector4(void) :
	Vector4(0.f, 0.f, 0.f, 0.f)
{}

Vector4::Vector4(float x, float y, float z, float w) :
	x(x),
	y(y),
	z(z),
	w(w)
{}

Vector4::Vector4(Vector4 const & vector)
{
	*this = vector;
}

Vector4::Vector4(Vector4 && vector)
{
	*this = std::move(vector);
}

float Vector4::length(void)
{
	return (std::sqrt(x * x + y * y + z * z + w * w));
}

void Vector4::normalize(void)
{
	float len = length();
	x /= len;
	y /= len;
	z /= len;
	w /= len;
}

	Vector4 inverse(void);

Vector4 & Vector4::operator=(Vector4 const & vector)
{
	x = vector.x;
	y = vector.y;
	z = vector.z;
	w = vector.w;
	return (*this);
}

Vector4 & Vector4::operator=(Vector4 && vector)
{
	x = std::move(vector.x);
	y = std::move(vector.y);
	z = std::move(vector.z);
	w = std::move(vector.w);
	return (*this);
}

Vector4 & Vector4::operator+=(Vector4 const & vector4)
{
	x += vector4.x;
	y += vector4.y;
	z += vector4.z;
	w += vector4.w;
	return (*this);
}

Vector4 & Vector4::operator*=(Vector4 const & vector4)
{
	x *= vector4.x;
	y *= vector4.y;
	z *= vector4.z;
	w *= vector4.w;
	return (*this);
}

Vector4 & Vector4::operator-=(Vector4 const & vector4)
{
	x -= vector4.x;
	y -= vector4.y;
	z -= vector4.z;
	w -= vector4.w;
	return (*this);
}

Vector4 Vector4::operator+(Vector4 const & vector4) const
{
	return (Vector4(x + vector4.x, y + vector4.y, z + vector4.z, w + vector4.w));
}

Vector4 Vector4::operator*(Matrix const & matrix) const
{
	Vector4 res;

	res.x += matrix.getMatrix()[0 * 4 + 0] * x;
	res.x += matrix.getMatrix()[0 * 4 + 1] * y;
	res.x += matrix.getMatrix()[0 * 4 + 2] * z;
	res.x += matrix.getMatrix()[0 * 4 + 3] * w;

	res.y += matrix.getMatrix()[1 * 4 + 0] * x;
	res.y += matrix.getMatrix()[1 * 4 + 1] * y;
	res.y += matrix.getMatrix()[1 * 4 + 2] * z;
	res.y += matrix.getMatrix()[1 * 4 + 3] * w;

	res.z += matrix.getMatrix()[2 * 4 + 0] * x;
	res.z += matrix.getMatrix()[2 * 4 + 1] * y;
	res.z += matrix.getMatrix()[2 * 4 + 2] * z;
	res.z += matrix.getMatrix()[2 * 4 + 3] * w;

	res.w += matrix.getMatrix()[3 * 4 + 0] * x;
	res.w += matrix.getMatrix()[3 * 4 + 1] * y;
	res.w += matrix.getMatrix()[3 * 4 + 2] * z;
	res.w += matrix.getMatrix()[3 * 4 + 3] * w;

	return (res);
}

Vector4 Vector4::operator*(Vector4 const & vector4) const
{
	return (Vector4(x * vector4.x, y * vector4.y, z * vector4.z, w * vector4.w));
}

Vector4 Vector4::operator*(float factor) const
{
	return (Vector4(x * factor, y * factor, z * factor, w * factor));
}

Vector4 Vector4::operator-(Vector4 const & vector4) const
{
	return (Vector4(x - vector4.x, y - vector4.y, z - vector4.z, w - vector4.w));
}

Vector4 Vector4::operator-(void) const
{
	return (Vector4(-x, -y, -z, -w));
}

std::ostream & operator<<(std::ostream & out, Vector4 const & vector)
{
	out << "Vector4(" << vector.x  << ", " << vector.y << ", " << vector.z << ", " << vector.w << ")";
	return out;
}

Vector4 operator/(float value, Vector4 const & vector4)
{
	return Vector4(value / vector4.x, value / vector4.y, value / vector4.z, value / vector4.w);
}
