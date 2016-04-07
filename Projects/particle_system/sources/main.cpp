#include "Windows.hpp"
#include "Shader.hpp"
#include "Keyboard.hpp"
#include "Mouse.hpp"
#include "GravitySystem.hpp"
#include "EmitterSystem.hpp"
#include "Camera.hpp"
#include <sstream>

ParticleSystem * parseArgs(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "Usage : ./particle_system particle_count system_type" << std::endl;
		std::cout << "Type : " << std::endl;
		std::cout << "  - gravity_system : 1" << std::endl;
		std::cout << "  - emitter_system : 2" << std::endl;
		return (nullptr);
	}
	int particleCount;
	if (argc >= 2)
	{
		particleCount = std::atoi(argv[1]);
		if (particleCount > 5000000)
			return (nullptr);
	}
	if (argc >= 3)
	{
		if (!std::strcmp(argv[2], "1"))
			return (new GravitySystem(particleCount));
		if (!std::strcmp(argv[2], "2"))
			return (new EmitterSystem(particleCount));
	}
	return (nullptr);
}

int main(int argc, char **argv)
{
	Windows win(1902, 1080, "Particle System");
	win.setClearColor(Color::Black);
	Camera camera;

	std::unique_ptr<ParticleSystem> system;
	system.reset(parseArgs(argc, argv));
	if (!system)
		return (1);

	glfwSetTime(0.f);
	float lastTime = 0.f;

	float dt = 0.f;
	float frameLimit = 1.f / 300.f;
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

		dt += frametime;
		if (dt < frameLimit)
			continue ;

		// Inputs
		if (Keyboard::isKeyPressed(GLFW_KEY_ESCAPE))
			win.close();

		// Update
		system->update(camera, dt);
		camera.update(dt);
		while (dt > frameLimit)
			dt -= frameLimit;

		// Draw
		win.clear();
		system->draw();

		win.display();
		win.pollEvents();
	}
	return (0);
}
