#include "Camera.hpp"
#include "Vector4.hpp"
#include "Keyboard.hpp"
#include "Mouse.hpp"
#include "Math.hpp"
#include <limits>

Camera::Camera(void) :
	Transformable(),
	m_up(0.f, 1.f, 0.f),
	m_target(0.f, 0.f, 1.f),
	m_mousePos(Mouse::getPosition()),
	m_shader(nullptr)
{
	m_shader.reset(new Shader("resources/default.frag" ,"resources/default.vert"));
	m_shader->bind();
	translate(Vector3(0.f, 0.f, -8.0f));
	m_shader->setParameter("ViewMatrix", getMatrix());
	Matrix model;
	m_shader->setParameter("ModelMatrix", model);
	m_projection.perspectiveProjection(60.f, 1920.f / 1080.f, 0.1f, 100.f);
	m_shader->setParameter("ProjectionMatrix", m_projection);
}

Camera::Camera(Camera const & camera) :
	Transformable(camera)
{
	*this = camera;
}

Camera::~Camera(void) { }

Camera & Camera::operator=(Camera const & camera)
{
	Transformable::operator=(camera);
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

Matrix const & Camera::getModel(void)
{
	return (getMatrix());
}

Shader & Camera::getShader(void) const
{
	return (*m_shader);
}

Vector3 Camera::unProject(Vector2 const & inPosition, float depth)
{
	Vector4 inVector;
	inVector.x = (2.0f * inPosition.x) - 1.0f;
	inVector.y = 1.0f - (2.0f * inPosition.y);
	inVector.z = 2.0f * depth - 1.0f;
	inVector.w = 1.0f;

	Matrix modelView = getMatrix() * m_view;
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

void Camera::update(float frametime)
{
	static const float speed = 5.f;
	const Vector2 delta = m_mousePos - Mouse::getPosition();
	m_mousePos = Mouse::getPosition();

	if (Mouse::isButtonPress(GLFW_MOUSE_BUTTON_RIGHT))
	{
		if (Keyboard::isKeyPress(GLFW_KEY_RIGHT))
		{
			Vector3 left(m_target.cross(m_up));
			left.normalize();
			translate(left * frametime * speed);
		}
		else if (Keyboard::isKeyPress(GLFW_KEY_LEFT))
		{
			Vector3 right(m_up.cross(m_target));
			right.normalize();
			translate(right * frametime * speed);
		}
		if (Keyboard::isKeyPress(GLFW_KEY_UP))
			translate(m_target * frametime * speed);
		if (Keyboard::isKeyPress(GLFW_KEY_DOWN))
			translate(m_target * -frametime * speed);
	
		rotate({delta.y * frametime * 50000.f, delta.x * frametime * 50000.f, 0.f});
	}
	else
		setRotation({0.f, 0.f, 0.f});
	m_shader->setParameter("ViewMatrix", getMatrix());
}
