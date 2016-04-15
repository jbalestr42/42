#include "EmitterSystem.hpp"
#include "Mouse.hpp"
#include "Keyboard.hpp"
#include "Math.hpp"
#include "Shader.hpp"
#include "Vector4.hpp"
#include <iostream>
#include <random>

EmitterSystem::EmitterSystem(void) :
	EmitterSystem(1000000)
{}

EmitterSystem::EmitterSystem(std::size_t particleCount) :
	ParticleSystem("resources/emitter_system.cl"),
	m_particleCount(particleCount),
	m_disableVelocity(false)
{
	loadData();
}

EmitterSystem::EmitterSystem(EmitterSystem const & openCL) :
	ParticleSystem(openCL)
{
	*this = openCL;
}

EmitterSystem::~EmitterSystem(void)
{
	glDeleteBuffers(1, &m_vbo[Index::Particles]);
	glDeleteBuffers(1, &m_vbo[Index::Velocity]);
	glDeleteBuffers(1, &m_vbo[Index::Life]);
	glDeleteVertexArrays(1, &m_vao);
}

EmitterSystem & EmitterSystem::operator=(EmitterSystem const & openCL)
{
	ParticleSystem::operator=(openCL);
	(void)openCL;
	return (*this);
}

void EmitterSystem::init(bool firsttime)
{
	std::cout << "-> Initialize particles as a circle." << std::endl;
	cl_int err = 0;
	std::random_device rd;
	std::mt19937 eng(rd());
	std::uniform_real_distribution<float> dist(1.f, 3.5f);
	std::uniform_real_distribution<float> dist_life(0.1f, 1.5f);
	std::uniform_real_distribution<float> dist_vel(0.f, 1.f);
	std::uniform_real_distribution<float> dist_polar(0.f, Pi2);
	std::uniform_real_distribution<float> dist_half_polar(-PiDiv2, PiDiv2);

	glBindBuffer(GL_ARRAY_BUFFER, m_vbo[Index::Particles]);
	Particle *p = static_cast<Particle*>(glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY));
	for (std::size_t i = 0; i < m_particleCount; i++)
		p[i].position = Vector3(0.f, 0.f, 0.f);
	if (firsttime)
	{
		m_glBuffer[Index::Particles] = cl::BufferGL(getContext(), CL_MEM_READ_WRITE, m_vbo[Index::Particles], &err);
		if (err)
			std::cout << "ERROR (" << getError(err) << "): kernel loading failed." << std::endl;
		m_clBuffer[Index::Particles] = cl::Buffer(getContext(), CL_MEM_READ_WRITE, m_particleCount * sizeof(Particle), NULL, &err);
	}
	err = getQueue().enqueueWriteBuffer(m_clBuffer[Index::Particles], CL_TRUE, 0, m_particleCount * sizeof(Particle), p);
	if (err)
		std::cout << "ERROR -> " << getError(err) << std::endl;
	glUnmapBuffer(GL_ARRAY_BUFFER);

	glBindBuffer(GL_ARRAY_BUFFER, m_vbo[Index::Velocity]);
	Vector3 * v = static_cast<Vector3*>(glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY));
	for (std::size_t i = 0; i < m_particleCount; i++)
	{
		Vector3 vec =  Vector3(dist(eng), dist(eng), dist(eng));
		v[i * 2 + 0] = vec;
		v[i * 2 + 1] = vec;
	}
	if (firsttime)
	{
		m_glBuffer[Index::Velocity] = cl::BufferGL(getContext(), CL_MEM_READ_WRITE, m_vbo[Index::Velocity], &err);
		if (err)
			std::cout << "ERROR (" << getError(err) << "): kernel loading failed." << std::endl;
		m_clBuffer[Index::Velocity] = cl::Buffer(getContext(), CL_MEM_READ_WRITE, 2 * m_particleCount * sizeof(Vector3), NULL, &err);
		if (err)
			std::cout << "ERROR (" << err << ")" << getError(err) << std::endl;
	}
	err = getQueue().enqueueWriteBuffer(m_clBuffer[Index::Velocity], CL_TRUE, 0, 2 * m_particleCount * sizeof(Vector3), v);
	if (err)
		std::cout << "ERROR -> " << getError(err) << std::endl;
	glUnmapBuffer(GL_ARRAY_BUFFER);

	glBindBuffer(GL_ARRAY_BUFFER, m_vbo[Index::Life]);
	float *l = static_cast<float*>(glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY));
	for (std::size_t i = 0; i < m_particleCount; i++)
	{
		l[i * 2 + 0] = 0.f;
		l[i * 2 + 1] = dist_life(eng);
	}
	if (firsttime)
	{
		m_glBuffer[Index::Life] = cl::BufferGL(getContext(), CL_MEM_READ_WRITE, m_vbo[Index::Life], &err);
		if (err)
			std::cout << "ERROR (" << getError(err) << "): kernel loading failed." << std::endl;
		m_clBuffer[Index::Life] = cl::Buffer(getContext(), CL_MEM_READ_WRITE, 2 * m_particleCount * sizeof(float), NULL, &err);
		if (err)
			std::cout << "ERROR (" << err << ")" << getError(err) << std::endl;
	}
	err = getQueue().enqueueWriteBuffer(m_clBuffer[Index::Life], CL_TRUE, 0, 2 * m_particleCount * sizeof(float), l);
	if (err)
		std::cout << "ERROR -> " << getError(err) << std::endl;
	glUnmapBuffer(GL_ARRAY_BUFFER);
}

void EmitterSystem::loadData(void)
{
	cl_int err = 0;

	std::cout << "-> Initializing particle in GPU memory" << std::endl;

	glGenVertexArrays(1, &m_vao);
	glBindVertexArray(m_vao);

	glGenBuffers(1, &m_vbo[Index::Particles]);
	glBindBuffer(GL_ARRAY_BUFFER, m_vbo[Index::Particles]);
	glBufferData(GL_ARRAY_BUFFER, m_particleCount * sizeof(Particle), NULL, GL_STATIC_DRAW); // check static

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Particle), (GLvoid*)0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 1, GL_FLOAT, GL_FALSE, sizeof(Particle), (GLvoid*)(sizeof(Vector3)));

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	glGenBuffers(1, &m_vbo[Index::Velocity]);
	glBindBuffer(GL_ARRAY_BUFFER, m_vbo[Index::Velocity]);
	glBufferData(GL_ARRAY_BUFFER, 2 * m_particleCount * sizeof(Vector3), NULL, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glGenBuffers(1, &m_vbo[Index::Life]);
	glBindBuffer(GL_ARRAY_BUFFER, m_vbo[Index::Life]);
	glBufferData(GL_ARRAY_BUFFER, 2 * m_particleCount * sizeof(float), NULL, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	init(true);

	if ((err = getKernel().setArg(0, m_clBuffer[Index::Particles])))
		std::cout << "ERROR (" << err << ") " << getError(err) << std::endl;
	if ((err = getKernel().setArg(1, m_clBuffer[Index::Velocity])))
		std::cout << "ERROR (" << err << ") " << getError(err) << std::endl;
	if ((err = getKernel().setArg(2, m_clBuffer[Index::Life])))
		std::cout << "ERROR (" << err << ") " << getError(err) << std::endl;

	Matrix model;
	if ((err = glGetError()))
		std::cout << "ERROR (" << err << ") " << getError(err) << std::endl;

	glEnable(GL_POINT_SMOOTH);
	glPointSize(0.5f);
}

void EmitterSystem::update(Camera & camera, float frametime)
{
	Vector3 near = camera.unProject(Mouse::getPosition(), 0.f);
	Vector3 far = camera.unProject(Mouse::getPosition(), 1.f);
	Vector3 dir = (far - near);
	dir.normalize();
	dir.x *= lerp(1.f, 4.f, std::abs(Mouse::getPosition().x - 0.5f) / 0.5f);
	dir.y *= lerp(1.f, 4.f, std::abs(Mouse::getPosition().y - 0.5f) / 0.5f);

	cl::Event event;
	cl_int err = 0;
	glFinish();

	if (Keyboard::isKeyPressed(GLFW_KEY_F))
		init();
	if (Keyboard::isKeyPressed(GLFW_KEY_H))
		m_disableVelocity = !m_disableVelocity;

	if (m_disableVelocity)
		frametime = 0.f;

	std::vector<cl::Memory> buffers;
	buffers.push_back(m_glBuffer[Index::Particles]);
	err = getQueue().enqueueAcquireGLObjects(&buffers, NULL, NULL);
	if (err != CL_SUCCESS)
		std::cout << "Failed acquiring GL object : " << getError(err) << std::endl;
	err = getQueue().finish();
	if (err != CL_SUCCESS)
		std::cout << "ERROR" << std::endl;

	err = getKernel().setArg(3, frametime);
	if (err != CL_SUCCESS)
		std::cout << "ERROR kernel args" << std::endl;

	err = getQueue().enqueueNDRangeKernel(getKernel(), cl::NullRange, cl::NDRange(m_particleCount), cl::NullRange, NULL, &event);
	if (err != CL_SUCCESS)
		std::cout << "Failed enqueueing kernel : " << getError(err) << std::endl;
	err = event.wait();
	if (err != CL_SUCCESS)
		std::cout << "ERROR" << std::endl;

	getQueue().enqueueCopyBuffer(m_clBuffer[Index::Particles], m_glBuffer[Index::Particles], 0, 0, m_particleCount * sizeof(Particle), NULL, NULL);
	err = getQueue().enqueueReleaseGLObjects(&buffers, NULL, NULL);
	if (err != CL_SUCCESS)
		std::cout << "Failed releasing GL object : " << getError(err) << std::endl;
	getQueue().finish();
}

void EmitterSystem::draw(void)
{
	glBindVertexArray(m_vao);
	glDrawArrays(GL_POINTS,0,m_particleCount);
	glBindVertexArray(0);
}
