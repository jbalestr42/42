#ifndef OPENCL_HPP
# define OPENCL_HPP

# include <CL/cl.hpp>
# include <memory>
# include "Shader.hpp"
# include "Vector3.hpp"
# include "Color.hpp"
# include "Matrix.hpp"

struct Particle
{
	Particle(void) = default;
	Particle(Vector3 const & p, Color const & c, Vector3 const & v) :
		position(p),
		color(c),
		velocity(v)
	{}
	~Particle(void) = default;

	Vector3		position;
	Color		color;
	Vector3		velocity;
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
	cl::Buffer cl_particles;

	GLuint vao;
	GLuint vbo;
	std::size_t num;    //the number of particles
	size_t array_size; //the size of our arrays num * sizeof(Vec4)

cl::Kernel kernel;
	std::unique_ptr<Shader>		m_shader;
	Matrix m_view;
	Matrix m_projection;

	void initCircle(bool firsttime = false);
	void initSquare(bool firsttime = false);
	void loadData(void);

};

#endif
