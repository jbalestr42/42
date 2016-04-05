#ifndef PARTICLESYSTEM_HPP
# define PARTICLESYSTEM_HPP

# include "Vector3.hpp"
# include "Color.hpp"
# include <GL/glew.h>
# include <GLFW/glfw3.h>

class ParticleSystem
{
public:
	ParticleSystem(void);
	virtual ~ParticleSystem(void);

	void init(void);


private:

	ParticleSystem(ParticleSystem const & particleSystem);
	ParticleSystem & operator=(ParticleSystem const & particleSystem);

};

#endif
