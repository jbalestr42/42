#ifndef SCENENOISE_HPP
# define SCENENOISE_HPP

# include "SceneBase.hpp"
# include "Sprite.hpp"
# include "GameObject/TileMapManager.hpp"
# include "GameObject/StaticObjectManager.hpp"

class SceneNoise : public ASceneBase
{
private:
	TileMapManager		m_mapManager;
	StaticObjectManager	m_staticManager;

protected:
	virtual void draw(sf::RenderTarget &p_target, sf::RenderStates p_states) const;

public:
	SceneNoise(void);
	virtual ~SceneNoise(void);

	virtual void init(void);
	virtual void update(float pf_Deltatime);
	virtual void pollEvent(sf::Event p_event);
};

#endif
