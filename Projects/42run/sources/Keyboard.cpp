#include "Keyboard.hpp"

std::map<int, int>	Keyboard::m_keys;

Keyboard::Keyboard(void) { }

Keyboard::Keyboard(Keyboard const & keyboard)
{
	*this = keyboard;
}

Keyboard::~Keyboard(void) { }

Keyboard & Keyboard::operator=(Keyboard const & keyboard)
{
	(void)keyboard;
	return (*this);
}

void Keyboard::callback(GLFWwindow *, int key, int, int action, int)
{
	if (action != GLFW_REPEAT)
		m_keys[key] = action;
}

bool Keyboard::isKeyPressed(int key)
{
	if (m_keys.find(key) != m_keys.end())
	{
		if (m_keys[key] == GLFW_PRESS)
		{
			m_keys[key] = GLFW_REPEAT;
			return true;
		}
	}
	return false;
}

bool Keyboard::isKeyPress(int key)
{
	if (m_keys.find(key) != m_keys.end())
	{
		if (m_keys[key] == GLFW_PRESS)
			m_keys[key] = GLFW_REPEAT;
		if (m_keys[key] == GLFW_REPEAT)
			return true;
	}
	return false;
}

bool Keyboard::isKeyReleased(int key)
{
	if (m_keys.find(key) != m_keys.end())
	{
		if (m_keys[key] == GLFW_RELEASE)
		{
			m_keys[key] = -1;
			return true;
		}
	}
	return false;
}
