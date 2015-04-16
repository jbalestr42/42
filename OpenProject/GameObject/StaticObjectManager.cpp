#include "GameObject/StaticObjectManager.hpp"
#include "Main/ResourcesManager.hpp"

StaticObjectManager::StaticObjectManager()
{
	m_objects.push_back(new Tree());
	m_objects.push_back(new Tree());
	m_objects.push_back(new Tree());
	m_objects.push_back(new Star());
	m_objects.push_back(new Sun());
}

StaticObjectManager::~StaticObjectManager(void)
{
	for (int i = 0; i < m_objects.size(); i++)
		delete m_objects[i];
	m_objects.clear();
}

void StaticObjectManager::init(void)
{
	for (int i = 0; i < m_objects.size(); i++)
		m_objects[i]->init();
}

void StaticObjectManager::update(float pf_deltatime)
{
	for (int j = 0; j < m_objects.size(); j++)
	{
		for (int i = 0; i < 68; i++)
		{
			if (!m_tiles->get(m_objects[j]->getOrigin().x, i).isEmpty())
			{
				m_objects[j]->setOriginY(i);
				break;
			}
		}
		m_objects[j]->update(pf_deltatime);
	}
}

void StaticObjectManager::draw(sf::RenderTarget & p_target, sf::RenderStates p_states) const
{
	for (int i = 0; i < m_objects.size(); i++)
	{
		m_objects[i]->draw(p_target, p_states);
	}
}

void StaticObjectManager::setTile(TileMap * p_tiles)
{
	m_tiles = p_tiles;
}

