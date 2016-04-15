#include "Windows.hpp"
#include "Mesh.hpp"
#include "Shader.hpp"
#include "Keyboard.hpp"
#include "Texture.hpp"
#include "RoomManager.hpp"
#include "Player.hpp"
#include "HUD.hpp"
#include <iostream>

int main(void)
{
	Windows win(800, 600, "42run");
	win.setClearColor(Color::White);

	Shader shader("resources/default.frag" ,"resources/default.vert");
	Shader shaderTexture("resources/animated_texture.frag" ,"resources/animated_texture.vert");
	Matrix m_view;
	Matrix m_projection;
	m_view.translate(Vector3(0.f, 0.f, 0.0f));
	shader.setParameter("ViewMatrix", m_view);
	shaderTexture.setParameter("ViewMatrix", m_view);
	m_projection.perspectiveProjection(60.f, 800.f / 600.f, 0.1f, 100.f);
	shader.setParameter("ProjectionMatrix", m_projection);
	shaderTexture.setParameter("ProjectionMatrix", m_projection);

	HUD hud;
	Player player;
	RoomManager rooms;

	glfwSetTime(0.f);
	float lastTime = 0.f;
	while (win.isOpen())
	{
		// Compute frametime
		float currentTime = glfwGetTime();
		float frametime = (currentTime - lastTime);
		lastTime = currentTime;

		// Inputs
		if (Keyboard::isKeyPressed(GLFW_KEY_ESCAPE))
			win.close();

		// Update
		player.update(frametime);
		rooms.update(player, frametime);
		hud.addScore(rooms.getSpeedFactor());

		// Draw
		win.clear();
		if (glGetError()) // TODO remove
			std::cout << "error" << std::endl;

		rooms.draw(shader);
		player.draw(shaderTexture);
		hud.draw(shaderTexture);

		win.display();
		win.pollEvents();
	}
	return (0);
}
