#include "Vector2.hpp"

Vector2::Vector2(void) :
	Vector2(0.f, 0.f)
{}

Vector2::Vector2(float x, float y) :
	x(x),
	y(y)
{}

Vector2::Vector2(Vector2 const & vector)
{
	*this = vector;
}

Vector2 & Vector2::operator=(Vector2 const & vector)
{
	x = vector.x;
	y = vector.y;
	return (*this);
}

Vector2 Vector2::operator*(float factor) const
{
	return (Vector2(x * factor, y * factor));
}

Vector2 Vector2::operator/(Vector2 const & vector2) const
{
	return (Vector2(x / vector2.x, y / vector2.y));
}

Vector2 operator/(float value, Vector2 const & vector2)
{
	return Vector2(value / vector2.x, value / vector2.y);
}
