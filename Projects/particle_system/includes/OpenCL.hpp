#ifndef OPENCL_HPP
# define OPENCL_HPP

# include <CL/cl.hpp>
# include <memory>
# include "Shader.hpp"
# include "Vector3.hpp"
# include "Color.hpp"
# include "Matrix.hpp"

struct Vec4
{
    float x,y,z,w;
    Vec4(){};
    //convenience functions
    Vec4(float xx, float yy, float zz, float ww):
        x(xx),
        y(yy),
        z(zz),
        w(ww)
    {}
    void set(float xx, float yy, float zz, float ww=1.) {
        x = xx;
        y = yy;
        z = zz;
        w = ww;
    }
};

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
	void loadData(void);
	void runKernel(float frametime);

	std::vector<cl::Memory> cl_vbos;  //0: position vbo, 1: color vbo
	cl::BufferGL cl_vbo;
	cl::Buffer cl_particles;  //0: position vbo, 1: color vbo
	cl::Buffer cl_velocities;  //particle velocities
	cl::Buffer cl_pos_gen;  //want to have the start points for reseting particles
	cl::Buffer cl_vel_gen;  //want to have the start velocities for reseting particles

	int p_vbo;   //position vbo
	int c_vbo;   //colors vbo
	GLuint vao;
	GLuint vbo;
	std::size_t num;    //the number of particles
	size_t array_size; //the size of our arrays num * sizeof(Vec4)

private:
	cl::Context context;
	std::size_t deviceUsed;
	cl::Device			m_device;
	cl::CommandQueue queue;
	cl::Program program;
	cl::Kernel kernel;
	std::unique_ptr<Shader>		m_shader;
	Matrix m_view;
	Matrix m_projection;




};

#endif
