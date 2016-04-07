#include "ParticleSystem.hpp"
#include <fstream>
#include <streambuf>

ParticleSystem::ParticleSystem(std::string const & filename)
{
	std::ifstream t(filename);
	std::string kernelSource((std::istreambuf_iterator<char>(t)),
			std::istreambuf_iterator<char>());

	std::cout << "-> Initializing OpenCL..." << std::endl;
	std::vector<cl::Platform> platforms;
	cl_int err = cl::Platform::get(&platforms);
	if (err)
		std::cout << "ERROR (" << getError(err) << "): no platform found." << std::endl;
	else
	{
		std::cout << "-> Loading Platform..." << std::endl;
		std::cout << " - " << platforms.front().getInfo<CL_PLATFORM_VENDOR>() << std::endl;
		std::cout << " - " << platforms.front().getInfo<CL_PLATFORM_NAME>() << " - ";
		std::cout << " - " << platforms.front().getInfo<CL_PLATFORM_VERSION>() << std::endl;
	}

	std::vector<cl::Device> devices;
	err = platforms[0].getDevices(CL_DEVICE_TYPE_GPU, &devices);
	if (err)
		std::cout << "ERROR (" << getError(err) << "): no device found." << std::endl;
	else
	{
		std::cout << "-> Loading Device..." << std::endl;
		std::cout << " - " << devices.front().getInfo<CL_DEVICE_VENDOR>() << std::endl;
		std::cout << " - " << devices.front().getInfo<CL_DEVICE_NAME>() << " (";
		std::cout << " - " << devices.front().getInfo<CL_DRIVER_VERSION>() << ")" << std::endl;
		m_device = devices.front();
	}

#if defined(__APPLE__) || defined(MACOSX)
	CGLContextObj kCGLContext = CGLGetCurrentContext();
	CGLShareGroupObj kCGLShareGroup = CGLGetShareGroup(kCGLContext);
	cl_context_properties props[] =
	{
		CL_CONTEXT_PROPERTY_USE_CGL_SHAREGROUP_APPLE, (cl_context_properties)kCGLShareGroup,
		0
	};
	try
	{
		m_context = clCreateContext(props, 0, 0, NULL, NULL, &err);   //had to edit line 1448 of cl.hpp to add this constructor
	}
	catch (std::exception e)
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
		m_context = cl::Context(m_device, props);
	}
	catch (std::exception e)
	{
		std::cout << "ERROR : " << e.what() << std::endl;
	}
#endif

	std::cout << "-> Creating Command..." << std::endl;
	m_queue = cl::CommandQueue(m_context, m_device, 0, &err);
	if (err)
		std::cout << "ERROR (" << getError(err) << "): no device found." << std::endl;

	loadProgram(kernelSource);
}

ParticleSystem::ParticleSystem(ParticleSystem const & particleSystem)
{
	*this = particleSystem;
}

ParticleSystem::~ParticleSystem(void) { }

ParticleSystem & ParticleSystem::operator=(ParticleSystem const & particleSystem)
{
	(void)particleSystem;
	return (*this);
}

void ParticleSystem::loadProgram(std::string const & kernelSource)
{
	size_t size = 0u;
	cl_int err = 0;

	std::cout << "-> Loading Program..." << std::endl;
	size = kernelSource.size();
	std::cout << " - Kernel Size : " << size << std::endl;
	try
	{
		cl::Program::Sources source(1, std::make_pair(kernelSource.c_str(), size));
		m_program = cl::Program(m_context, source);
	}
	catch (std::exception e)
	{
		std::cout << "ERROR : " << e.what() << std::endl;
	}

	std::cout << "-> Building Program..." << std::endl;
	if ((err = m_program.build(std::vector<cl::Device>(1, m_device))))
		std::cout << "ERROR (" << getError(err) << "): no device found." << std::endl;
	std::cout << " - Build Status: " << m_program.getBuildInfo<CL_PROGRAM_BUILD_STATUS>(m_device) << std::endl;
	std::cout << " - Build Options: " << m_program.getBuildInfo<CL_PROGRAM_BUILD_OPTIONS>(m_device) << std::endl;
	std::cout << " - Build Log: " << m_program.getBuildInfo<CL_PROGRAM_BUILD_LOG>(m_device) << std::endl;

	m_kernel = cl::Kernel(m_program, "animate", &err);
	if (err)
		std::cout << "ERROR (" << getError(err) << "): kernel loading failed." << std::endl;
}

cl::Kernel & ParticleSystem::getKernel(void)
{
	return (m_kernel);
}

cl::Program & ParticleSystem::getProgram(void)
{
	return (m_program);
}

cl::Context & ParticleSystem::getContext(void)
{
	return (m_context);
}

cl::Device & ParticleSystem::getDevice(void)
{
	return (m_device);
}

cl::CommandQueue & ParticleSystem::getQueue(void)
{
	return (m_queue);
}

const char * ParticleSystem::getError(cl_int error)
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
