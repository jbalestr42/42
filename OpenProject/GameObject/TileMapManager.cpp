#include "TileMapManager.hpp"
#include "Main/ResourcesManager.hpp"

TileMapManager::TileMapManager(void) :
	m_tiles(new TileMap(120, 68)),
	m_tilesPrev(new TileMap(120, 68)),
	mf_transitionTimer(1.f),
	mf_thirdDimension(0.f)
{
	m_tilesCount.setFont(ResourcesManager::getCurrent().getFont(FONT_CHUNKFIVE_EX));
	m_tilesCount.setPosition(20.f, 350.f);
}

TileMapManager::~TileMapManager(void)
{
	delete m_tiles;
	delete m_tilesPrev;
}

void TileMapManager::initTransitionFull(TileMap * tiles, int x, int y, bool appear)
{
	sf::Vertex * ver = tiles->get(x, y).mp_upLeft;

	ver[0].position.x = x * TILE_SIZE;
	ver[1].position.x = x * TILE_SIZE + TILE_SIZE;
	ver[2].position.x = x * TILE_SIZE + TILE_SIZE;
	ver[3].position.x = x * TILE_SIZE;
	ver[0].position.y = y * TILE_SIZE;
	ver[1].position.y = y * TILE_SIZE;
	ver[2].position.y = y * TILE_SIZE + TILE_SIZE;
	ver[3].position.y = y * TILE_SIZE + TILE_SIZE;
}

void TileMapManager::initTransitionLeft(TileMap * tiles, int x, int y, bool appear)
{
	sf::Vertex * ver = tiles->get(x, y).mp_upLeft;

	for (int i = 0; i < 2; i++)
	{
		ver[i].position.x = x * TILE_SIZE;
		ver[i + 2].position.x = x * TILE_SIZE;
		ver[i].position.y = y * TILE_SIZE;
		ver[i + 2].position.y = y * TILE_SIZE + TILE_SIZE;
	}
}

void TileMapManager::initTransitionRight(TileMap * tiles, int x, int y, bool appear)
{
	sf::Vertex * ver = tiles->get(x, y).mp_upLeft;

	for (int i = 0; i < 2; i++)
	{
		ver[i].position.x = x * TILE_SIZE + TILE_SIZE;
		ver[i + 2].position.x = x * TILE_SIZE + TILE_SIZE;
		ver[i].position.y = y * TILE_SIZE;
		ver[i + 2].position.y = y * TILE_SIZE + TILE_SIZE;
	}
}

void TileMapManager::initTransitionUp(TileMap * tiles, int x, int y, bool appear)
{
	sf::Vertex * ver = tiles->get(x, y).mp_upLeft;

	for (int i = 0; i < 2; i++)
	{
		ver[i + i * 2].position.x = x * TILE_SIZE;
		ver[i + 1].position.x = x * TILE_SIZE + TILE_SIZE;
		ver[i].position.y = y * TILE_SIZE;
		ver[i + 2].position.y = y * TILE_SIZE;
	}
}

void TileMapManager::initTransitionDown(TileMap * tiles, int x, int y, bool appear)
{
	sf::Vertex * ver = tiles->get(x, y).mp_upLeft;

	for (int i = 0; i < 2; i++)
	{
		ver[i + i * 2].position.x = x * TILE_SIZE;
		ver[i + 1].position.x = x * TILE_SIZE + TILE_SIZE;
		ver[i].position.y = y * TILE_SIZE + TILE_SIZE;
		ver[i + 2].position.y = y * TILE_SIZE + TILE_SIZE;
	}
}

void TileMapManager::initTransitionCentered(TileMap * tiles, int x, int y, bool appear)
{
	sf::Vertex * ver = tiles->get(x, y).mp_upLeft;

	for (int i = 0; i < 4; i++)
	{
		ver[i].position.x = x * TILE_SIZE + HALF_TILE_SIZE;
		ver[i].position.y = y * TILE_SIZE + HALF_TILE_SIZE;
	}
}

void TileMapManager::defineTriangle(bool bounds[4], TileMap * tiles, int x, int y)
{
	bounds[0] = x <= 0 ? true : m_tiles->get(x - 1, y).isEmpty();
	bounds[1] = x >= m_tiles->getColumns() - 1 ? true : m_tiles->get(x + 1, y).isEmpty();
	bounds[2] = y <= 0 ? true : m_tiles->get(x, y - 1).isEmpty();
	bounds[3] = y >= m_tiles->getRows() - 1 ? true : m_tiles->get(x, y + 1).isEmpty();
	if ((bounds[0] && bounds[1]) || (bounds[2] && bounds[3]))
		return;
	tiles->get(x, y).mf_scaleX = 1.0f;
	if (bounds[0]) // x - 1
	{
		if (bounds[2]) // y - 1
			tiles->get(x, y).mp_upLeft[0].position.y = y * TILE_SIZE + TILE_SIZE;
		else if (bounds[3]) // y + 1
			tiles->get(x, y).mp_upLeft[3].position.y = y * TILE_SIZE;
	}
	else if (bounds[1]) // x + 1
	{
		if (bounds[2]) // y - 1
			tiles->get(x, y).mp_upLeft[1].position.y = y * TILE_SIZE + TILE_SIZE;
		else if (bounds[3]) // y + 1
			tiles->get(x, y).mp_upLeft[2].position.y = y * TILE_SIZE;
	}
}

void TileMapManager::defineAppearTransitionType(int x, int y, bool appear)
{
	bool bounds[4];
	bounds[0] = x <= 0 ? true : m_tilesPrev->get(x - 1, y).isEmpty();
	bounds[1] = x >= m_tilesPrev->getColumns() - 1 ? true : m_tilesPrev->get(x + 1, y).isEmpty();
	bounds[2] = y <= 0 ? true : m_tilesPrev->get(x, y - 1).isEmpty();
	bounds[3] = y >= m_tilesPrev->getRows() - 1 ? true : m_tilesPrev->get(x, y + 1).isEmpty();

	m_tilesPrev->get(x, y).mf_scaleX = 1.0f;
	if (bounds[0] && bounds[1] && bounds[2] && bounds[3])
	{
		initTransitionCentered(m_tilesPrev, x, y, true);
		m_tilesPrev->get(x, y).mf_scaleX = 0.5f;
	}
	else if (!bounds[3])
		initTransitionDown(m_tilesPrev, x, y, appear);
	else if (!bounds[2])
		initTransitionUp(m_tilesPrev, x, y, appear);
	else if (!bounds[1])
		initTransitionRight(m_tilesPrev, x, y, appear);
	else if (!bounds[0])
		initTransitionLeft(m_tilesPrev, x, y, appear);
	else
	{
		initTransitionCentered(m_tilesPrev, x, y, true);
		m_tilesPrev->get(x, y).mf_scaleX = 0.5f;
	}
	initTransitionFull(m_tiles, x, y, true);
	defineTriangle(bounds, m_tiles, x, y);
}

void TileMapManager::defineDisappearTransitionType(int x, int y, bool appear)
{
	int bounds[4];
	bounds[0] = x <= 0 ? true : m_tiles->get(x - 1, y).isEmpty();
	bounds[1] = x >= m_tiles->getColumns() - 1 ? true : m_tiles->get(x + 1, y).isEmpty();
	bounds[2] = y <= 0 ? true : m_tiles->get(x, y - 1).isEmpty();
	bounds[3] = y >= m_tiles->getRows() - 1 ? true : m_tiles->get(x, y + 1).isEmpty();

	m_tilesPrev->get(x, y).mf_scaleX = 1.0f;
	if (!bounds[0] && !bounds[1] && !bounds[2] && !bounds[3])
	{
		initTransitionCentered(m_tiles, x, y, false);
		m_tilesPrev->get(x, y).mf_scaleX = 0.5f;
	}
	else if (!bounds[3])
		initTransitionDown(m_tiles, x, y, appear);
	else if (!bounds[2])
		initTransitionUp(m_tiles, x, y, appear);
	else if (!bounds[1])
		initTransitionRight(m_tiles, x, y, appear);
	else if (!bounds[0])
		initTransitionLeft(m_tiles, x, y, appear);
	else
	{
		initTransitionCentered(m_tiles, x, y, false);
		m_tilesPrev->get(x, y).mf_scaleX = 0.5f;
	}
}

void TileMapManager::defineTransition(int x, int y)
{
	int prev = m_tilesPrev->get(x, y).isEmpty();
	int current = m_tiles->get(x, y).isEmpty();

	m_tilesPrev->get(x, y).me_transition = e_transition_alone;
	if (prev && !current) // appear
	{
		defineAppearTransitionType(x, y, true);
	}
	else if (!prev && current) // disappear
	{
		defineDisappearTransitionType(x, y, false);
	}
	else if (current && prev) // no tile
	{
		initTransitionCentered(m_tilesPrev, x, y, false);
		initTransitionCentered(m_tiles, x, y, false);
		m_tilesPrev->get(x, y).me_transition = e_transition_none;
	}
	else if (!current && !prev) // already a tile
	{
	bool bounds[4];
		//initTransitionFull(m_tilesPrev, x, y, true);
		initTransitionFull(m_tiles, x, y, true);
		defineTriangle(bounds, m_tiles, x, y);
		m_tilesPrev->get(x, y).me_transition = e_transition_alone;
	}
}

void TileMapManager::defineTransition(void)
{
	// For each tile, define the type and transition type
	for (int x = 0; x < m_tiles->getColumns(); x++)
	{
		for (int y = 0; y < m_tiles->getRows(); y++)
			defineTransition(x, y);
	}
	m_tilesCount.setString(std::to_string(m_tiles->getCount()));
}

void TileMapManager::interpolate(sf::Vertex & tile, sf::Vertex & tilePrev, float transition)
{
	if (tilePrev.position.x < tile.position.x)
		tilePrev.position.x += transition;
	else if (tilePrev.position.x > tile.position.x)
		tilePrev.position.x -= transition;
	if (tilePrev.position.y < tile.position.y)
		tilePrev.position.y += transition;
	else if (tilePrev.position.y > tile.position.y)
		tilePrev.position.y -= transition;
}

void TileMapManager::updateTransition(float pf_deltatime)
{
	float transition;
	if (mf_transitionTimer > TRANSITION_TIME)
	{
		pf_deltatime = mf_transitionTimer - TRANSITION_TIME;
		mf_transitionTimer = TRANSITION_TIME;
	}
	for (int x = 0; x < m_tiles->getColumns(); x++)
	{
		for (int y = 0; y < m_tiles->getRows(); y++)
		{
			if (m_tilesPrev->get(x, y).me_transition == e_transition_none)
				continue;
			transition = pf_deltatime * STEP_TRANSITION * m_tilesPrev->get(x, y).mf_scaleX;
			for (int i = 0; i < 4; i++)
				interpolate(m_tiles->get(x, y).mp_upLeft[i], m_tilesPrev->get(x, y).mp_upLeft[i], transition);
		}
	}
}

void TileMapManager::update(float pf_deltatime)
{
	bool compute = false;
	mf_transitionTimer += pf_deltatime;
	updateTransition(pf_deltatime);
	if (mf_transitionTimer >= TRANSITION_TIME)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
		{
			compute = true;
			mf_thirdDimension += 1.0f;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
		{
			compute = true;
			mf_thirdDimension -= 1.0f;
		}
		if (!compute)
			return;
		mf_transitionTimer = 0.f;
		TileMap *tmp = m_tilesPrev;
		m_tilesPrev = m_tiles;
		m_tiles = tmp;
		m_tiles->computeMap(mf_thirdDimension);
		defineTransition();
	}
}

void TileMapManager::draw(sf::RenderTarget& render, sf::RenderStates states) const
{
	render.draw(*m_tilesPrev);
	render.draw(m_tilesCount);
}

TileMap * TileMapManager::getTile(void) const
{
	return m_tiles;
}
