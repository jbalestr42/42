#include "Transformable.hpp"
#include "Quaternion.hpp"

Transformable::Transformable(void) :
	m_scale(1.f, 1.f, 1.f),
	m_eulerOrder(Matrix::EulerOrder::ZYX),
	m_needRecompute(false),
	m_parent(nullptr)
{}

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
		m_model.scale(m_scale);
		//m_model.rotate(m_rotation, m_eulerOrder);
		Quaternion modelRot;
		modelRot.fromEuler(m_rotation);
		m_model.multiply(modelRot.toMatrix());
		//m_model.rotateX(m_rotation.x);
		//m_model.rotateY(m_rotation.y);
		//m_model.rotateZ(m_rotation.z);
		//m_model.rotateY(m_rotation.y);
		m_model.translate(m_position);
		m_needRecompute = false;
	}
	return m_model;
}
