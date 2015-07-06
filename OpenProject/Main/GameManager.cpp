#include <SFML/Graphics.hpp>
#include "GameManager.hpp"
#include "ResourcesManager.hpp"
#include "Options.hpp"
#include "FrameRate.hpp"
#include "Octo/OctoLogger.hpp"

#include "SceneNoise.hpp"

GameManager *GameManager::msp_current = NULL;

/* ---------------------------------------------------------------------- */
/*                                Base                                    */
/* ---------------------------------------------------------------------- */
GameManager::GameManager(void) :
	me_currentScene(EScene::e_scene_noise)
{
}

GameManager::~GameManager(void)
{
	Option::getCurrent()->destroy();
	OctoLogger::log("Destroy GameManager");
	OctoLogger::destroy();
}

/* ---------------------------------------------------------------------- */
/*                              Accessors                                 */
/* ---------------------------------------------------------------------- */
GameManager & GameManager::getCurrent(void)
{
	if (msp_current == NULL)
		msp_current = new GameManager();

	return *msp_current;
}

sf::RenderWindow & GameManager::getWindow(void)
{
	return m_window;
}

/* ---------------------------------------------------------------------- */
/*                              Methods                                   */
/* ---------------------------------------------------------------------- */
void GameManager::init(void)
{
	// Init Logger
	OctoLogger::log("Init GameManager");

	ResourcesManager & data = ResourcesManager::getCurrent();
	data.createMemoryFile("DataConverter/data");

	// Load Option
	Option *options = Option::getCurrent();
	options->load();

	// Create the window of the application
	m_window.create(sf::VideoMode(1900, 1080, 32), "Octodyssey");
	m_window.setVerticalSyncEnabled(options->getOptions()->mb_verticalsync);
	if (options->getOptions()->mb_limitFramerate)
		m_window.setFramerateLimit(options->getOptions()->mn_framerate);

	// Initialize each Scene
	mp_scenes[EScene::e_scene_noise] = new SceneNoise();

	// init all scenes
	for (int i = 0; i < EScene::e_scene_nb; i++)
		mp_scenes[i]->init();
}

void GameManager::destroy(void)
{
	if (msp_current)
		delete msp_current;
	msp_current = NULL;
}

void GameManager::update(float pf_deltatime)
{
	mp_scenes[me_currentScene]->update(pf_deltatime);
}

void GameManager::draw(void)
{
	m_window.draw(*mp_scenes[me_currentScene]);
}

void GameManager::pollEvent(sf::Event p_event)
{
	mp_scenes[me_currentScene]->pollEvent(p_event);
}

void GameManager::run(void)
{
	FrameRate fps;
	sf::Clock clock;
	float fDeltatime = 0.f;

	while (m_window.isOpen())
	{
		// Handle events
		sf::Event event;
		while (m_window.pollEvent(event))
		{
			// Window closed or escape key pressed: exit
			if ((event.type == sf::Event::Closed) || ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)))
			{
				m_window.close();
				break;
			}

			// Poll event for current scene
			pollEvent(event);
			if (event.type == sf::Event::MouseButtonPressed)
			{
				sf::Vector2i MousePos = sf::Mouse::getPosition(m_window) / 50;
			}
		}	

		fDeltatime = clock.restart().asSeconds();
#ifndef NDEBUG
		fps.update(fDeltatime);
#endif

		// Update current scene
		update(fDeltatime);

		// Clear the window
		m_window.clear(sf::Color(200, 200, 200));

		// Draw current scene
		m_window.setView( sf::View( sf::FloatRect(0,0,m_window.getSize().x,m_window.getSize().y) ) );
		draw();
#ifndef NDEBUG
		m_window.draw(fps);
#endif

		// Display things on scene
		m_window.display();
	}
}

