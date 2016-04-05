#include "Camera.hpp"
#include "Vector4.hpp"

Camera::Camera(void) :
	m_shader(nullptr)
{
	m_shader.reset(new Shader("resources/default.frag" ,"resources/default.vert"));
	m_shader->bind();
	m_view.translate(Vector3(0.f, 0.f, -8.0f));
	m_shader->setParameter("ViewMatrix", m_view);
	m_shader->setParameter("ModelMatrix", m_model);
	m_projection.perspectiveProjection(60.f, 1920.f / 1080.f, 0.1f, 100.f);
	m_shader->setParameter("ProjectionMatrix", m_projection);
}

Camera::Camera(Camera const & camera)
{
	*this = camera;
}

Camera::~Camera(void) { }

Camera & Camera::operator=(Camera const & camera)
{
	(void)camera;
	return (*this);
}

Matrix const & Camera::getProjection(void) const
{
	return (m_projection);
}

Matrix const & Camera::getView(void) const
{
	return (m_view);
}

Matrix const & Camera::getModel(void) const
{
	return (m_model);
}

Vector3 Camera::unProject(Vector2 const & inPosition, float depth)
{
	Vector4 inVector;
	inVector.x = (2.0f * inPosition.x) - 1.0f;
	inVector.y = 1.0f - (2.0f * inPosition.y);
	inVector.z = 2.0f * depth - 1.0f;
	inVector.w = 1.0f;

	Matrix modelView = m_model * m_view;
	Vector4 rayWorld = inVector * modelView.inverse();
	rayWorld = rayWorld * m_projection.inverse();

	Vector3 result;
	if (rayWorld.w < 0.00001f && rayWorld.w > -0.00001f)
	{
	result.x = rayWorld.x;
	result.y = rayWorld.y;
	result.z = rayWorld.z;
	}
	else
	{
	result.x = rayWorld.x / rayWorld.w;
	result.y = rayWorld.y / rayWorld.w;
	result.z = rayWorld.z / rayWorld.w;
	}
	return result;
}
