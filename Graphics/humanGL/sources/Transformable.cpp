#include "Transformable.hpp"
#include "Quaternion.hpp"

Transformable::Transformable(void) :
	m_scale(1.f, 1.f, 1.f),
	m_parentScale(1.f, 1.f, 1.f),
	m_eulerOrder(Matrix::EulerOrder::ZYX),
	m_needRecompute(false)
{}

Transformable::Transformable(Transformable const & transformable)
{
	*this = transformable;
}

Transformable::Transformable(Transformable && transformable)
{
	*this = std::move(transformable);
}

Transformable & Transformable::operator=(Transformable const & transformable)
{
	m_origin = transformable.m_origin;
	m_position = transformable.m_position;
	m_rotation = transformable.m_rotation;
	m_scale = transformable.m_scale;
	m_parentScale = transformable.m_parentScale;
	m_model = transformable.m_model;
	m_eulerOrder = transformable.m_eulerOrder;
	m_needRecompute = transformable.m_needRecompute;
	return (*this);
}

Transformable & Transformable::operator=(Transformable && transformable)
{
	m_origin = std::move(transformable.m_origin);
	m_position = std::move(transformable.m_position);
	m_rotation = std::move(transformable.m_rotation);
	m_scale = std::move(transformable.m_scale);
	m_parentScale = std::move(transformable.m_parentScale);
	m_model = std::move(transformable.m_model);
	m_eulerOrder = transformable.m_eulerOrder;
	m_needRecompute = transformable.m_needRecompute;
	return (*this);
}

void Transformable::setOrigin(Vector3 const & origin)
{
	m_origin = origin;
	m_needRecompute = true;
}

void Transformable::setPosition(Vector3 const & position)
{
	m_position = position;
	m_needRecompute = true;
}

void Transformable::setRotation(Vector3 const & rotation)
{
	m_rotation = rotation;
	m_needRecompute = true;
}

void Transformable::setScale(Vector3 const & scale)
{
	m_scale = scale;
	m_needRecompute = true;
}

void Transformable::setParentScale(Vector3 const & parentScale)
{
	m_parentScale = parentScale;
	m_needRecompute = true;
}

Vector3 const & Transformable::getOrigin(void) const
{
	return m_origin;
}

Vector3 const & Transformable::getPosition(void) const
{
	return m_position;
}

Vector3 const & Transformable::getRotation(void) const
{
	return m_rotation;
}

Vector3 const & Transformable::getScale(void) const
{
	return m_scale;
}

Vector3 const & Transformable::getParentScale(void) const
{
	return m_parentScale;
}

void Transformable::translate(Vector3 const & translation)
{
	m_position += translation;
	m_needRecompute = true;
}

void Transformable::rotate(Vector3 const & rotation)
{
	m_rotation += rotation;
	m_needRecompute = true;
}

void Transformable::rotateX(float angle)
{
	m_rotation.x += angle;
	m_needRecompute = true;
}

void Transformable::rotateY(float angle)
{
	m_rotation.y += angle;
	m_needRecompute = true;
}

void Transformable::rotateZ(float angle)
{
	m_rotation.z += angle;
	m_needRecompute = true;
}

void Transformable::scale(Vector3 const & scale)
{
	m_scale += scale;
	m_needRecompute = true;
}

void Transformable::setEulerOrder(Matrix::EulerOrder order)
{
	m_eulerOrder = order;
	m_needRecompute = true;
}

Matrix const & Transformable::getMatrix(void)
{
	if (m_needRecompute)
	{
		m_model.identity();
		m_model.translate(m_origin);
		m_model.scale(m_scale * m_parentScale);
		m_model.rotate(m_rotation, m_eulerOrder);
		//Quaternion modelRot;
		//modelRot.fromEuler(m_rotation);
		//m_model.multiply(modelRot.toMatrix());
		m_model.scale(1.f / m_parentScale);
		m_model.translate(m_position);
		m_needRecompute = false;
	}
	return m_model;
}
