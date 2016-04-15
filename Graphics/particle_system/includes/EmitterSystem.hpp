#ifndef EMITTERSYSTEM_HPP
# define EMITTERSYSTEM_HPP

# include <memory>
# include "ParticleSystem.hpp"

class EmitterSystem : public ParticleSystem
{
	struct Particle
	{
		Particle(void) = default;
		Particle(Vector3 const & p, float const & c) :
			position(p),
			color_lerp(c)
		{}
		~Particle(void) = default;
	
		Vector3		position;
		float		color_lerp;
	};

public:
	EmitterSystem(void);
	EmitterSystem(std::size_t particleCount);
	virtual ~EmitterSystem(void);

	void update(Camera & camera, float frametime);
	void draw(void);

private:
	static const std::size_t	IndexCount = 3u;
	enum Index
	{
		Particles,
		Velocity,
		Life
	};

	cl::BufferGL	m_glBuffer[IndexCount];
	cl::Buffer		m_clBuffer[IndexCount];
	GLuint			m_vao;
	GLuint			m_vbo[IndexCount];
	std::size_t		m_particleCount;
	bool			m_disableVelocity;

	void init(bool firsttime = false);
	void loadData(void);

	EmitterSystem(EmitterSystem const & openCL);
	EmitterSystem & operator=(EmitterSystem const & openCL);

};

#endif
