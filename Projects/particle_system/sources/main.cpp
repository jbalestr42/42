#include "Windows.hpp"
#include "Shader.hpp"
#include "Keyboard.hpp"
#include <iostream>
#include <CL/cl.h>

int main(void)
{
	Windows win(800, 600, "Particle System");
	win.setClearColor(Color::White);

	Shader shader("resources/default.frag" ,"resources/default.vert");
	Matrix m_view;
	Matrix m_projection;
	m_view.translate(Vector3(0.f, 0.f, 0.0f));
	shader.setParameter("ViewMatrix", m_view);
	m_projection.perspectiveProjection(60.f, 800.f / 600.f, 0.1f, 100.f);
	shader.setParameter("ProjectionMatrix", m_projection);

	glfwSetTime(0.f);
	float lastTime = 0.f;
	while (win.isOpen())
	{
		// Compute frametime
		float currentTime = glfwGetTime();
		float frametime = (currentTime - lastTime);
		lastTime = currentTime;
		(void)frametime;

		// Inputs
		if (Keyboard::isKeyPressed(GLFW_KEY_ESCAPE))
			win.close();

		// Update

		// Draw
		win.clear();
		if (glGetError()) // TODO remove
			std::cout << "error" << std::endl;

		win.display();
		win.pollEvents();
	}
	return (0);
}
