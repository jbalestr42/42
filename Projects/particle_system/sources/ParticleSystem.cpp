#include "ParticleSystem.hpp"

ParticleSystem::ParticleSystem(void) :
	m_particleCount(10u)
{ }

ParticleSystem::ParticleSystem(ParticleSystem const & particleSystem)
{
	*this = particleSystem;
}

ParticleSystem::~ParticleSystem(void) { }

ParticleSystem & ParticleSystem::operator=(ParticleSystem const & particleSystem)
{
	(void)particleSystem;
	return (*this);
}

void ParticleSystem::init(void)
{
	std::cout << "Initialize Particle System" << std::endl;
	glGenVertexArrays(1, &m_vertexArrayObject);
	glBindVertexArray(m_vertexArrayObject);
	glGenBuffers(2, m_vertexBufferObject);                        // create a vbo
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexBufferObject[0]);                    // activate vbo id to use
	glBufferData(GL_ARRAY_BUFFER, sizeof(ParticleSystem::Particle) * m_particleCount, 0, GL_DYNAMIC_DRAW); // we didn't upload data to video card

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(ParticleSystem::Particle), 0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(ParticleSystem::Particle), (GLvoid*)(sizeof(Vector3)));

	// check data size in VBO is same as input array, if not return 0 and delete VBO
	int bufferSize = 0;
	glGetBufferParameteriv(GL_ARRAY_BUFFER, GL_BUFFER_SIZE, &bufferSize);
	//this was important for working inside blender!
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	GLuint err = glGetError();
	if (err) // TODO remove
		std::cout << "ERROR (Particle System) : " << err << std::endl;
}
