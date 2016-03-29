#include "OpenCL.hpp"
#include "Mouse.hpp"
#include <GL/glew.h>
#define GLFW_EXPOSE_NATIVE_X11
#define GLFW_EXPOSE_NATIVE_GLX
#define __CL_ENABLE_EXCEPTIONS
#include <GLFW/glfw3.h>
#include <GLFW/glfw3native.h>
#include <iostream>
#include <cmath>
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
	// Program Setup
	size_t size;
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

	cl_int err = 0;
	std::cout << "-> Building Program..." << std::endl;
	err = program.build(std::vector<cl::Device>(1, m_device));
	if (err)
		std::cout << "ERROR (" << oclErrorString(err) << "): no device found." << std::endl;
	std::cout << "TO remove if nothing happened" << std::endl;
	std::cout << "Build Status: " << program.getBuildInfo<CL_PROGRAM_BUILD_STATUS>(m_device) << std::endl;
	std::cout << "Build Options:\t" << program.getBuildInfo<CL_PROGRAM_BUILD_OPTIONS>(m_device) << std::endl;
	std::cout << "Build Log:\t " << program.getBuildInfo<CL_PROGRAM_BUILD_LOG>(m_device) << std::endl;

	kernel = cl::Kernel(program, "part2", &err); // TODO: rename part2
	if (err)
		std::cout << "ERROR (" << oclErrorString(err) << "): kernel loading failed." << std::endl;
}

void OpenCL::loadData(void)
{
	cl_int err = 0;
	glGetError();
	//store the number of particles and the size in bytes of our arrays
	//num = pos.size();
	//array_size = num * sizeof(Vec4);
	//create VBOs (defined in util.cpp)
	//p_vbo = createVBO(&pos[0], array_size, GL_DYNAMIC_DRAW);
	//c_vbo = createVBO(&col[0], array_size, GL_DYNAMIC_DRAW);
	num = 1000000;
	std::vector<Particle>		particles;
	std::random_device rd;
	std::mt19937 eng(rd());
	std::normal_distribution<float> dist(0.f, 5.f);
	std::normal_distribution<float> dist_life(0.2f, 2.f);
	//fill our vectors with initial data
	for (std::size_t i = 0; i < num; i++)
	{
		//distribute the particles in a random circle around z axis
		//pos[i] = Vec4(x, y, z, 1.0f);

		//give some initial velocity 
		float xr = dist(eng);
		float yr = dist(eng);
		//the life is the lifetime of the particle: 1 = alive 0 = dead
		//as you will see in part2.cl we reset the particle when it dies
		float life_r = dist_life(eng);
		//vel[i] = Vec4(0.0, 0.0, 3.0f, life_r);

		//just make them red and full alpha
		//color[i] = Vec4(1.0f, 0.0f,0.0f, 1.0f);
		particles.emplace_back(Vector3(dist(eng), dist(eng), dist(eng)), Color(1.f, 0.f, 0.f, life_r), Vector3(xr, yr, xr * yr));
	}

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glGenBuffers(1, &vbo);                        // create a vbo
	glBindBuffer(GL_ARRAY_BUFFER, vbo);                    // activate vbo id to use
	glBufferData(GL_ARRAY_BUFFER, num * sizeof(Particle), &particles[0], GL_DYNAMIC_DRAW); // upload data to video card

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Particle), (GLvoid*)0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Particle), (GLvoid*)(sizeof(Vector3)));
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Particle), (GLvoid*)(sizeof(Vector3) + sizeof(Color)));

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);


	//make sure OpenGL is finished before we proceed
	glFinish();
	printf("gl interop!\n");
	// create OpenCL buffer from GL VBO
	err = 0;
	cl_vbo = cl::BufferGL(context, CL_MEM_READ_WRITE, vbo, NULL); //TODO check for error
	if (err)
		std::cout << "ERROR (" << oclErrorString(err) << "): kernel loading failed." << std::endl;

	//cl_vbos.push_back(cl::BufferGL(context, CL_MEM_READ_WRITE, p_vbo, &err));
	//printf("p_vbo: %s (%i)\n", oclErrorString(err), err);
	//cl_vbos.push_back(cl::BufferGL(context, CL_MEM_READ_WRITE, c_vbo, &err));
	//printf("c_vbo: %s (%i)\n", oclErrorString(err), err);
	//we don't need to push any data here because it's already in the VBO

	//TODO access data here and initialize it here too

	//create the OpenCL only arrays
	cl_particles = cl::Buffer(context, CL_MEM_READ_WRITE, num * sizeof(Particle), NULL, &err);
	//cl_velocities = cl::Buffer(context, CL_MEM_WRITE_ONLY, array_size, NULL, &err);
	//cl_pos_gen = cl::Buffer(context, CL_MEM_WRITE_ONLY, array_size, NULL, &err);
	//cl_vel_gen = cl::Buffer(context, CL_MEM_WRITE_ONLY, array_size, NULL, &err);

	printf("Pushing data to the GPU\n");
	//push our CPU arrays to the GPU
	//data is tightly packed in std::vector starting with the adress of the first element
	err = queue.enqueueWriteBuffer(cl_particles, CL_TRUE, 0, num * sizeof(Particle), &particles[0]);
	if (err)
		std::cout << "ERROR -> " << err << std::endl;
	//err = queue.enqueueWriteBuffer(cl_velocities, CL_TRUE, 0, array_size, &vel[0], NULL, &event);
	//if (err)
	//	std::cout << "ERROR -> " << err << std::endl;
	//err = queue.enqueueWriteBuffer(cl_pos_gen, CL_TRUE, 0, array_size, &pos[0], NULL, &event);
	//if (err)
	//	std::cout << "ERROR -> " << err << std::endl;
	//err = queue.enqueueWriteBuffer(cl_vel_gen, CL_TRUE, 0, array_size, &vel[0], NULL, &event);
	//if (err)
	//	std::cout << "ERROR -> " << err << std::endl;
	queue.finish();

	//set the arguements of our kernel
	try
	{
		err = kernel.setArg(0, cl_particles);
	}
	catch (std::exception er) {
		printf("ERROR: %s\n", er.what());//, oclErrorString(er.err()));
	}
	//Wait for the command queue to finish these commands before proceeding
	queue.finish();

	Matrix model;
	m_shader->bind();
	m_view.translate(Vector3(0.f, 0.f, -25.0f));
	m_shader->setParameter("ViewMatrix", m_view);
	m_shader->setParameter("ModelMatrix", model);
	m_projection.perspectiveProjection(60.f, 800.f / 600.f, 0.1f, 100.f);
	m_shader->setParameter("ProjectionMatrix", m_projection);
	if ((err = glGetError())) // TODO remove
		std::cout << "error (" << err << ") " << oclErrorString(err) << std::endl;
}

inline unsigned divup(unsigned a, unsigned b)
{
    return (a+b-1)/b;
}

void OpenCL::runKernel(float frametime)
{
	glFinish();

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
		err = kernel.setArg(2, Mouse::getPosition()); //pass in the timestep
	err = kernel.setArg(1, frametime); //pass in the timestep
	//if (err != CL_SUCCESS)
	//	std::cout << "ERROR kernel args" << std::endl;

	//cl::NDRange local(16);
	//cl::NDRange global(16 * divup(num, 16));
	err = queue.enqueueNDRangeKernel(kernel, cl::NullRange, cl::NDRange(num), cl::NullRange, NULL, &event);//global, local);
	//if (err != CL_SUCCESS)
	//	std::cout << "Failed enqueueing kernel : " << oclErrorString(err) << std::endl;
	err = event.wait();
	//if (err != CL_SUCCESS)
	//	std::cout << "ERROR" << std::endl;

	queue.enqueueCopyBuffer(cl_particles, cl_vbo, 0, 0, num * sizeof(Particle), NULL, NULL);
	//Release the VBOs so OpenGL can play with them
	err = queue.enqueueReleaseGLObjects(&buffers, NULL, NULL);
	if (err != CL_SUCCESS)
		std::cout << "Failed releasing GL object : " << oclErrorString(err) << std::endl;
	queue.finish();

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.2,0.2,0.2,1.0);
    glEnable(GL_DEPTH_TEST);

	// now render stuff
	glPointSize(0.01);
	glBindVertexArray(vao);
	glDrawArrays(GL_POINTS,0,num);
	glBindVertexArray(0);

	if ((err = glGetError())) // TODO remove
		std::cout << "error (" << err << ") " << oclErrorString(err) << std::endl;
}
