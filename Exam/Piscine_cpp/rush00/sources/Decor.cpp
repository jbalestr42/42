#include "Decor.hpp"
#include "GameManager.hpp"
#include "Weapon.hpp"
#include "FlowerGun.hpp"
#include <ncurses.h>

// canonical
Decor::Decor(void) :
	GameEntity()
{
}

Decor::Decor(GameManager * pp_gameManager, int pn_x, int pn_y) :
	GameEntity(pp_gameManager, pn_x, pn_y, MAX_HP, GameEntity::e_Type_Decor)
{
	std::string t[MAX_HEIGHT] =
	{
		"              ",
		"     .-'';'-.  ",
		"   ,'   <_,-.`.  ",
		"  /)   ,--,_>\\_\\  ",
		" |'   (      \\_ |  ",
		" |_    `-.    / |   ",
		"  \\`-.   ;  _(`/   ",
		"   `.(    \\/ ,'   ",
		"      `-....-'    ",
		"                ",
	};

	mp_model = new Model(t, this);
}

Decor::Decor(Decor const & p_enemy) :
	GameEntity()
{
	*this = p_enemy;
}

Decor::~Decor(void)
{
	mvprintw(mf_x + 0, mf_y + 1, "                   ");
	mvprintw(mf_x + 1, mf_y + 1, "                   ");
	mvprintw(mf_x + 2, mf_y + 1, "                    ");
	mvprintw(mf_x + 3, mf_y + 1, "                    ");
	mvprintw(mf_x + 4, mf_y + 1, "                     ");
	mvprintw(mf_x + 5, mf_y + 1, "                     ");
	mvprintw(mf_x + 6, mf_y + 1, "                    ");
	mvprintw(mf_x + 7, mf_y + 1, "                   ");
	mvprintw(mf_x + 8, mf_y + 1, "                   ");
}

// operator
Decor & 		Decor::operator=(Decor const & p_enemy)
{
	GameEntity::operator=(p_enemy);
	return (*this);
}

void		Decor::display(void)
{
	if (mn_hp > 0)
		GameEntity::display();
}

void		Decor::update(float pf_deltatime)
{
	int		x;
	int		y;

	GameEntity::update(pf_deltatime);
	mf_y -= 70.f * pf_deltatime;
	getmaxyx(stdscr, x, y);
	(void)x;
	if (mf_y < 0)
	{
		mn_hp = 0;
	}
}

void		Decor::collision(GameEntity & p_gameEntity)
{
	if (mp_model->collision(p_gameEntity))
	{
		if (p_gameEntity.getType() == e_Type_Bullet)
		{
			Bullet *bullet = (Bullet *)&p_gameEntity;
			bullet->setHp(0);
		}
		else if (p_gameEntity.getType() == e_Type_Decor)
		{
			p_gameEntity.setHp(0);
		}
		if (p_gameEntity.getType() == e_Type_Player)
		{
			Player * player = (Player *)&p_gameEntity;
			player->takeDamage(30);
			setHp(0);
		}
	}
}

