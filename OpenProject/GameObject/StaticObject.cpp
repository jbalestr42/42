#include "StaticObject.hpp"
#include "Main/ResourcesManager.hpp"
#include <cmath>

StaticObject::StaticObject() :
	GameObject(),
	me_currentState(e_treeState_sleep),
	m_origin(0.0f, 0.0f),
	m_size(50.0f, 50.0f),
	m_color(sf::Color(0, 0, 0)),
	mf_transitionTimer(0.0f)
{
	srand(time(NULL));
	for (int i = 0; i < 36000; i++)
		mf_cos[i] = cos(i / 100.0f * RADIAN);
}

StaticObject::~StaticObject(void)
{
}

void StaticObject::rotateVec(sf::Vector2f *p_point, float pf_angle, sf::Vector2f p_axis)
{
	float radian = pf_angle * PI / 180.0f;
	sf::Vector2f tmp;

	*p_point = *p_point - p_axis;
	tmp.x = p_point->x * cos(radian) - p_point->y * sin(radian);
	tmp.y = p_point->y * cos(radian) + p_point->x * sin(radian);
	*p_point = tmp + p_axis;
}

float StaticObject::randomRange(int pn_min, int pn_max)
{
	return static_cast<float>(rand() % (pn_max - pn_min) + pn_min);
}

float StaticObject::randomRangeTile(int pn_min, int pn_max)
{
	int tmp = randomRange(pn_min, pn_max);
	tmp -= tmp % 16;
	return static_cast<float>(tmp);
}

void StaticObject::init(void)
{
	GameObject::init();
}

void StaticObject::update(float pf_deltatime)
{
	GameObject::update(pf_deltatime);
	if (mf_nextY > m_origin.y)
		m_origin.y += pf_deltatime * STEP_TRANSITION * (abs(m_origin.y - mf_nextY) / TILE_SIZE);
	else if (mf_nextY <= m_origin.y)
		m_origin.y -= pf_deltatime * STEP_TRANSITION * (abs(m_origin.y - mf_nextY) / TILE_SIZE);
}

void StaticObject::draw(sf::RenderTarget & p_target, sf::RenderStates p_states) const
{
	GameObject::draw(p_target, p_states);
}

void StaticObject::setOriginX(void)
{
	int rand = randomRange(10, 117);
	m_origin.x = rand * TILE_SIZE - m_size.x / 2;
}

void StaticObject::setOriginY(int const pn_y)
{
	mf_nextY = pn_y * TILE_SIZE - m_size.y / 2.0f + TILE_SIZE;
	if (m_origin.y <= 0.0f || m_origin.y >= 128 * TILE_SIZE)
		m_origin.y = pn_y * TILE_SIZE - m_size.y / 2.0f + TILE_SIZE;
}

sf::Vector2f StaticObject::getOrigin(void) const
{
	return sf::Vector2f(m_origin.x / TILE_SIZE, m_origin.y / TILE_SIZE);
}
