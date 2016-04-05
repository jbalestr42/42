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
	float			color;
	}				t_particle;

	__constant float MIN_DIST = 8.5f;
	__constant float PARTICLE_MASS = 100.f;
	__constant float GRAVITY = 250.f * 100.f;

	__kernel void animate(__global t_particle * particles, __global float *velocities, float dt, float posx, float posy)
	{
		unsigned int i = get_global_id(0);

		float4 res = (float4)(posx - particles[i].position[0], posy - particles[i].position[1], -particles[i].position[2], 0.f);
		float dist = fast_length(res);
		particles[i].color = dist;
		if (dist < MIN_DIST)
			dist = MIN_DIST;
		float4 force = GRAVITY * normalize(res) / (dist * dist);

		velocities[i * 3 + 0] += (force.x / PARTICLE_MASS) * dt;
		velocities[i * 3 + 1] += (force.y / PARTICLE_MASS) * dt;
		velocities[i * 3 + 2] += (force.z / PARTICLE_MASS) * dt;
		particles[i].position[0] += velocities[i * 3 + 0] * dt;
		particles[i].position[1] += velocities[i * 3 + 1] * dt;
		particles[i].position[2] += velocities[i * 3 + 2] * dt;
	}
);

int main(void)
{
	Windows win(1902, 1080, "Particle System");
	win.setClearColor(Color::Black);

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

    //this updates the particle system by calling the kernel
	cl.update(frametime);

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
	std::cout << "Realse opencl and opengl buffer" << std::endl;
	std::cout << "Activer et desactiver la velocité" << std::endl;
	return (0);
}
