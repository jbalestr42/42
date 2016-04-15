#include "GameManager.hpp"
#include "ncurses.h"
#include <time.h>

GameManager::GameManager(void) :
	mp_player(NULL),
	mp_spawner(NULL),
	mb_exit(false),
	mn_nbBullet(0),
	mf_globalTime(clock()),
	mn_score(0),
	mn_lastScore(0)
{
	mp_player = new Player(this, 10, 10);

	for (int i = 0; i < MAX_ENEMY; i++)
		mp_enemies[i] = 0;

	for (int i = 0; i < MAX_BULLET; i++)
		mp_bullets[i] = 0;

	mp_spawner = new Spawner(this);
}

GameManager::GameManager(GameManager const & p_gameManager)
{
	*this = p_gameManager;
}

GameManager::~GameManager(void)
{
	if (mp_player)
		delete mp_player;
	if (mp_spawner)
		delete mp_spawner;
	reset();
}

void GameManager::reset(void)
{
	for (int i = 0; i < mn_nbEnemy; i++)
	{
		if (mp_enemies[i])
		{
			delete mp_enemies[i];
			mp_enemies[i] = NULL;
		}
	}
	for (int i = 0; i < mn_nbBullet; i++)
	{
		if (mp_bullets[i])
		{
			delete mp_bullets[i];
			mp_bullets[i] = NULL;
		}
	}
	for (int i = 0; i < mn_nbDecor; i++)
	{
		if (mp_decors[i])
		{
			delete mp_decors[i];
			mp_decors[i] = NULL;
		}
	}
	for (int i = 0; i < mn_nbBonus; i++)
	{
		if (mp_bonus[i])
		{
			delete mp_bonus[i];
			mp_bonus[i] = NULL;
		}
	}
	mn_lastScore = mn_score;
	mn_score = 0;
	mn_nbBullet = 0;
	mn_nbEnemy = 0;
	mn_nbDecor = 0;
	mn_nbBonus = 0;
	mp_player->setHp(MAX_HP);
	mp_player->setPos(10, 10);
}

GameManager & GameManager::operator=(GameManager const & p_gameManager)
{
	(void)p_gameManager;
	return (*this);
}

void GameManager::getInput(void)
{
	int nInput;

	if ((nInput = getch()) == ERR)
	{	}
	else
	{
		if (nInput == KEY_ESCAPE)
			mb_exit = true;
		mp_player->getInput(nInput);
	}
}

void GameManager::update(float pf_deltatime)
{
	if (mp_player->isDead())
		reset();

	// Update player
	mp_player->update(pf_deltatime);
	// Update spawner
	mp_spawner->update(pf_deltatime);

	// Update all enemies and bullets
	for (int i = 0; i < mn_nbEnemy; i++)
		mp_enemies[i]->update(pf_deltatime);
	for (int i = 0; i < mn_nbBullet; i++)
		mp_bullets[i]->update(pf_deltatime);
	for (int i = 0; i < mn_nbDecor; i++)
		mp_decors[i]->update(pf_deltatime);
	for (int i = 0; i < mn_nbBonus; i++)
		mp_bonus[i]->update(pf_deltatime);

	// Check bonus
	for (int i = 0; i < mn_nbBonus; i++)
		mp_bonus[i]->collision(*mp_player);

	// Check decor
	for (int i = 0; i < mn_nbDecor; i++)
	{
		mp_decors[i]->collision(*mp_player);
		for (int j = 0; j < mn_nbEnemy; j++)
			mp_decors[i]->collision(*mp_enemies[j]);
		for (int j = 0; j < mn_nbBullet; j++)
			mp_decors[i]->collision(*mp_bullets[j]);
	}

	// Check enemies
	for (int i = 0; i < mn_nbEnemy; i++)
	{
		// Check enemies with bullets
		for (int j = 0; j < mn_nbBullet; j++)
			mp_enemies[i]->collision(*mp_bullets[j]);
		// Check enemy with other enemy
		for (int j = 0; j < mn_nbEnemy; j++)
		{
			if (mp_enemies[i] != mp_enemies[j])
				mp_enemies[i]->collision(*mp_enemies[j]);
		}
		// Check with player
		mp_enemies[i]->collision(*mp_player);
	}

	// Check bullets
	for (int i = 0; i < mn_nbBullet; i++)
	{
		// Check bullets with player
		mp_player->collision(*mp_bullets[i]);
		// Check bullets with other bullets
		for (int k = 0; k < mn_nbBullet; k++)
		{
			if (mp_bullets[i] != mp_bullets[k])
				mp_bullets[i]->collision(*mp_bullets[k]);
		}
	}

	// Delete dead decor
	for (int i = 0; i < mn_nbDecor; i++)
	{
		if (mp_decors[i]->isDead())
		{
			while (mn_nbDecor > 0 && mn_nbDecor <= MAX_DECOR && mp_decors[mn_nbDecor - 1] == NULL)
				mn_nbDecor--;
			delete mp_decors[i];
			mn_nbDecor--;
			mp_decors[i] = mp_decors[mn_nbDecor];
			mp_decors[mn_nbDecor] = NULL;
		}
	}

	// Delete dead enemies
	for (int i = 0; i < mn_nbEnemy; i++)
	{
		if (mp_enemies[i]->isDead())
		{
			while (mn_nbEnemy > 0 && mn_nbEnemy <= MAX_ENEMY && mp_enemies[mn_nbEnemy - 1] == NULL)
				mn_nbEnemy--;
			delete mp_enemies[i];
			mn_nbEnemy--;
			mp_enemies[i] = mp_enemies[mn_nbEnemy];
			mp_enemies[mn_nbEnemy] = NULL;
		}
	}

	// Delete dead bullets
	for (int i = 0; i < mn_nbBullet; i++)
	{
		if (mp_bullets[i]->isDead())
		{
			while (mn_nbBullet > 0 && mn_nbBullet <= MAX_BULLET && mp_bullets[mn_nbBullet - 1] == NULL)
				mn_nbBullet--;
			delete mp_bullets[i];
			mn_nbBullet--;
			mp_bullets[i] = mp_bullets[mn_nbBullet];
			mp_bullets[mn_nbBullet] = NULL;
		}
	}

	// Delete dead bonus
	for (int i = 0; i < mn_nbBonus; i++)
	{
		if (mp_bonus[i]->isDead())
		{
			while (mn_nbBonus > 0 && mn_nbBonus <= MAX_BONUS && mp_bonus[mn_nbBonus - 1] == NULL)
				mn_nbBonus--;
			delete mp_bonus[i];
			mn_nbBonus--;
			mp_bonus[i] = mp_bonus[mn_nbBonus];
			mp_bonus[mn_nbBonus] = NULL;
		}
	}
}

void GameManager::display(void)
{
	mp_player->display();
	for (int i = 0; i < mn_nbEnemy; i++)
		mp_enemies[i]->display();
	for (int i = 0; i < mn_nbBullet; i++)
		mp_bullets[i]->display();
	for (int i = 0; i < mn_nbDecor; i++)
		mp_decors[i]->display();
	for (int i = 0; i < mn_nbBonus; i++)
		mp_bonus[i]->display();
	// display all entity
	// mvprintw(x, y, str);
	refresh();			// Print it on to the real screen
}

void GameManager::runGame(void)
{
	float	fFrametime = 1.f / 60.f;

	// Init ncurses
	initscr();				// Start curses mode
	noecho();				// Don't echo() while we do getch
	nodelay(stdscr, 1);		// Don't wait for user input
	curs_set(false);		// Disable cursor
	keypad(stdscr, true);	// Enable arrow and specials keys
	int frame = 0;

	while (!mb_exit)
	{
		clock_t fBeforeFrame = clock();
		getInput();
		update(fFrametime);
		display();
		mp_player->resetSpeed();
		frame++;
		while (1)
		{
			float elapsedTime = (clock() - fBeforeFrame) / (float)CLOCKS_PER_SEC;
			if (elapsedTime > fFrametime)
				break;
		}
	}
	endwin();			// End curses mode
}

void GameManager::addBullet(Bullet *pp_bullet)
{
	if (mn_nbBullet < MAX_BULLET)
		mp_bullets[mn_nbBullet++] = pp_bullet;
}

void GameManager::addEnemy(Enemy *pp_enemy)
{
	if (mn_nbEnemy < MAX_ENEMY)
		mp_enemies[mn_nbEnemy++] = pp_enemy;
}

void GameManager::addDecor(Decor *pp_decor)
{
	if (mn_nbDecor < MAX_DECOR)
		mp_decors[mn_nbDecor++] = pp_decor;
}

void GameManager::addBonus(Bonus *pp_bonus)
{
	if (mn_nbBonus < MAX_BONUS)
		mp_bonus[mn_nbBonus++] = pp_bonus;
}

int GameManager::getNbDecor(void) const
{
	return (mn_nbDecor);
}

int GameManager::getNbEnemy(void) const
{
	return (mn_nbEnemy);
}

int GameManager::getNbBonus(void) const
{
	return (mn_nbBonus);
}

float GameManager::getGlobalTime(void)
{
	return ((clock() - mf_globalTime) / (float)CLOCKS_PER_SEC);
}

int GameManager::getScore(void) const
{
	return (mn_score);
}

int GameManager::getLastScore(void) const
{
	return (mn_lastScore);
}

void GameManager::addScore(int pn_score)
{
	mn_score += pn_score;
}
