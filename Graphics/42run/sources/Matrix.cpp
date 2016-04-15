#include "Matrix.hpp"
#include "Math.hpp"
#include <algorithm>
#include <iostream>

Matrix::Matrix(void)
{
	identity();
}

Matrix::Matrix(float f00, float f01, float f02, float f03,
				float f10, float f11, float f12, float f13,
				float f20, float f21, float f22, float f23,
				float f30, float f31, float f32, float f33)
{
	m_matrix[0] = f00; m_matrix[1] = f01; m_matrix[2] = f02; m_matrix[3] = f03;
	m_matrix[4] = f10; m_matrix[5] = f11; m_matrix[6] = f12; m_matrix[7] = f13;
	m_matrix[8] = f20; m_matrix[9] = f21; m_matrix[10] = f22; m_matrix[11] = f23;
	m_matrix[12] = f30; m_matrix[13] = f31; m_matrix[14] = f32; m_matrix[15] = f33;
}

Matrix::Matrix(Matrix const & matrix)
{
	*this = matrix;
}

Matrix::Matrix(Matrix && matrix)
{
	*this = std::move(matrix);
}

Matrix & Matrix::operator=(Matrix const & matrix)
{
	std::copy(std::begin(matrix.m_matrix), std::end(matrix.m_matrix), std::begin(m_matrix));
	return (*this);
}

Matrix & Matrix::operator=(Matrix && matrix)
{
	std::move(std::begin(matrix.m_matrix), std::end(matrix.m_matrix), std::begin(m_matrix));
	return (*this);
}

float & Matrix::operator[](int index)
{
	return (m_matrix[index]);
}

Matrix Matrix::operator*(Matrix const & matrix) const
{
	Matrix	result;
	for (int i = 0, offset = 0; i < 4; i++, offset = i * 4)
	{
		for (int j = 0; j < 4; j++)
		{
			result[offset + j] = m_matrix[offset + 0] * matrix.m_matrix[j + 0];
			result[offset + j] += m_matrix[offset + 1] * matrix.m_matrix[j + 4];
			result[offset + j] += m_matrix[offset + 2] * matrix.m_matrix[j + 8];
			result[offset + j] += m_matrix[offset + 3] * matrix.m_matrix[j + 12];
		}
	}
	return (result);
}

Matrix & Matrix::multiply(Matrix const & matrix)
{
	Matrix tmp(std::move(*this));

	for (int i = 0, offset = 0; i < 4; i++, offset = i * 4)
	{
		for (int j = 0; j < 4; j++)
		{
			m_matrix[offset + j] =  tmp.m_matrix[offset + 0] * matrix.m_matrix[j + 0];
			m_matrix[offset + j] += tmp.m_matrix[offset + 1] * matrix.m_matrix[j + 4];
			m_matrix[offset + j] += tmp.m_matrix[offset + 2] * matrix.m_matrix[j + 8];
			m_matrix[offset + j] += tmp.m_matrix[offset + 3] * matrix.m_matrix[j + 12];
		}
	}
	return (*this);
}

Matrix & Matrix::rotateX(float angle)
{
	float rad = angle * Deg2Rad;
	float cos = std::cos(rad);
	float sin = std::sin(rad);

	Matrix rotation(1.f, 0.f, 0.f, 0.f,
			0.f, cos, -sin, 0.f,
			0.f, sin, cos, 0.f,
			0.f, 0.f, 0.f, 1.f);
	return multiply(rotation);
}

Matrix & Matrix::rotateY(float angle)
{
	float rad = angle * Deg2Rad;
	float cos = std::cos(rad);
	float sin = std::sin(rad);

	Matrix rotation(cos, 0.f, -sin, 0.f,
			0.f, 1.f, 0.f, 0.f,
			sin, 0.f, cos, 0.f,
			0.f, 0.f, 0.f, 1.f);
	return multiply(rotation);
}

Matrix & Matrix::rotateZ(float angle)
{
	float rad = angle * Deg2Rad;
	float cos = std::cos(rad);
	float sin = std::sin(rad);

	Matrix rotation(cos, -sin, 0.f, 0.f,
			sin,  cos, 0.f, 0.f,
			0.f,  0.f, 1.f, 0.f,
			0.f,  0.f, 0.f, 1.f);
	return multiply(rotation);
}

Matrix & Matrix::rotate(Vector3 const & vector, EulerOrder order)
{
	Matrix rotation = eulerAnglesToMatrix(vector, order);
	return multiply(rotation);
}

Matrix Matrix::eulerAnglesToMatrix(Vector3 const & angles, EulerOrder order)
{
	Matrix	result;
	float sinX = std::sin(Deg2Rad * angles.x);
	float sinY = std::sin(Deg2Rad * angles.y);
	float sinZ = std::sin(Deg2Rad * angles.z);
	float cosX = std::cos(Deg2Rad * angles.x);
	float cosY = std::cos(Deg2Rad * angles.y);
	float cosZ = std::cos(Deg2Rad * angles.z);

	switch (order)
	{
		case XYZ:
			result.m_matrix[0] = cosY * cosZ;
			result.m_matrix[1] = -cosY * sinZ;
			result.m_matrix[2] = sinY;
			result.m_matrix[4] = cosZ * sinX * sinY + cosX * sinZ;
			result.m_matrix[5] = cosX * cosZ - sinX * sinY * sinZ;
			result.m_matrix[6] = -cosY * sinX;
			result.m_matrix[8] = -cosX * cosZ * sinY + sinX * sinZ;
			result.m_matrix[9] = cosZ * sinX + cosX * sinY * sinZ;
			result.m_matrix[10] = cosX * cosY;
			break;
		case YZX:
			result.m_matrix[0] = cosY * cosZ;
			result.m_matrix[1] = sinX * sinY - cosX * cosY * sinZ;
			result.m_matrix[2] = cosX * sinY + cosY * sinX * sinZ;
			result.m_matrix[4] = sinZ;
			result.m_matrix[5] = cosX * cosZ;
			result.m_matrix[6] = -cosZ * sinX;
			result.m_matrix[8] = -cosZ * sinY;
			result.m_matrix[9] = cosY * sinX + cosX * sinY * sinZ;
			result.m_matrix[10] = cosX * cosY - sinX * sinY * sinZ;
			break;
		case ZXY:
			result.m_matrix[0] = cosY * cosZ - sinX * sinY * sinZ;
			result.m_matrix[1] = -cosX * sinZ;
			result.m_matrix[2] = cosZ * sinY + cosY * sinX * sinZ;
			result.m_matrix[4] = cosZ * sinX * sinY + cosY * sinZ;
			result.m_matrix[5] = cosX * cosZ;
			result.m_matrix[6] = -cosY * cosZ * sinX + sinY * sinZ;
			result.m_matrix[8] = -cosX * sinY;
			result.m_matrix[9] = sinX;
			result.m_matrix[10] = cosX * cosY;
			break;
		case ZYX:
			result.m_matrix[0] = cosY * cosZ;
			result.m_matrix[1] = cosZ * sinX * sinY - cosX * sinZ;
			result.m_matrix[2] = cosX * cosZ * sinY + sinX * sinZ;
			result.m_matrix[4] = cosY * sinZ;
			result.m_matrix[5] = cosX * cosZ + sinX * sinY * sinZ;
			result.m_matrix[6] = -cosZ * sinX + cosX * sinY * sinZ;
			result.m_matrix[8] = -sinY;
			result.m_matrix[9] = cosY * sinX;
			result.m_matrix[10] = cosX * cosY;
			break;
		case YXZ:
			result.m_matrix[0] = cosY * cosZ + sinX * sinY * sinZ;
			result.m_matrix[1] = cosZ * sinX * sinY - cosY * sinZ;
			result.m_matrix[2] = cosX * sinY;
			result.m_matrix[4] = cosX * sinZ;
			result.m_matrix[5] = cosX * cosZ;
			result.m_matrix[6] = -sinX;
			result.m_matrix[8] = -cosZ * sinY + cosY * sinX * sinZ;
			result.m_matrix[9] = cosY * cosZ * sinX + sinY * sinZ;
			result.m_matrix[10] = cosX * cosY;
			break;
		case XZY:
			result.m_matrix[0] = cosY * cosZ;
			result.m_matrix[1] = -sinZ;
			result.m_matrix[2] = cosZ * sinY;
			result.m_matrix[4] = sinX * sinY + cosX * cosY * sinZ;
			result.m_matrix[5] = cosX * cosZ;
			result.m_matrix[6] = -cosY * sinX + cosX * sinY * sinZ;
			result.m_matrix[8] = -cosX * sinY + cosY * sinX * sinZ;
			result.m_matrix[9] = cosZ * sinX;
			result.m_matrix[10] = cosX * cosY + sinX * sinY * sinZ;
			break;
	}
	return (result);
}

Matrix & Matrix::translate(Vector3 const & vector)
{
	Matrix translation(1.f, 0.f, 0.f, 0.f,
			0.f, 1.f, 0.f, 0.f,
			0.f, 0.f, 1.f, 0.f,
			vector.x, vector.y, vector.z, 1.f);
	return multiply(translation);
}

Matrix & Matrix::scale(Vector3 const & vector)
{
	Matrix scale(vector.x, 0.f, 0.f, 0.f,
			0.f, vector.y, 0.f, 0.f,
			0.f, 0.f, vector.z, 0.f,
			0.f, 0.f, 0.f, 1.f);
	return multiply(scale);
}

float Matrix::determinant(void) const
{
	float const * m = m_matrix;
	float det =
		(m[0] * (m[5] * (m[10] * m[15] - m[11] * m[14])
				 - m[6] * (m[9] * m[15] - m[11] * m[13])
				 + m[7] * (m[9] * m[14] - m[10] * m[13])))
		-
		(m[1] * (m[4] * (m[10] * m[15] - m[11] * m[14])
				 - m[6] * (m[8] * m[15] - m[11] * m[12])
				 + m[7] * (m[8] * m[14] - m[10] * m[12])))
		+
		(m[2] * (m[4] * (m[9] * m[15] - m[11] * m[13])
				 - m[5] * (m[8] * m[15] - m[11] * m[12])
				 + m[7] * (m[8] * m[13] - m[9] * m[12])))
		-
		(m[3] * (m[4] * (m[9] * m[14] - m[10] * m[13])
				 - m[5] * (m[8] * m[14] - m[10] * m[12])
				 + m[6] * (m[8] * m[13] - m[9] * m[12])));
	return (det);
}

Matrix Matrix::inverse(void) const
{
	Matrix inverse;
	float det = 1.f / determinant();

	Matrix minor;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			// get the co-factor (matrix) of A(j,i)
			getMinor(*this, minor, j, i);
			inverse[i * 4 + j] = det * determinant3(minor);
			if ((i + j) % 2 == 1)
				inverse.m_matrix[i * 4 + j] = -inverse.m_matrix[i * 4 + j];
		}
	}
	return (inverse);
}

float const * Matrix::getMatrix(void) const
{
	return (m_matrix);
}

void Matrix::identity(void)
{
	m_matrix[0] = 1.f; m_matrix[1] = 0.f; m_matrix[2] = 0.f; m_matrix[3] = 0.f;
	m_matrix[4] = 0.f; m_matrix[5] = 1.f; m_matrix[6] = 0.f; m_matrix[7] = 0.f;
	m_matrix[8] = 0.f; m_matrix[9] = 0.f; m_matrix[10] = 1.f; m_matrix[11] = 0.f;
	m_matrix[12] = 0.f; m_matrix[13] = 0.f; m_matrix[14] = 0.f; m_matrix[15] = 1.f;
}

void Matrix::perspectiveProjection(float fov, float aspectRatio, float nearPlane, float farPlane)
{
	float		scaleY = 1.f / std::tan(Deg2Rad * (fov / 2.f));
	float		scaleX = scaleY / aspectRatio;
	float		frustumLength = nearPlane - farPlane;

	m_matrix[0] = scaleX;
	m_matrix[1] = 0.f;
	m_matrix[2] = 0.f;
	m_matrix[3] = 0.f;
	m_matrix[4] = 0.f;
	m_matrix[5] = scaleY;
	m_matrix[6] = 0.f;
	m_matrix[7] = 0.f;
	m_matrix[8] = 0.f;
	m_matrix[9] = 0.f;
	m_matrix[10] = (farPlane + nearPlane) / frustumLength;
	m_matrix[11] = -1.f;
	m_matrix[12] = 0.f;
	m_matrix[13] = 0.f;
	m_matrix[14] = (2.f * nearPlane * farPlane) / frustumLength;
	m_matrix[15] = 0.f;
}

void Matrix::dump(void)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
			std::cout << m_matrix[i * 4 + j] << " ";
		std::cout << std::endl;
	}
}

int Matrix::getMinor(Matrix const & src, Matrix & dest, int row, int col) const
{
	int colCount;
	int rowCount = 0;

	for (int i = 0; i < 4; i++)
	{
		if (i != row)
		{
			colCount = 0;
			for (int j = 0; j < 4; j++)
			{
				if (j != col)
				{
					dest[rowCount * 3 + colCount] = src.m_matrix[i * 4 + j];
					colCount++;
				}
			}
			rowCount++;
		}
	}
	return 1;
}

float Matrix::determinant3(Matrix const & matrix) const
{
	float const * m = matrix.m_matrix;
	float det =
		m[0] * (m[4] * m[8] - m[5] * m[7])
		- m[1] * (m[3] * m[8] - m[5] * m[6])
		+ m[2] * (m[3] * m[7] - m[4] * m[6]);
	return (det);
}
