#ifndef OPENCL_HPP
# define OPENCL_HPP

#define __CL_ENABLE_EXCEPTIONS

//apple
# define GL_GLEXT_PROTOTYPES
# define EGL_EGLEXT_PROTOTYPES
# include <GL/glew.h>
# include <GLFW/glfw3.h>
# include <OpenGL/OpenGL.h> // <---- That line was missing
# include <OpenCL/opencl.h>
# include <OpenCL/cl_gl.h>
# include "cl.hpp"

//linux
//# include <CL/cl.hpp>
//#define GLFW_EXPOSE_NATIVE_X11
//#define GLFW_EXPOSE_NATIVE_GLX

# include <memory>
# include "Shader.hpp"
# include "Vector3.hpp"
# include "Color.hpp"
# include "Matrix.hpp"
//#include <GLFW/glfw3native.h> //TODO is linux or apple

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

class OpenCL
{
public:
	OpenCL(void);
	OpenCL(OpenCL const & openCL);
	virtual ~OpenCL(void);

	OpenCL & operator=(OpenCL const & openCL);

	void loadProgram(std::string const & kernel_source);
	void runKernel(float frametime);

private:
	cl::Context context;
	std::size_t deviceUsed;
	cl::Device			m_device;
	cl::CommandQueue queue;
	cl::Program program;
	cl::BufferGL cl_vbo;
	cl::BufferGL cl_vbo_vel;
	cl::Buffer cl_particles;
	cl::Buffer cl_particles_vel;

	GLuint vao;
	GLuint vbo;
	GLuint vbo_vel;
	std::size_t num;    //the number of particles

cl::Kernel kernel;
	std::unique_ptr<Shader>		m_shader;
	Matrix m_view;
	Matrix m_projection;

	void initCircle(bool firsttime = false);
	void initSquare(bool firsttime = false);
	void loadData(void);

};

#endif
