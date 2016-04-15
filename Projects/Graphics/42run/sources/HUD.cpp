#include "HUD.hpp"
#include "Shader.hpp"

HUD::HUD(void) :
	Transformable(),
	m_mesh(nullptr),
	m_score(0u)
{
	m_mesh.reset(new Mesh("resources/player.obj"));
	m_texture.resize(10);
	for (int i = 0; i < 10; i++)
		m_texture[i].reset(new AnimatedTexture("resources/nyan.png", Vector2(21, 32), 0.25f, 10));
	setScale({0.005f, 0.0075f, 0.25f});
}

HUD::HUD(HUD const & hUD) :
	Transformable(hUD)
{
	*this = hUD;
}

HUD::~HUD(void) { }

HUD & HUD::operator=(HUD const & hUD)
{
	(void)hUD;
	return (*this);
}

void HUD::addScore(std::size_t score)
{
	m_score += score;
}

std::size_t HUD::getScore(void) const
{
	return m_score;
}

void HUD::draw(Shader & shader)
{
	int scoreTmp = m_score;
	int count = 0;
	//std::cout << m_score << std::endl;
	while (scoreTmp > 0)
	{
		int frame = scoreTmp % 10;
		scoreTmp /= 10;
		m_texture[count]->bind(shader);
		m_texture[count]->setCurrentFrame(frame);
		count++;
		if (count > 10)
			std::cout << "PAS ASSEZ D'IMAGE aLLOUEE" << std::endl;
		setPosition({ 0.115f + count * -0.011f, 0.075f, -0.15f});
		shader.setParameter("ModelMatrix", getMatrix());
		m_mesh->draw();
	}
}
