#include "Windows.hpp"
#include "Shader.hpp"
#include "Keyboard.hpp"
#include "Mouse.hpp"
#include "GravitySystem.hpp"
#include "Camera.hpp"
#include <sstream>

int main(void)
{
	Windows win(1902, 1080, "Particle System");
	win.setClearColor(Color::Black);
	Camera camera;

	glfwSetTime(0.f);
	float lastTime = 0.f;

	GravitySystem cl(1000000);
	while (win.isOpen())
	{
		// Compute frametime
		float currentTime = glfwGetTime();
		float frametime = (currentTime - lastTime);
		lastTime = currentTime;
		std::ostringstream ss;
		ss << (1.f / frametime);
		std::string s(ss.str());
		win.setTitle(s);

		// Inputs
		if (Keyboard::isKeyPressed(GLFW_KEY_ESCAPE))
			win.close();

		// Update
		cl.update(camera, frametime);
		camera.update(frametime);

		// Draw
		win.clear();
		cl.draw();

		win.display();
		win.pollEvents();
	}
	return (0);
}
