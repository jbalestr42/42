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
	void update(float frametime);

private:
	static const std::size_t	IndexCount = 2u;
	enum Index
	{
		Position,
		Velocity
	};

	cl::Context				m_context;
	cl::Device				m_device;
	cl::CommandQueue		m_queue;
	cl::Program				m_program;
	cl::BufferGL			m_glBuffer[IndexCount];
	cl::Buffer				m_clBuffer[IndexCount];
	cl::Kernel				m_kernel;
	std::unique_ptr<Shader>	m_shader;
	GLuint					m_vao;
	GLuint					m_vbo[IndexCount];
	std::size_t				m_particleCount;
	Matrix					m_view;
	Matrix					m_projection;

	void initCircle(bool firsttime = false);
	void initSquare(bool firsttime = false);
	void initVelocity(bool firsttime = false);
	void loadData(void);

};

#endif
