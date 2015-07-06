#ifndef TILEMAP_HPP
# define TILEMAP_HPP

# include <map>
# include "Matrix.hpp"
# include <SFML/Graphics.hpp>

# define TILE_SIZE 16.f
# define HALF_TILE_SIZE TILE_SIZE / 2.f
# define NB_VERTEX WIDTH * HEIGHT * 4

enum ETransitionType
{
	e_transition_left,
	e_transition_right,
	e_transition_up,
	e_transition_down,
	e_transition_alone,
	e_transition_none
};

struct STile
{
	int		mn_tileType;
	float		mf_noiseValue;

	bool		mb_appear;
	ETransitionType	me_transition;
	float		mf_startTransitionX;
	float		mf_startTransitionY;
	float		mf_scaleX;
	float		mf_scaleY;
	sf::Vertex *	mp_upLeft;
	sf::Vertex	m_startTransition[4];
	sf::Vertex	m_endTransition[4];

	STile(void) :
		mn_tileType(0),
		me_transition(e_transition_none),
		mp_upLeft(0),
		mf_startTransitionX(0.f),
		mf_startTransitionY(0.f),
		mf_scaleX(1.f),
		mf_scaleY(1.f)
	{}

	bool isEmpty(void)
	{
		if (mn_tileType < 121)
			return true;
		return false;
	}
};

class TileMap : public sf::Drawable, public sf::Transformable
{
public:
	typedef Matrix<STile>			Map;

	TileMap(unsigned int pn_width, unsigned int pn_height);
	~TileMap(void);

	unsigned int getCount(void) const;
	unsigned int getColumns(void) const;
	unsigned int getRows(void) const;
	STile & get(unsigned int column, unsigned int row);
	STile const & get(unsigned int column, unsigned int row) const;

	void computeMap(float pf_offsetThirdDimension);
	void draw(sf::RenderTarget& render, sf::RenderStates states) const;

private:
	TileMap(void) = delete;
	void setQuad(int x, int y);

	Map					m_tiles;
	std::unique_ptr<sf::Vertex[]>		m_vertices;
	unsigned int				mn_verticesCount;
	unsigned int				mn_tilesCount;
	float					mf_thirdDimension;

};

#endif
