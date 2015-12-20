#ifndef VECTOR3_HPP
# define VECTOR3_HPP

# include <iostream>

class Vector3
{
public:
	Vector3(void);
	Vector3(float x, float y, float z);
	Vector3(Vector3 const & vector3);
	~Vector3(void) = default;

	float length(void);
	void normalize(void);

	Vector3 & operator=(Vector3 const & vector3);
	Vector3 & operator+=(Vector3 const & vector3);
	Vector3 & operator*=(Vector3 const & vector3);
	Vector3 & operator-=(Vector3 const & vector3);
	Vector3 operator+(Vector3 const & vector3);
	Vector3 operator*(Vector3 const & vector3);
	Vector3 operator*(float factor);
	Vector3 operator-(Vector3 const & vector3);
	Vector3 operator-(void);

	float	x;
	float	y;
	float	z;

};

std::ostream & operator<<(std::ostream & out, Vector3 const & vector);

#endif
