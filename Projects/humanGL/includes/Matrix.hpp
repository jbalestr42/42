#ifndef MATRIX_HPP
# define MATRIX_HPP

# include "Vector3.hpp"

class Matrix
{
public:
	enum EulerOrder
	{
		XYZ,
		YZX,
		ZXY,
		ZYX,
		YXZ,
		XZY
	};

	Matrix(void);
	Matrix(float f00, float f01, float f02, float f03,
			float f10, float f11, float f12, float f13,
			float f20, float f21, float f22, float f23,
			float f30, float f31, float f32, float f33);
	Matrix(Matrix const & matrix);
	~Matrix(void) = default;

	Matrix & operator=(Matrix const & matrix);
	float & operator[](int index);
	Matrix operator*(Matrix const & matrix);

	//TODO Shearing
	//Interpolation between matrices
	Matrix & multiply(Matrix const & matrix);
	Matrix & rotateX(float angle);
	Matrix & rotateY(float angle);
	Matrix & rotateZ(float angle);
	Matrix & rotate(Vector3 const & vector, EulerOrder order = XYZ);
	Matrix & translate(Vector3 const & vector);
	Matrix & scale(Vector3 const & vector);
	Matrix eulerAnglesToMatrix(Vector3 const & angles, EulerOrder order = XYZ);

	Matrix inverse(void);
	float determinant(void);
	Matrix coFactor(void);
	float const * getMatrix(void) const;
	void identity(void);
	void perspectiveProjection(float fov, float aspectRatio, float nearPlane, float farPlane);

	void dump(void);

private:
	float	m_matrix[16];

	int getMinor(Matrix const & src, Matrix & dest, int row, int col);
	float determinant3(Matrix const & matrix);
};

#endif
