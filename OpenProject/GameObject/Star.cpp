#include "Star.hpp"
#include "DefineResources.hpp"
#include "Octo/OctoLogger.hpp"
#include "cmath"

Star::Star() :
	StaticObject(),
	mf_timer(0.0f),
	mf_mouvement(0.01f)
{
}

Star::~Star()
{
}

void Star::randomStar(sf::ConvexShape * p_star)
{
	p_star->setPointCount(8);
	m_origin = sf::Vector2f(1000.0f, 500.0f);
	m_sizeHeart = sf::Vector2f(10.0f, 10.0f);
	m_sizeRay = sf::Vector2f(randomRange(MIN_X, MAX_X), randomRange(MIN_Y, MAX_Y));
	p_star->setPoint(0, sf::Vector2f(m_origin.x - m_sizeHeart.x / 2.0f - m_sizeRay.x, m_origin.y));
	p_star->setPoint(1, sf::Vector2f(m_origin.x - m_sizeHeart.x / 2.0f, m_origin.y - m_sizeHeart.y / 2.0f));
	p_star->setPoint(2, sf::Vector2f(m_origin.x, m_origin.y - m_sizeHeart.y / 2.0f - m_sizeRay.y));
	p_star->setPoint(3, sf::Vector2f(m_origin.x + m_sizeHeart.x / 2.0f, m_origin.y - m_sizeHeart.y / 2.0f));
	p_star->setPoint(4, sf::Vector2f(m_origin.x + m_sizeHeart.x / 2.0f + m_sizeRay.x, m_origin.y));
	p_star->setPoint(5, sf::Vector2f(m_origin.x + m_sizeHeart.x / 2.0f, m_origin.y + m_sizeHeart.y / 2.0f));
	p_star->setPoint(6, sf::Vector2f(m_origin.x, m_origin.y + m_sizeHeart.y / 2.0f + m_sizeRay.y));
	p_star->setPoint(7, sf::Vector2f(m_origin.x - m_sizeHeart.x / 2.0f, m_origin.y + m_sizeHeart.y / 2.0f));

	p_star->setOrigin(m_origin);
	p_star->setFillColor(sf::Color(255, 255, 255));
	p_star->setPosition(m_origin);
	//p_star->setOutlineThickness(1);
	//p_star->setOutlineColor(sf::Color(0, 0, 0));

	mf_mouvement = 0.01f;
}

void Star::randomLight(void)
{
	texture.loadFromFile("/Users/fcorbel/Downloads/GradianTransparentWhite.png");
	sprite.setTexture(texture);
	//sprite.setColor(sf::Color(255, 255, 255, 128));
	float radius = m_sizeHeart.x + m_sizeRay.x;
	sprite.setOrigin(sf::Vector2f(m_origin.x - radius, m_origin.y - radius));
	//m_light.setFillColor(sf::Color(255, 255, 255));
	m_light.setTexture(&texture);
	//m_light.setTextureRect(sf::IntRect(m_origin.x, m_origin.y, 100, 100));
	m_light.setRadius(radius);
	m_light.setOrigin(sf::Vector2f(radius, radius));
	m_light.setPosition(m_origin);
}

void Star::init(void)
{
	StaticObject::init();
	//m_color = sf::Color(randomRange(20, 200), randomRange(20, 200), randomRange(20, 200));
	randomStar(&m_starFront);
	randomStar(&m_starBack);
	randomLight();
}

void Star::pollEvent(sf::Event events)
{
}

void Star::update(float pf_deltatime)
{
	StaticObject::update(pf_deltatime);

	mf_timer += pf_deltatime;
	if (mf_timer > 1.0f)
	{
		mf_timer = 0.0f;
		randomStar(&m_starFront);
		randomStar(&m_starBack);
		m_starBack.setRotation(45.0f);
	}
}

void Star::draw(sf::RenderTarget& p_target, sf::RenderStates p_states) const
{
	StaticObject::draw(p_target, p_states);

	//sf::BlendMode blendmode = sf::BlendMultiply;
	//blendmode.colorDstFactor = sf::BlendMode::SrcColor;
	//p_target.draw(m_light, blendmode);
	/*
	p_target.draw(m_light);
	p_target.draw(sprite);
	p_target.draw(m_starFront);
	p_target.draw(m_starBack);
	*/
}

