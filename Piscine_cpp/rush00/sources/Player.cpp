#include "Player.hpp"
#include "GameManager.hpp"
#include "Model.hpp"
#include "FlowerGun.hpp"
#include <ncurses.h>
#include <sstream>

// canonical
Player::Player(void) :
	GameEntity()
{
}

Player::Player(GameManager * pp_gameManager, int pn_x, int pn_y) :
	GameEntity(pp_gameManager, pn_x, pn_y, MAX_HP, GameEntity::e_Type_Player),
	mp_weapon(NULL)
{
	std::string t[7 * 10] =
	{
		"      ",
		"    __  ",
		"    | \\           ",
		"   -=[_JF)--._____ ",
		" -===[---,------+' ",
		"   -=[|_/         ",
		"         ",
		"       ",
		"    __  ",
		"    | \\           ",
		"   -=[_JF)--._____ ",
		"  -==[---,-----+-' ",
		"   -=[|_/         ",
		"         ",
		"       ",
		"    __  ",
		"    | \\           ",
		"    -[_JF)--._____ ",
		"   -=[---,----+--' ",
		"    -[|_/         ",
		"         ",
		"       ",
		"    __  ",
		"    | \\           ",
		"   -=[_JF)--._____ ",
		"  -==[---,---+---' ",
		"   -=[|_/         ",
		"         ",
		"      ",
		"    __  ",
		"    | \\           ",
		"   -=[_JF)--._____ ",
		" -===[---,--+----' ",
		"   -=[|_/         ",
		"         ",
		"       ",
		"    __  ",
		"    | \\           ",
		"   -=[_JF)--._____ ",
		"  -==[---,-+-----' ",
		"   -=[|_/         ",
		"         ",
		"       ",
		"    __  ",
		"    | \\           ",
		"    -[_JF)--._____ ",
		"   -=[---,+------' ",
		"    -[|_/         ",
		"         ",
		"       ",
		"    __  ",
		"    | \\           ",
		"   -=[_JF)--._____ ",
		"  -==[--+,-------' ",
		"   -=[|_/         ",
		"         ",
		"       ",
		"    __  ",
		"    | \\           ",
		"    -[_JF)--._____ ",
		"   -=[-+-,-------' ",
		"    -[|_/         ",
		"         ",
		"       ",
		"    __  ",
		"    | \\           ",
		"   -=[_JF)--._____ ",
		"  -==[+--,-------' ",
		"   -=[|_/         ",
		"         ",
	};

	mp_model = new Model(t, 10, 7, this);
	mp_weapon = new FlowerGun(this);
}

Player::Player(Player const & p_player) :
	GameEntity()
{
	*this = p_player;
}

Player::~Player(void)
{
	if (mp_weapon)
		delete mp_weapon;
}

// operator
Player & 		Player::operator=(Player const & p_player)
{
	GameEntity::operator=(p_player);
	mp_weapon = p_player.mp_weapon;
	return (*this);
}

void		Player::update(float pf_deltatime)
{
	int		x;
	int		y;

	getmaxyx(stdscr, x, y);
	(void)x;

	GameEntity::update(pf_deltatime);
	if (mp_weapon)
		mp_weapon->update(pf_deltatime);
	mf_x += mf_speedX * pf_deltatime;
	mf_y += mf_speedY * pf_deltatime;
	mf_x = mf_x <= 0 ? 0 : mf_x;
	mf_y = mf_y <= 0 ? 0 : mf_y;
	mf_x = mf_x >= x - 6 ? x - 6 : mf_x;
	hud();
}

void		Player::collision(GameEntity & p_gameEntity)
{
	if (mp_model->collision(p_gameEntity))
	{
		if (p_gameEntity.getType() == e_Type_Bullet)
		{
			Bullet *bullet = (Bullet *)&p_gameEntity;
			mn_hp -= bullet->getDamage();
			bullet->setHp(0);
		}
	}
}

void		Player::getInput(int pn_input)
{
	if (pn_input == KEY_UP)
		mf_speedX = -50.f;
	else if (pn_input == KEY_DOWN)
		mf_speedX = 50.f;
	else if (pn_input == KEY_LEFT)
		mf_speedY = -50.f;
	else if (pn_input == KEY_RIGHT)
		mf_speedY = 50.f;
	else if (pn_input == KEY_SPACE)
		attack();
}

void			Player::attack(void)
{
	if (mp_weapon)
		mp_weapon->attack(*mp_gameManager);
}

void			Player::setPos(int pn_x, int pn_y)
{
	mvprintw((int)mf_x + 0, (int)mf_y, "                     ");
	mvprintw((int)mf_x + 1, (int)mf_y, "                     ");
	mvprintw((int)mf_x + 2, (int)mf_y, "                     ");
	mvprintw((int)mf_x + 3, (int)mf_y, "                     ");
	mvprintw((int)mf_x + 4, (int)mf_y, "                     ");
	mvprintw((int)mf_x + 5, (int)mf_y, "                     ");
	mvprintw((int)mf_x + 6, (int)mf_y, "                     ");
	mf_x = pn_x;
	mf_y = pn_y;
}

void			Player::resetSpeed(void)
{
	mf_speedX = 0.f;
	mf_speedY = 0.f;
}

void			Player::restoreHp(int pn_value)
{
	mn_hp += pn_value;
	if (mn_hp > MAX_HP)
		mn_hp = MAX_HP;
}

void			Player::takeDamage(int pn_value)
{
	mn_hp -= pn_value;
}

void			Player::hud(void)
{
	int					i = 0;
	int					max;
	int					strSize;
	std::string			buffer;
	std::stringstream	time;
	std::stringstream	score;
	std::stringstream	lastScore;

	buffer = "Hit Points |=|";
	mvprintw(1, 0, buffer.c_str());
	i += buffer.length();
	strSize = buffer.length();
	max = i + 100;
	while (i <= max)
	{
		if (i < mn_hp + strSize + 1)
			mvprintw(1, i, "|");
		else
			mvprintw(1, i, "-");
		i++;
	}
	buffer = "|=)                    Time (=|   ";
	mvprintw(1, i, buffer.c_str());
	i += buffer.length();
	time << (int)mp_gameManager->getGlobalTime();
	mvprintw(1, i, time.str().c_str());
	i += time.str().length();
	buffer = "sec   |=)                    Score (=|   ";
	mvprintw(1, i, buffer.c_str());
	i += buffer.length();
	score << mp_gameManager->getScore();
	mvprintw(1, i, score.str().c_str());
	i += score.str().length();
	buffer = "   |=)";
	mvprintw(1, i, buffer.c_str());
	i += buffer.length();
	buffer = "                    Last Score (=|   ";
	mvprintw(1, i, buffer.c_str());
	i += buffer.length();
	lastScore << mp_gameManager->getLastScore();
	mvprintw(1, i, lastScore.str().c_str());
	i += lastScore.str().length();
	buffer = "   |=)         ";
	mvprintw(1, i, buffer.c_str());
	i += buffer.length();
}


