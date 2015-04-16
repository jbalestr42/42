#include "Sun.hpp"
#include "DefineResources.hpp"
#include "Octo/OctoLogger.hpp"
#include "cmath"

Sun::Sun() :
	StaticObject(),
	mf_timer(0.0f),
	mf_mouvement(0.01f)
{
}

Sun::~Sun()
{
}

void Sun::randomSun(sf::ConvexShape * p_sun)
{
	p_sun->setPointCount(12);
	m_origin = sf::Vector2f(1000.0f, 500.0f);
	me_currentState = e_treeState_grow;
	m_sizeHeart = sf::Vector2f(randomRange(MIN_X, MAX_X), randomRange(MIN_Y, MAX_Y));
	m_sizeRay = sf::Vector2f(randomRange(MIN_X, MAX_X), randomRange(MIN_Y, MAX_Y));
	p_sun->setPoint(0, sf::Vector2f(m_origin.x - m_sizeHeart.x - m_sizeRay.x, m_origin.y));
	p_sun->setPoint(1, sf::Vector2f(m_origin.x - m_sizeHeart.x, m_origin.y - m_sizeHeart.y / 2.0f));
	p_sun->setPoint(2, sf::Vector2f(m_origin.x - m_sizeHeart.x / 2.0f, m_origin.y - m_sizeHeart.y));
	p_sun->setPoint(3, sf::Vector2f(m_origin.x, m_origin.y - m_sizeHeart.y - m_sizeRay.y));
	p_sun->setPoint(4, sf::Vector2f(m_origin.x + m_sizeHeart.x / 2.0f, m_origin.y - m_sizeHeart.y));
	p_sun->setPoint(5, sf::Vector2f(m_origin.x + m_sizeHeart.x, m_origin.y - m_sizeHeart.y / 2.0f));
	p_sun->setPoint(6, sf::Vector2f(m_origin.x + m_sizeHeart.x + m_sizeRay.x, m_origin.y));
	p_sun->setPoint(7, sf::Vector2f(m_origin.x + m_sizeHeart.x, m_origin.y + m_sizeHeart.y / 2.0f));
	p_sun->setPoint(8, sf::Vector2f(m_origin.x + m_sizeHeart.x / 2.0f, m_origin.y + m_sizeHeart.y));
	p_sun->setPoint(9, sf::Vector2f(m_origin.x, m_origin.y + m_sizeHeart.y + m_sizeRay.y));
	p_sun->setPoint(10, sf::Vector2f(m_origin.x - m_sizeHeart.x / 2.0f, m_origin.y + m_sizeHeart.y));
	p_sun->setPoint(11, sf::Vector2f(m_origin.x - m_sizeHeart.x, m_origin.y + m_sizeHeart.y / 2.0f));

	p_sun->setOrigin(m_origin);
	p_sun->setFillColor(m_color);
	p_sun->rotate(randomRange(MAX_A, MIN_A));
	p_sun->setPosition(m_origin);

	mf_mouvement = 0.01f;
}

void Sun::init(void)
{
	StaticObject::init();
	m_color = sf::Color(randomRange(20, 200), randomRange(20, 200), randomRange(20, 200));
	randomSun(&m_sunFront);
	randomSun(&m_sunBack);
}

void Sun::pollEvent(sf::Event events)
{
}

void Sun::update(float pf_deltatime)
{
	StaticObject::update(pf_deltatime);

	mf_timer += pf_deltatime;
	if (mf_timer > 1.0f)
	{
		mf_timer = 0.0f;
		randomSun(&m_sunFront);
		randomSun(&m_sunBack);
	}
	/*
	if (me_currentState == e_treeState_grow)
	{
		mf_mouvement += pf_deltatime / 4;
		if (mf_mouvement >= 1.0f)
		{
			mf_timer = 0.0f;
			me_currentState = e_treeState_sleep;
		}
	}
	else if (me_currentState == e_treeState_sleep)
	{
		if (mf_timer > 2.0f)
			mf_mouvement += pf_deltatime / (20 + (mf_timer - 2.0f) * 10);
		else
			mf_mouvement -= pf_deltatime / (20 + mf_timer * 10);
	}
	*/
}

void Sun::draw(sf::RenderTarget& p_target, sf::RenderStates p_states) const
{
	StaticObject::draw(p_target, p_states);

//	p_target.draw(m_sunFront);
//	p_target.draw(m_sunBack);
}

