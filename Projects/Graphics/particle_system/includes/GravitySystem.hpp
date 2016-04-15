#ifndef GRAVITYSYSTEM_HPP
# define GRAVITYSYSTEM_HPP

# include <memory>
# include "ParticleSystem.hpp"

class GravitySystem : public ParticleSystem
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
	GravitySystem(void);
	GravitySystem(std::size_t particleCount);
	virtual ~GravitySystem(void);

	void update(Camera & camera, float frametime);
	void draw(void);

private:
	static const std::size_t	IndexCount = 2u;
	enum Index
	{
		Particles,
		Velocity
	};

	cl::BufferGL	m_glBuffer[IndexCount];
	cl::Buffer		m_clBuffer[IndexCount];
	GLuint			m_vao;
	GLuint			m_vbo[IndexCount];
	std::size_t		m_particleCount;
	bool			m_disableVelocity;

	void initCircle(bool firsttime = false);
	void initCustom(bool firsttime = false);
	void initSquare(bool firsttime = false);
	void initVelocity(bool firsttime = false);
	void loadData(void);

	GravitySystem(GravitySystem const & openCL);
	GravitySystem & operator=(GravitySystem const & openCL);

};

#endif
