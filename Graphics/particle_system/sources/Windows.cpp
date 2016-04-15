#include "Windows.hpp"
#include "Keyboard.hpp"
#include "Mouse.hpp"
#include <iostream>

Windows::Windows(void) :
	Windows(800u, 600u, "OpenGL Window")
{
}

Windows::Windows(int width, int height, char const * title) :
	m_window(nullptr),
	m_width(width),
	m_height(height),
	m_title(title)
{
	init();
}

Windows::Windows(Windows const & windows)
{
	*this = windows;
}

Windows::~Windows(void)
{
	glfwDestroyWindow(m_window);
	glfwTerminate();
}

Windows & Windows::operator=(Windows const & windows)
{
	(void)windows;
	return (*this);
}

void Windows::init(void)
{
	glfwSetErrorCallback(errorCallback);

	if (!glfwInit())
		exit(EXIT_FAILURE);

	glfwWindowHint(GLFW_SAMPLES, 4); // antialiasing
#if defined(__APPLE__) || defined(MACOSX)
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, true);
#else
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
#endif
	glfwWindowHint(GLFW_DEPTH_BITS, 16);

	glfwWindowHint(GLFW_RESIZABLE, true);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	// if debug
	// glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, true);
	m_window = glfwCreateWindow(m_width, m_height, m_title, NULL, NULL);
	if (!m_window)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	glfwSetKeyCallback(m_window, Keyboard::callback);
	glfwSetMouseButtonCallback(m_window, Mouse::callbackButton);
	glfwSetCursorPosCallback(m_window, Mouse::callbackPosition);
	glfwSetFramebufferSizeCallback(m_window, resizeCallback);

	glfwMakeContextCurrent(m_window);
	glewExperimental = true;
	if (glewInit() != GLEW_OK)
	{
		std::cerr << "Failed to initialize GLEW" << std::endl;
		exit(EXIT_FAILURE);
	}
	glGetError();
	glfwSwapInterval(1); // vsync
	glfwGetFramebufferSize(m_window, &m_width, &m_height);
	resizeCallback(m_window, m_width, m_height);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

bool Windows::isOpen(void) const
{
	return (!glfwWindowShouldClose(m_window));
}

void Windows::clear(void) const
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Windows::display(void) const
{
	glfwSwapBuffers(m_window);
}

void Windows::pollEvents(void) const
{
	glfwPollEvents();
}

void Windows::close(void)
{
	glfwSetWindowShouldClose(m_window, true);
}

GLFWwindow * Windows::getWindow(void) const
{
	return m_window;
}

void Windows::setClearColor(Color const & color)
{
	glClearColor(color.r, color.g, color.b, color.a);
}

void Windows::setTitle(std::string const & title)
{
	glfwSetWindowTitle(m_window, title.c_str());
}

void Windows::errorCallback(int error, char const * description)
{
	std::cerr << "ERROR " << error << " : " << description << std::endl;
}

void Windows::resizeCallback(GLFWwindow * window, int width, int height)
{
	(void)window;
	glViewport( 0, 0, (GLsizei)width, (GLsizei)height);
}
