#include "TileMap.hpp"
#include "Octo/OctoNoise.hpp"

TileMap::TileMap(unsigned int pn_width, unsigned int pn_height) :
	mn_verticesCount(0u),
	mn_tilesCount(0u),
	mf_thirdDimension(0.f)
{
	m_tiles.resize(pn_width, pn_height, STile());

	m_vertices.reset(new sf::Vertex[pn_width * pn_height * 4u]);
	for (int x = 0; x < m_tiles.columns(); x++)
	{
		for (int y = 0; y < m_tiles.rows(); y++)
			setQuad(x, y);
	}
}

TileMap::~TileMap(void) {}

void TileMap::setQuad(int x, int y)
{
	m_tiles(x, y).mp_upLeft = &m_vertices[mn_verticesCount];
	float offset = TILE_SIZE / 2.f;

	sf::Vertex ver;
	ver.position = sf::Vector2f(x * TILE_SIZE + offset, y * TILE_SIZE + offset);
	ver.texCoords = sf::Vector2f(0.f, 0.f);
	ver.color = sf::Color(128.f, 0.f, 128.f);
	m_vertices[mn_verticesCount] = ver;
	mn_verticesCount++;

	ver.position = sf::Vector2f(x * TILE_SIZE + offset, y * TILE_SIZE + offset);
	ver.texCoords = sf::Vector2f(TILE_SIZE, 0.f);
	ver.color = sf::Color(128.f, 0.f, 128.f);
	m_vertices[mn_verticesCount] = ver;
	mn_verticesCount++;

	ver.position = sf::Vector2f(x * TILE_SIZE + offset, y * TILE_SIZE + offset);
	ver.texCoords = sf::Vector2f(TILE_SIZE, TILE_SIZE);
	ver.color = sf::Color(128.f, 0.f, 128.f);
	m_vertices[mn_verticesCount] = ver;
	mn_verticesCount++;

	ver.position = sf::Vector2f(x * TILE_SIZE + offset, y * TILE_SIZE + offset);
	ver.texCoords = sf::Vector2f(0.f, TILE_SIZE);
	ver.color = sf::Color(128.f, 0.f, 128.f);
	m_vertices[mn_verticesCount] = ver;
	mn_verticesCount++;
}

void TileMap::computeMap(float pf_offsetThirdDimension)
{
	float vec[3];
	int height;
	float v;
	mn_tilesCount = 0;
	mf_thirdDimension = pf_offsetThirdDimension;
	// Init perlin value
	for (int x = 0; x < m_tiles.columns(); x++)
	{
		vec[0] = static_cast<float>(x) / 100.0;
		vec[1] = mf_thirdDimension / 100.f;
		// fbm return a value b/tween -1 & 1
		// we normalize it betwen 0 & m_tiles.columns
		v = (OctoNoise::getCurrent().fbm(vec) + 1.f) * static_cast<float>(m_tiles.rows()) / 2.f;
		height = static_cast<int>(v);
		for (int y = height; y < m_tiles.rows(); y++)
		{
			vec[0] = static_cast<float>(x) / 70.0;
			vec[1] = static_cast<float>(y) / 10.0;
			vec[2] = mf_thirdDimension / 100.f;
			// Perlin return a value between -1 & 1
			// we normalize it between 0 & 255
			m_tiles(x, y).mf_noiseValue = OctoNoise::getCurrent().noise3(vec);
			m_tiles(x, y).mn_tileType = (m_tiles(x, y).mf_noiseValue + 1.f) * 128.f;
			mn_tilesCount++;
		}
		for (int y = 0; y < height; y++)
			m_tiles(x, y).mn_tileType = 0;
	}
}

void TileMap::draw(sf::RenderTarget& render, sf::RenderStates states) const
{
	//states.transform = getTransform();
	render.draw(m_vertices.get(), mn_verticesCount, sf::Quads, states);
}

unsigned int TileMap::getCount(void) const
{
	return mn_tilesCount;
}

unsigned int TileMap::getColumns(void) const
{
	return m_tiles.columns();
}

unsigned int TileMap::getRows(void) const
{
	return m_tiles.rows();
}

STile & TileMap::get(unsigned int column, unsigned int row)
{
	return m_tiles(column, row);
}

STile const & TileMap::get(unsigned int column, unsigned int row) const
{
	return m_tiles(column, row);
}
