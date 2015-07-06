#include "SceneNoise.hpp"
#include "ResourcesManager.hpp"
#include "Octo/OctoNoise.hpp"
#include <string>
#include <iostream>

SceneNoise::SceneNoise(void) :
	ASceneBase()
{
}

SceneNoise::~SceneNoise(void)
{
}

void SceneNoise::init(void)
{
	m_staticManager.setTile(m_mapManager.getTile());
	m_staticManager.init();
}

void SceneNoise::update(float pf_deltatime)
{
	m_mapManager.update(pf_deltatime);
	m_staticManager.setTile(m_mapManager.getTile());
	m_staticManager.update(pf_deltatime);
}

void SceneNoise::draw(sf::RenderTarget &p_target, sf::RenderStates p_states) const
{
	m_staticManager.draw(p_target, p_states);
	p_target.draw(m_mapManager);
}

void SceneNoise::pollEvent(sf::Event p_event)
{
}
