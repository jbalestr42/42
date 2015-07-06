#include "Spawner.hpp"
#include "Enemy.hpp"
#include "Decor.hpp"
#include "Bonus.hpp"
#include "GameManager.hpp"
#include <ncurses.h>
#include <stdlib.h>
#include <time.h>


Spawner::Spawner(void) { /* unused */ }

Spawner::Spawner(GameManager * pp_gameManager) :
	mp_gameManager(pp_gameManager)
{
	srand(time(NULL));
}

Spawner::Spawner(Spawner const & p_spawner)
{
	*this = p_spawner;
}

Spawner::~Spawner(void)
{

}

Spawner & Spawner::operator=(Spawner const & p_spawner)
{
	(void)p_spawner;
	return (*this);
}

void			Spawner::update(float pf_deltatime)
{
	(void)pf_deltatime;
	int			posX;
	int			posY;
	int			randSpawn = rand() % 42;;

	//TODO: Check pop in window
	getmaxyx(stdscr, mn_maxScreenX, mn_maxScreenY);
	posX = rand() % (mn_maxScreenX - 10);
	posY = mn_maxScreenY - 14;
	if (posX < 5)
		posX = 5;

	if (mp_gameManager->getNbEnemy() < MAX_ENEMY && !randSpawn)
		mp_gameManager->addEnemy(new Enemy(mp_gameManager, posX , posY));
	if (mp_gameManager->getNbDecor() < MAX_DECOR && !(randSpawn - 1))
		mp_gameManager->addDecor(new Decor(mp_gameManager, posX , posY));
	if (mp_gameManager->getNbBonus() < MAX_BONUS && !(randSpawn - 5))
		mp_gameManager->addBonus(new Bonus(mp_gameManager, posX , posY));
}
