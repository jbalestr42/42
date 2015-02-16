#include "Bonus.hpp"
#include "GameManager.hpp"
#include "Weapon.hpp"
#include "FlowerGun.hpp"
#include <ncurses.h>

// canonical
Bonus::Bonus(void) :
	GameEntity()
{
}

Bonus::Bonus(GameManager * pp_gameManager, int pn_x, int pn_y) :
	GameEntity(pp_gameManager, pn_x, pn_y, MAX_HP, GameEntity::e_Type_Bonus)
{
	std::string t[MAX_HEIGHT] =
	{
		" ^  ",
		"<->  ",
		" v  ",
		" ^  ",
		"<\\>  ",
		" v  ",
		" ^  ",
		"<|>  ",
		" v  ",
		" ^  ",
		"</>  ",
		" v  ",
	};

	mp_model = new Model(t, 4, 3, this);
}

Bonus::Bonus(Bonus const & p_enemy) :
	GameEntity()
{
	*this = p_enemy;
}

Bonus::~Bonus(void)
{
	mvprintw(mf_x + 0, mf_y + 1, "     ");
	mvprintw(mf_x + 1, mf_y + 1, "     ");
	mvprintw(mf_x + 2, mf_y + 1, "     ");
	mvprintw(mf_x + 1, mf_y, "     ");
}

// operator
Bonus & 		Bonus::operator=(Bonus const & p_enemy)
{
	GameEntity::operator=(p_enemy);
	return (*this);
}

void		Bonus::display(void)
{
	if (mn_hp > 0)
		GameEntity::display();
}

void		Bonus::update(float pf_deltatime)
{
	int		x;
	int		y;

	GameEntity::update(pf_deltatime);
	mf_y -= 20.f * pf_deltatime;
	getmaxyx(stdscr, x, y);
	(void)x;
	if (mf_y < 0)
	{
		mn_hp = 0;
	}
}

void		Bonus::collision(GameEntity & p_gameEntity)
{
	if (mp_model->collision(p_gameEntity))
	{
		if (p_gameEntity.getType() == e_Type_Player)
		{
			Player * player = (Player *)&p_gameEntity;
			player->restoreHp(40);
			setHp(0);
		}
	}
}

