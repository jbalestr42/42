#ifndef VECTOR2_HPP
# define VECTOR2_HPP

# include <iostream>

class Vector2
{
public:
	Vector2(void);
	Vector2(float x, float y);
	Vector2(Vector2 const & vector2);
	~Vector2(void) = default;

	Vector2 & operator=(Vector2 const & vector2);
	Vector2 operator*(float factor) const;
	Vector2 operator/(Vector2 const & vector2) const;
	Vector2 operator-(Vector2 const & vector2) const;
	Vector2 operator+(Vector2 const & vector2) const;

	float	x;
	float	y;

};

std::ostream & operator<<(std::ostream & out, Vector2 const & vector);
Vector2 operator/(float value, Vector2 const & vector2);

#endif
