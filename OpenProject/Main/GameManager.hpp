#ifndef GAMEMANAGER_HPP
# define GAMEMANAGER_HPP

# include "SceneBase.hpp"

class GameManager
{
private:
	// Window managment
	sf::RenderWindow	m_window;

	// Scene management
	ASceneBase *		mp_scenes[EScene::e_scene_nb];
	EScene				me_currentScene;

	virtual void update(float p_fDeltatime);
	virtual void pollEvent(sf::Event p_event);
	virtual void draw(void);

	static GameManager *msp_current;

public:
	GameManager(void);
	virtual ~GameManager(void);

	static GameManager & getCurrent(void);
	sf::RenderWindow & getWindow(void);

	void destroy(void);
	void init(void);
	void run(void);

};

#endif
