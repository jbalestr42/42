#ifndef VECTOR4_HPP
# define VECTOR4_HPP

# include <iostream>
# include "Matrix.hpp"

class Vector4
{
public:
	Vector4(void);
	Vector4(float x, float y, float z, float w);
	Vector4(Vector4 const & vector4);
	Vector4(Vector4 && vector4);
	~Vector4(void) = default;

	float length(void);
	void normalize(void);
	Vector4 inverse(void);

	Vector4 & operator=(Vector4 const & vector4);
	Vector4 & operator=(Vector4 && vector4);
	Vector4 & operator+=(Vector4 const & vector4);
	Vector4 & operator*=(Vector4 const & vector4);
	Vector4 & operator-=(Vector4 const & vector4);
	Vector4 operator+(Vector4 const & vector4) const;
	Vector4 operator*(Matrix const & matrix) const;
	Vector4 operator*(Vector4 const & vector4) const;
	Vector4 operator*(float factor) const;
	Vector4 operator-(Vector4 const & vector4) const;
	Vector4 operator-(void) const;

	float	x;
	float	y;
	float	z;
	float	w;

};

std::ostream & operator<<(std::ostream & out, Vector4 const & vector);
Vector4 operator/(float value, Vector4 const & vector4);

#endif
