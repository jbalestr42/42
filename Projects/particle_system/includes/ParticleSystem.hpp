#ifndef PARTICLESYSTEM_HPP
# define PARTICLESYSTEM_HPP

# if defined(__APPLE__) || defined(MACOSX)
#  define GL_GLEXT_PROTOTYPES
#  define EGL_EGLEXT_PROTOTYPES
#  include <GL/glew.h>
#  include <GLFW/glfw3.h>
#  include <OpenGL/OpenGL.h> // <---- That line was missing
#  include <OpenCL/opencl.h>
#  include <OpenCL/cl_gl.h>
#  include "cl.hpp"
# else // Linux
#  include <CL/cl.hpp>
#  include <memory>
#  include <GL/glew.h>
#  define GLFW_EXPOSE_NATIVE_X11
#  define GLFW_EXPOSE_NATIVE_GLX
#  define __CL_ENABLE_EXCEPTIONS
#  include <GLFW/glfw3.h>
#  include <GLFW/glfw3native.h>
# endif


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
