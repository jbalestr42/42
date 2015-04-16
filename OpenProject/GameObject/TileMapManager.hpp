#ifndef TILEMAPMANAGER_HPP
# define TILEMAPMANAGER_HPP

# include "GameObject/TileMap.hpp"

# define TRANSITION_TIME 0.4f
# define STEP_TRANSITION TILE_SIZE / TRANSITION_TIME

class TileMapManager : public sf::Drawable
{
public:
	TileMapManager(void);
	virtual ~TileMapManager(void);

	// Transition
	void defineTransition(void);
	void defineTransition(int x, int y);
	void defineTriangle(bool bounds[4], TileMap * tiles, int x, int y);
	void defineDisappearTransitionType(int x, int y, bool appear);
	void defineAppearTransitionType(int x, int y, bool appear);
	void initTransitionLeft(TileMap * tiles, int x, int y, bool appear);
	void initTransitionRight(TileMap * tiles, int x, int y, bool appear);
	void initTransitionUp(TileMap * tiles, int x, int y, bool appear);
	void initTransitionDown(TileMap * tiles, int x, int y, bool appear);
	void initTransitionFull(TileMap * tiles, int x, int y, bool appear);
	void initTransitionCentered(TileMap * tiles, int x, int y, bool appear);
	void interpolate(sf::Vertex & tile, sf::Vertex & tilePrev, float transition);

	void update(float pf_deltatime);
	void updateTransition(float pf_deltatime);
	void draw(sf::RenderTarget& render, sf::RenderStates states) const;

	TileMap * getTile(void) const;

private:
	TileMap		*m_tiles;
	TileMap		*m_tilesPrev;
	float		mf_transitionTimer;
	float		mf_thirdDimension;
	sf::Text	m_tilesCount;

};

#endif
