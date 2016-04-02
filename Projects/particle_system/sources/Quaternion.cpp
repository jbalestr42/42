#include "Quaternion.hpp"
#include "Math.hpp"
#include "Vector3.hpp"
#include <cmath>

Quaternion::Quaternion(void)
{
	identity();
}

Quaternion::Quaternion(Quaternion const & quaternion)
{
	*this = quaternion;
}

Quaternion & Quaternion::operator=(Quaternion const & quaternion)
{
	x = quaternion.x;
	y = quaternion.y;
	z = quaternion.z;
	w = quaternion.w;
	return (*this);
}

void Quaternion::identity(void)
{
	x = 0.f;
	y = 0.f;
	z = 0.f;
	w = 1.f;
}

void Quaternion::fromEuler(Vector3 const & euler)
{
	fromEuler(euler.x, euler.y, euler.z);
}

void Quaternion::fromEuler(float eulerX, float eulerY, float eulerZ)
{
	float hx = Deg2Rad * eulerX / 2.f;
	float hy = Deg2Rad * eulerY / 2.f;
	float hz = Deg2Rad * eulerZ / 2.f;
	float sinX = std::sin(hx);
	float cosX = std::cos(hx);
	float sinY = std::sin(hy);
	float cosY = std::cos(hy);
	float sinZ = std::sin(hz);
	float cosZ = std::cos(hz);
	float cosYsinX = cosY * sinX;
	float sinYcosX = sinY * cosX;
	float cosYcosX = cosY * cosX;
	float sinYsinX = sinY * sinX;
	x = (cosYsinX * cosZ) + (sinYcosX * sinZ);
	y = (sinYcosX * cosZ) - (cosYsinX * sinZ);
	z = (cosYcosX * sinZ) - (sinYsinX * cosZ);
	w = (cosYcosX * cosZ) + (sinYsinX * sinZ);

	normalize();
}

void Quaternion::fromAxis(Vector3 const & axis, float angle)
{
	angle *= 0.5f;
	float sinAngle = std::sin(angle);

	x = axis.x * sinAngle;
	y = axis.y * sinAngle;
	z = axis.z * sinAngle;
	w = std::cos(angle);
	normalize();
}

float Quaternion::length(void)
{
	return std::sqrt(x * x + y * y + z * z + w * w);
}

void Quaternion::normalize(void)
{
	float len = 1.f / length();
	x *= len;
	y *= len;
	z *= len;
	w *= len;
}

Matrix Quaternion::toMatrix(void)
{
	float xx = x * x;
	float yy = y * y;
	float zz = z * z;
	float xy = x * y;
	float xz = x * z;
	float yz = y * z;
	float wx = w * x;
	float wy = w * y;
	float wz = w * z;

	return Matrix(1.f - 2.f * (yy + zz), 2.f * (xy + wz), 2.f * (xz - wy), 0.f,
					2.f * (xy - wz), 1.f - 2.f * (xx + zz), 2.f * (yz + wx), 0.f,
					2.f * (xz + wy), 2.f * (yz - wx), 1.f - 2.f * (xx + yy), 0.f,
					0.f, 0.f, 0.f, 1.f);
}

void Quaternion::multiply(Quaternion const & q)
{
	float tx = x * q.w + w * q.x + y * q.z - z * q.y;
	float ty = y * q.w + w * q.y + z * q.x - x * q.z;
	float tz = z * q.w + w * q.z + x * q.y - y * q.x;
	float tw = w * q.w - x * q.x - y * q.y - z * q.z;

	x = tx;
	y = ty;
	z = tz;
	w = tw;
}
