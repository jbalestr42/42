#ifndef STATICOBJECTMANAGER_HPP
# define STATICOBJECTMANAGER_HPP

# include <SFML/Graphics.hpp>
# include "GameObject/TileMap.hpp"
# include "GameObject/StaticObject.hpp"
# include "GameObject/Tree.hpp"
# include "GameObject/Sun.hpp"
# include "GameObject/Star.hpp"

class StaticObjectManager : public sf::Drawable
{
private:
	TileMap						* m_tiles;
	std::vector<StaticObject *>	m_objects;

public:
	StaticObjectManager();
	virtual ~StaticObjectManager(void);

	virtual void init(void);

	virtual void update(float pf_deltatime);
	virtual void draw(sf::RenderTarget & p_target, sf::RenderStates p_states) const;

	void	setTile(TileMap * p_tiles);
};

#endif
