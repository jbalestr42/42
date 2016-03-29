#ifndef PARTICLESYSTEM_HPP
# define PARTICLESYSTEM_HPP

# include "Vector3.hpp"
# include "Color.hpp"
# include <GL/glew.h>
# include <GLFW/glfw3.h>

class ParticleSystem
{
public:
	class Particle
	{
	public:
		Particle(void);
		virtual ~Particle(void);

		Particle(Particle const & particle);

		Particle & operator=(Particle const & particle);

		Vector3		m_position;
		Color		m_color;
	};

	ParticleSystem(void);
	ParticleSystem(ParticleSystem const & particleSystem);
	virtual ~ParticleSystem(void);

	void init(void);

	ParticleSystem & operator=(ParticleSystem const & particleSystem);

private:
	GLuint			m_vertexArrayObject;
	GLuint			m_vertexBufferObject[2];
	std::size_t		m_particleCount;

};

#endif
