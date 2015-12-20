#include "Windows.hpp"
#include "Mesh.hpp"
#include "Color.hpp"
#include "Matrix.hpp"
#include "Math.hpp"
#include "Shader.hpp"
#include <iostream>

int main(void)
{
	Windows win(800, 600, "HumanGL");
	win.setClearColor(Color::White);

	Mesh mesh;
	Mesh mesh2;
	Shader shader("resources/default.frag" ,"resources/default.vert");

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	//glEnable(GL_CULL_FACE);
	//glCullFace(GL_FRONT);
	//glFrontFace(GL_CCW);
	//glEnable(GL_LIGHTING);
	//glEnable(GL_FOG);
	//glDepthMask(GL_TRUE);
	//glDisable(GL_LIGHTING);
	//glDisable(GL_FOG);
	Matrix		m_view;
	Matrix		m_projection;

	mesh.translate(Vector3(1.f, -1.f, 0.f));
	mesh.setScale(Vector3(0.5f, 1.f, 0.5f));
	mesh.rotate(Vector3(0.f, 90.f, 0.f));

	mesh2.translate(Vector3(-1.f, 1.f, 0.f));
	mesh2.setScale(Vector3(0.5f, 1.f, 0.5f));
	mesh2.rotate(Vector3(0.f, 90.f, 0.f));

	m_view.identity();
	m_view.translate(Vector3(0.f, 0.f, -3.f));
	shader.setParameter("ViewMatrix", m_view);
	m_projection.identity();
	m_projection.perspectiveProjection(60.f, 800.f / 600.f, 1.f, 100.f);
	shader.setParameter("ProjectionMatrix", m_projection);

	glfwSetTime(0.f);
	float lastTime = 0.f;
	while (win.isOpen())
	{
		// Compute frametime
		float currentTime = glfwGetTime();
		float frameTime = (currentTime - lastTime);
		lastTime = currentTime;

		// Update
		if (glfwGetKey(win.getWindow(), GLFW_KEY_ESCAPE) == GLFW_PRESS)
			win.close();

		mesh.rotate(Vector3(0.f, 0.f, 1.f) * frameTime);
		mesh2.rotate(Vector3(6.f, 3.f, 1.f) * frameTime);

		// Draw
		win.clear();

		mesh.draw(shader);
		mesh2.draw(shader);

		win.display();
		win.pollEvents();
	}
	return (0);
}
