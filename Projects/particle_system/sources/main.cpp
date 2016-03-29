#include "Windows.hpp"
#include "Shader.hpp"
#include "Keyboard.hpp"
#include "Mouse.hpp"
#include "OpenCL.hpp"
#include "ParticleSystem.hpp"
#include <iostream>
#include <sstream>

#define STRINGIFY(A) #A

std::string kernel_source = STRINGIFY(
typedef struct		s_particle
{
	float			position[3];
	float			color[4];
	float			velocity[3];
	}				t_particle;

	__kernel void part2(__global t_particle* particles, float dt, float2 mouse_pos)
	{
	//get our index in the array
	unsigned int i = get_global_id(0);

	particles[i].position[0] += (mouse_pos.x - particles[i].position[0]) * dt * 5.f;
	particles[i].color[3] -= dt;
	if (particles[i].color[3] < 0.0)
		particles[i].color[3] = 1.0;
	}
);

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

	OpenCL cl;
	cl.loadProgram(kernel_source);
	cl.loadData();
	while (win.isOpen())
	{
		// Compute frametime
		float currentTime = glfwGetTime();
		float frametime = (currentTime - lastTime);
		lastTime = currentTime;
		std::ostringstream ss;
		ss << (1.f / frametime);
		std::string s(ss.str());
		win.setTitle(s);

		// Inputs
		if (Keyboard::isKeyPressed(GLFW_KEY_ESCAPE))
			win.close();

		// Draw
		win.clear();

		// Update
		// cl.runKernel()

    //this updates the particle system by calling the kernel
	cl.runKernel(frametime);

    //render the particles from VBOs
    //glEnable(GL_BLEND);
    //glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    //glEnable(GL_POINT_SMOOTH);
    //glPointSize(5.);

    ////printf("color buffer\n");
    //glBindBuffer(GL_ARRAY_BUFFER, cl.c_vbo);
    //glColorPointer(4, GL_FLOAT, 0, 0);

    ////printf("vertex buffer\n");
    //glBindBuffer(GL_ARRAY_BUFFER, cl.p_vbo);
    //glVertexPointer(4, GL_FLOAT, 0, 0);

    ////printf("enable client state\n");
    //glEnableClientState(GL_VERTEX_ARRAY);
    //glEnableClientState(GL_COLOR_ARRAY);

    ////Need to disable these for blender
    //glDisableClientState(GL_NORMAL_ARRAY);

    ////printf("draw arrays\n");
    //glDrawArrays(GL_POINTS, 0, num);

    ////printf("disable stuff\n");
    //glDisableClientState(GL_COLOR_ARRAY);
    //glDisableClientState(GL_VERTEX_ARRAY);

		win.display();
		win.pollEvents();
	}
	return (0);
}
