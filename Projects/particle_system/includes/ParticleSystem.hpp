#ifndef PARTICLESYSTEM_HPP
# define PARTICLESYSTEM_HPP

# include <CL/cl.hpp>
# include "Vector3.hpp"
# include "Color.hpp"
# include "Camera.hpp"

class ParticleSystem
{
public:
	ParticleSystem(std::string const & filename);
	virtual ~ParticleSystem(void);

	virtual void update(Camera & camera, float frametime) = 0;
	virtual void draw(void) = 0;

protected:
	ParticleSystem(void) = delete;
	ParticleSystem(ParticleSystem const & particleSystem);
	ParticleSystem & operator=(ParticleSystem const & particleSystem);

	cl::Kernel & getKernel(void);
	cl::Program & getProgram(void);
	cl::Context & getContext(void);
	cl::Device & getDevice(void);
	cl::CommandQueue & getQueue(void);
	const char * getError(cl_int error);

private:
	cl::Kernel				m_kernel;
	cl::Program				m_program;
	cl::Context				m_context;
	cl::Device				m_device;
	cl::CommandQueue		m_queue;

	void loadProgram(std::string const & kernelSource);

};

#endif
