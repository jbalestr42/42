#ifndef QUATERNION_HPP
# define QUATERNION_HPP

#include "Matrix.hpp"

class Vector3;

class Quaternion
{
public:
	Quaternion(void);
	Quaternion(Quaternion const & quaternion);
	virtual ~Quaternion(void) = default;

	Quaternion & operator=(Quaternion const & quaternion);

	void identity(void);
	float length(void);
	void normalize(void);
	void multiply(Quaternion const & q);
	void fromEuler(Vector3 const & euler);
	void fromEuler(float eulerX, float eulerY, float eulerZ);
	void fromAxis(Vector3 const & axis, float angle);
	Matrix toMatrix(void);

	float	x;
	float	y;
	float	z;
	float	w;

};

#endif
