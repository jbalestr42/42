#include "OpenCL.hpp"
#include "Mouse.hpp"
#include "Keyboard.hpp"
#include "Math.hpp"
#include <GL/glew.h>
#define GLFW_EXPOSE_NATIVE_X11
#define GLFW_EXPOSE_NATIVE_GLX
#define __CL_ENABLE_EXCEPTIONS
#include <GLFW/glfw3.h>
#include <GLFW/glfw3native.h>
#include <iostream>
#include <random>

const char* oclErrorString(cl_int error)
{
	static const char* errorString[] = {
		"CL_SUCCESS",
		"CL_DEVICE_NOT_FOUND",
		"CL_DEVICE_NOT_AVAILABLE",
		"CL_COMPILER_NOT_AVAILABLE",
		"CL_MEM_OBJECT_ALLOCATION_FAILURE",
		"CL_OUT_OF_RESOURCES",
		"CL_OUT_OF_HOST_MEMORY",
		"CL_PROFILING_INFO_NOT_AVAILABLE",
		"CL_MEM_COPY_OVERLAP",
		"CL_IMAGE_FORMAT_MISMATCH",
		"CL_IMAGE_FORMAT_NOT_SUPPORTED",
		"CL_BUILD_PROGRAM_FAILURE",
		"CL_MAP_FAILURE",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"CL_INVALID_VALUE",
		"CL_INVALID_DEVICE_TYPE",
		"CL_INVALID_PLATFORM",
		"CL_INVALID_DEVICE",
		"CL_INVALID_CONTEXT",
		"CL_INVALID_QUEUE_PROPERTIES",
		"CL_INVALID_COMMAND_QUEUE",
		"CL_INVALID_HOST_PTR",
		"CL_INVALID_MEM_OBJECT",
		"CL_INVALID_IMAGE_FORMAT_DESCRIPTOR",
		"CL_INVALID_IMAGE_SIZE",
		"CL_INVALID_SAMPLER",
		"CL_INVALID_BINARY",
		"CL_INVALID_BUILD_OPTIONS",
		"CL_INVALID_PROGRAM",
		"CL_INVALID_PROGRAM_EXECUTABLE",
		"CL_INVALID_KERNEL_NAME",
		"CL_INVALID_KERNEL_DEFINITION",
		"CL_INVALID_KERNEL",
		"CL_INVALID_ARG_INDEX",
		"CL_INVALID_ARG_VALUE",
		"CL_INVALID_ARG_SIZE",
		"CL_INVALID_KERNEL_ARGS",
		"CL_INVALID_WORK_DIMENSION",
		"CL_INVALID_WORK_GROUP_SIZE",
		"CL_INVALID_WORK_ITEM_SIZE",
		"CL_INVALID_GLOBAL_OFFSET",
		"CL_INVALID_EVENT_WAIT_LIST",
		"CL_INVALID_EVENT",
		"CL_INVALID_OPERATION",
		"CL_INVALID_GL_OBJECT",
		"CL_INVALID_BUFFER_SIZE",
		"CL_INVALID_MIP_LEVEL",
		"CL_INVALID_GLOBAL_WORK_SIZE",
	};
	const int errorCount = sizeof(errorString) / sizeof(errorString[0]);
	const int index = -error;
	return (index >= 0 && index < errorCount) ? errorString[index] : "";
}

OpenCL::OpenCL(void) :
	m_shader(nullptr)
{
	m_shader.reset(new Shader("resources/default.frag", "resources/default.vert"));
	std::cout << "Initialize OpenCL" << std::endl;
	std::vector<cl::Platform> platforms;
	cl_int err = cl::Platform::get(&platforms);
	if (err)
		std::cout << "ERROR (" << oclErrorString(err) << "): no platform found." << std::endl;
	else
	{
		std::cout << "-> Loading Platform..." << std::endl;
		std::cout << platforms.front().getInfo<CL_PLATFORM_VENDOR>() << std::endl;
		std::cout << platforms.front().getInfo<CL_PLATFORM_NAME>() << " - ";
		std::cout << platforms.front().getInfo<CL_PLATFORM_VERSION>() << std::endl;
	}

	std::vector<cl::Device> devices;
	err = platforms[0].getDevices(CL_DEVICE_TYPE_GPU, &devices);
	if (err)
		std::cout << "ERROR (" << oclErrorString(err) << "): no device found." << std::endl;
	else
	{
		std::cout << "-> Loading Device..." << std::endl;
		std::cout << devices.front().getInfo<CL_DEVICE_VENDOR>() << std::endl;
		std::cout << devices.front().getInfo<CL_DEVICE_NAME>() << " (";
		std::cout << devices.front().getInfo<CL_DRIVER_VERSION>() << ")" << std::endl;
		m_device = devices.front();
	}

	// Define OS-specific context properties and create the OpenCL context
	// We setup OpenGL context sharing slightly differently on each OS
	// this code comes mostly from NVIDIA's SDK examples
	// we could also check to see if the device supports GL sharing
	// but that is just searching through the properties
	// an example is avaible in the NVIDIA code
#if defined(__APPLE__) || defined(MACOSX)
	CGLContextObj kCGLContext = CGLGetCurrentContext();
	CGLShareGroupObj kCGLShareGroup = CGLGetShareGroup(kCGLContext);
	cl_context_properties props[] =
	{
		CL_CONTEXT_PROPERTY_USE_CGL_SHAREGROUP_APPLE, (cl_context_properties)kCGLShareGroup,
		0
	};
	//Apple's implementation is weird, and the default values assumed by cl.hpp don't work
	//this works
	//cl_context cxGPUContext = clCreateContext(props, 0, 0, NULL, NULL, &err);
	//these dont
	//cl_context cxGPUContext = clCreateContext(props, 1,(cl_device_id*)&devices.front(), NULL, NULL, &err);
	//cl_context cxGPUContext = clCreateContextFromType(props, CL_DEVICE_TYPE_GPU, NULL, NULL, &err);
	//printf("error? %s\n", oclErrorString(err));
	try
	{
		context = cl::Context(props);   //had to edit line 1448 of cl.hpp to add this constructor
	}
	catch (cl::Error er)
	{
		std::cout << "ERROR : " << e.what() << std::endl;
	}
#else
	cl_context_properties props[] =
	{
		CL_GL_CONTEXT_KHR, (cl_context_properties)glfwGetGLXContext(glfwGetCurrentContext()),
		CL_GLX_DISPLAY_KHR, (cl_context_properties)glfwGetX11Display(),
		CL_CONTEXT_PLATFORM, (cl_context_properties)platforms[0](),
		0
	};
	try
	{
		std::cout << "-> Creating Context..." << std::endl;
		context = cl::Context(m_device, props);
	}
	catch (std::exception e)
	{
		std::cout << "ERROR : " << e.what() << std::endl;
	}
#endif

	deviceUsed = 0;
	//create the command queue we will use to execute OpenCL commands
	std::cout << "-> Creating Command..." << std::endl;
	queue = cl::CommandQueue(context, m_device, 0, &err);
	if (err)
		std::cout << "ERROR (" << oclErrorString(err) << "): no device found." << std::endl;
}

OpenCL::OpenCL(OpenCL const & openCL)
{
	*this = openCL;
}

OpenCL::~OpenCL(void) { }

OpenCL & OpenCL::operator=(OpenCL const & openCL)
{
	(void)openCL;
	return (*this);
}
void OpenCL::loadProgram(std::string const & kernel_source)
{
	size_t size = 0u;
	cl_int err = 0;

	std::cout << "-> Loading Program..." << std::endl;
	size = kernel_source.size();
	std::cout << "Kernel Size : " << size << std::endl;
	try
	{
		cl::Program::Sources source(1, std::make_pair(kernel_source.c_str(), size));
		program = cl::Program(context, source);
	}
	catch (std::exception e)
	{
		std::cout << "ERROR : " << e.what() << std::endl;
	}

	std::cout << "-> Building Program..." << std::endl;
	if ((err = program.build(std::vector<cl::Device>(1, m_device))))
		std::cout << "ERROR (" << oclErrorString(err) << "): no device found." << std::endl;
	std::cout << "TO remove if nothing happened" << std::endl;
	std::cout << "Build Status: " << program.getBuildInfo<CL_PROGRAM_BUILD_STATUS>(m_device) << std::endl;
	std::cout << "Build Options: " << program.getBuildInfo<CL_PROGRAM_BUILD_OPTIONS>(m_device) << std::endl;
	std::cout << "Build Log: " << program.getBuildInfo<CL_PROGRAM_BUILD_LOG>(m_device) << std::endl;

	kernel = cl::Kernel(program, "animate", &err);
	if (err)
		std::cout << "ERROR (" << oclErrorString(err) << "): kernel loading failed." << std::endl;

	loadData();
}

void OpenCL::initSquare(bool firsttime)
{
	std::cout << "-> Initialize particles as a square." << std::endl;
	cl_int err = 0;
	std::random_device rd;
	std::mt19937 eng(rd());
	std::uniform_real_distribution<float> dist(-0.5f, 0.5f);
	std::uniform_real_distribution<float> dist_life(0.2f, 1.f);
	std::uniform_real_distribution<float> dist_vel(0.f, 1.f);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	Particle *p = static_cast<Particle*>(glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY));
	for (std::size_t i = 0; i < num; i++)
	{
		p[i].position = Vector3(dist(eng), dist(eng), dist(eng));
	}
	if (firsttime)
	{
		cl_vbo = cl::BufferGL(context, CL_MEM_READ_WRITE, vbo, &err);
		if (err)
			std::cout << "ERROR (" << oclErrorString(err) << "): kernel loading failed." << std::endl;
		cl_particles = cl::Buffer(context, CL_MEM_READ_WRITE, num * sizeof(Particle), NULL, &err);
	}
	err = queue.enqueueWriteBuffer(cl_particles, CL_TRUE, 0, num * sizeof(Particle), p);
	if (err)
		std::cout << "ERROR -> " << oclErrorString(err) << std::endl;
	glUnmapBuffer(GL_ARRAY_BUFFER);

	glBindBuffer(GL_ARRAY_BUFFER, vbo_vel);
	Vector3 *v = static_cast<Vector3*>(glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY));
	for (std::size_t i = 0; i < num; i++)
		v[i] = Vector3(0.f, 0.f, 0.f);
	if (firsttime)
	{
		cl_vbo_vel = cl::BufferGL(context, CL_MEM_READ_WRITE, vbo_vel, &err);
		if (err)
			std::cout << "ERROR (" << oclErrorString(err) << "): kernel loading failed." << std::endl;
		cl_particles_vel = cl::Buffer(context, CL_MEM_READ_WRITE, num * sizeof(Vector3), NULL, &err);
	}
	err = queue.enqueueWriteBuffer(cl_particles_vel, CL_TRUE, 0, num * sizeof(Vector3), v);
	if (err)
		std::cout << "ERROR -> " << oclErrorString(err) << std::endl;
	glUnmapBuffer(GL_ARRAY_BUFFER);
}

void OpenCL::initCircle(bool firsttime)
{
	std::cout << "-> Initialize particles as a circle." << std::endl;
	cl_int err = 0;
	std::random_device rd;
	std::mt19937 eng(rd());
	std::uniform_real_distribution<float> dist(0.f, 0.5f);
	std::uniform_real_distribution<float> dist_life(0.2f, 1.f);
	std::uniform_real_distribution<float> dist_vel(0.f, 1.f);
	std::uniform_real_distribution<float> dist_polar(0.f, Pi2);
	std::uniform_real_distribution<float> dist_half_polar(-PiDiv2, PiDiv2);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	Particle *p = static_cast<Particle*>(glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY));
	for (std::size_t i = 0; i < num; i++)
	{
		float theta = dist_polar(eng);
		float phi = dist_half_polar(eng);
		float radius = dist(eng);
		p[i].position = Vector3(radius * std::cos(theta) * std::cos(phi),
								radius * std::sin(phi),
								radius * std::sin(theta) * std::cos(phi));
	}
	if (firsttime)
	{
		cl_vbo = cl::BufferGL(context, CL_MEM_READ_WRITE, vbo, &err);
		if (err)
			std::cout << "ERROR (" << oclErrorString(err) << "): kernel loading failed." << std::endl;
		cl_particles = cl::Buffer(context, CL_MEM_READ_WRITE, num * sizeof(Particle), NULL, &err);
	}
	err = queue.enqueueWriteBuffer(cl_particles, CL_TRUE, 0, num * sizeof(Particle), p);
	if (err)
		std::cout << "ERROR -> " << oclErrorString(err) << std::endl;
	glUnmapBuffer(GL_ARRAY_BUFFER);

	glBindBuffer(GL_ARRAY_BUFFER, vbo_vel);
	Vector3 *v = static_cast<Vector3*>(glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY));
	for (std::size_t i = 0; i < num; i++)
		v[i] = Vector3(0.f, 0.f, 0.f);
	if (firsttime)
	{
		cl_vbo_vel = cl::BufferGL(context, CL_MEM_READ_WRITE, vbo_vel, &err);
		if (err)
			std::cout << "ERROR (" << oclErrorString(err) << "): kernel loading failed." << std::endl;
		cl_particles_vel = cl::Buffer(context, CL_MEM_READ_WRITE, num * sizeof(Vector3), NULL, &err);
	}
	err = queue.enqueueWriteBuffer(cl_particles_vel, CL_TRUE, 0, num * sizeof(Vector3), v);
	if (err)
		std::cout << "ERROR -> " << oclErrorString(err) << std::endl;
	glUnmapBuffer(GL_ARRAY_BUFFER);
}

void OpenCL::loadData(void)
{
	cl_int err = 0;

	num = 1000000;

	std::cout << "-> Initializing particle in GPU memory" << std::endl;

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, num * sizeof(Particle), NULL, GL_STATIC_DRAW); // check static

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Particle), (GLvoid*)0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 1, GL_FLOAT, GL_FALSE, sizeof(Particle), (GLvoid*)(sizeof(Vector3)));

	initCircle(true);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	glGenBuffers(1, &vbo_vel);
	glBindBuffer(GL_ARRAY_BUFFER, vbo_vel);
	glBufferData(GL_ARRAY_BUFFER, num * sizeof(Vector3), NULL, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	if ((err = kernel.setArg(0, cl_particles)))
		std::cout << "ERROR (" << err << ") " << oclErrorString(err) << std::endl;
	if ((err = kernel.setArg(1, cl_particles_vel)))
		std::cout << "ERROR (" << err << ") " << oclErrorString(err) << std::endl;

	Matrix model;
	m_shader->bind();
	m_view.translate(Vector3(0.f, 0.f, -10.0f));
	m_shader->setParameter("ViewMatrix", m_view);
	m_shader->setParameter("ModelMatrix", model);
	m_projection.perspectiveProjection(60.f, 800.f / 600.f, 0.1f, 100.f);
	m_shader->setParameter("ProjectionMatrix", m_projection);
	if ((err = glGetError()))
		std::cout << "ERROR (" << err << ") " << oclErrorString(err) << std::endl;

    glEnable(GL_POINT_SMOOTH);
	glPointSize(0.5f);
}

void OpenCL::runKernel(float frametime)
{
	glFinish();

	if (Keyboard::isKeyPressed(GLFW_KEY_F))
		initCircle();
	if (Keyboard::isKeyPressed(GLFW_KEY_G))
		initSquare();

	(void)frametime;
	cl::Event event;
	cl_int err = 0;
	std::vector<cl::Memory> buffers;
	buffers.push_back(cl_vbo);
	err = queue.enqueueAcquireGLObjects(&buffers, NULL, NULL);
	if (err != CL_SUCCESS)
		std::cout << "Failed acquiring GL object : " << oclErrorString(err) << std::endl;
	err = queue.finish();
	if (err != CL_SUCCESS)
		std::cout << "ERROR" << std::endl;

	if (Mouse::isButtonPress(GLFW_MOUSE_BUTTON_LEFT))
	{
		err = kernel.setArg(3, (Mouse::getPosition().x - 0.5f) * 8.f);
		err = kernel.setArg(4, 1.f - (Mouse::getPosition().y - 0.5f ) * 8.f);
		if (err != CL_SUCCESS)
			std::cout << "ERROR kernel args" << std::endl;
	}
	else
	{
		err = kernel.setArg(3, 0.f);
		err = kernel.setArg(4, 0.f);
	}
	err = kernel.setArg(2, frametime);
	if (err != CL_SUCCESS)
		std::cout << "ERROR kernel args" << std::endl;

	err = queue.enqueueNDRangeKernel(kernel, cl::NullRange, cl::NDRange(num), cl::NullRange, NULL, &event);
	if (err != CL_SUCCESS)
		std::cout << "Failed enqueueing kernel : " << oclErrorString(err) << std::endl;
	err = event.wait();
	if (err != CL_SUCCESS)
		std::cout << "ERROR" << std::endl;

	queue.enqueueCopyBuffer(cl_particles, cl_vbo, 0, 0, num * sizeof(Particle), NULL, NULL);
	err = queue.enqueueReleaseGLObjects(&buffers, NULL, NULL);
	if (err != CL_SUCCESS)
		std::cout << "Failed releasing GL object : " << oclErrorString(err) << std::endl;
	queue.finish();

	glBindVertexArray(vao);
	glDrawArrays(GL_POINTS,0,num);
	glBindVertexArray(0);
}
