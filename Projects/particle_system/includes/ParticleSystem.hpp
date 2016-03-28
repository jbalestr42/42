#ifndef PARTICLESYSTEM_HPP
# define PARTICLESYSTEM_HPP

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

	ParticleSystem & operator=(ParticleSystem const & particleSystem);

private:
	GLuint			m_vertexArrayObject;
	GLuint			m_vertexBufferObject[2];
	std::size_t		m_particleCount;

};

#endif
