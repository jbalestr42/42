#include "Player.hpp"
#include "Shader.hpp"
#include "Keyboard.hpp"

Player::Player(void) :
	Transformable(),
	m_mesh(nullptr),
	m_texture(nullptr),
	m_speed(1.f),
	m_speedMax(5.f),
	m_jumpTimerMax(0.75f),
	m_jumpFactor(1.8f),
	m_state(Walk)
{
	m_mesh.reset(new Mesh("resources/player.obj"));
	m_texture.reset(new AnimatedTexture("resources/cat.png", Vector2(32, 64), 0.25f, 9));
	rotateY(180.f);
	translate({0.f, -0.75f, -2.f});
	setScale({0.25f, 0.25f, 0.25f});
}

Player::Player(Player const & player) :
	Transformable(player)
{
	*this = player;
}

Player::~Player(void) { }

Player & Player::operator=(Player const & player)
{
	(void)player;
	return (*this);
}

void Player::setSpeedFactor(float speedFactor)
{
	m_speed = speedFactor;
	if (m_speed > m_speedMax)
		m_speed = m_speedMax;
}

void Player::update(float frametime)
{
	float frameSpeed = frametime * m_speed;
	m_texture->update(frametime);

	if (Keyboard::isKeyPress(GLFW_KEY_LEFT))
	{
		if (getPosition().x > -0.75f)
			translate({ -frameSpeed, 0.f, 0.f});
	}
	else if (Keyboard::isKeyPress(GLFW_KEY_RIGHT))
	{
		if (getPosition().x < 0.75f)
			translate({ frameSpeed, 0.f, 0.f});
	}
	switch (m_state)
	{
		case Walk:
			if (Keyboard::isKeyPress(GLFW_KEY_SPACE))
			{
				m_state = Jump;
			}
			break;
		case Jump:
			if (Keyboard::isKeyPress(GLFW_KEY_SPACE))
			{
				translate({0.f, frameSpeed * m_jumpFactor, 0.f});
				if (getPosition().y > m_jumpTimerMax)
					m_state = Fall;
			}
			else
				m_state = Fall;
			break;
		case Fall:
			translate({0.f, -frameSpeed * m_jumpFactor, 0.f});
			if (getPosition().y <= -0.75f)
				m_state = Walk;
			break;
	}
}

void Player::draw(Shader & shader)
{
	m_texture->bind(shader);
	shader.setParameter("ModelMatrix", getMatrix());
	m_mesh->draw();
}
