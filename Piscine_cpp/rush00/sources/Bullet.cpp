#include "Bullet.hpp"
#include "GameManager.hpp"
#include "Weapon.hpp"
#include <ncurses.h>

// canonical
Bullet::Bullet(void) :
	GameEntity(),
	mf_speed(0.f),
	mn_damage(0)
{
}

Bullet::Bullet(GameManager * pp_gameManager, int pn_x, int pn_y, Weapon * pp_weapon) :
	GameEntity(pp_gameManager, pn_x, pn_y, MAX_HP, GameEntity::e_Type_Bullet),
	mf_speed(0.f),
	mn_damage(0)
{

	if (pp_weapon->getOwner()->getType() == e_Type_Player)
	{
		std::string t[MAX_HEIGHT] =
		{
			"  -@  "
		};
		mf_speed = 50.f;
		mp_model = new Model(t, this);
	}
	else if (pp_weapon->getOwner()->getType() == e_Type_Enemy)
	{
		mf_speed = -50.f;
		std::string t[MAX_HEIGHT] =
		{
			"  (+  "
		};
		mf_speed = -50.f;
		mp_model = new Model(t, this);
	}

	mn_damage = pp_weapon->getDamage();
}

Bullet::Bullet(Bullet const & p_bullet) :
	GameEntity()
{
	*this = p_bullet;
}

Bullet::~Bullet(void)
{
	mvprintw(mf_x, mf_y, "     ");
}

// operator
Bullet & 		Bullet::operator=(Bullet const & p_bullet)
{
	GameEntity::operator=(p_bullet);
	return (*this);
}

void		Bullet::display(void)
{
	if (mn_hp > 0)
		GameEntity::display();
}

void		Bullet::update(float pf_deltatime)
{
	int		x;
	int		y;

	mf_y += mf_speed * pf_deltatime;
	getmaxyx(stdscr, x, y);
	(void)x;
	if (mf_y > y - 3 || mf_y < 0)
	{
		mn_hp = 0;
	}
}

int			Bullet::getDamage(void) const
{
	return (mn_damage);
}

float		Bullet::getSpeed(void) const
{
	return (mf_speed);
}

void		Bullet::collision(GameEntity & p_gameEntity)
{
	if (mp_model->collision(p_gameEntity))
	{
		if (p_gameEntity.getType() == e_Type_Bullet)
		{
			setHp(0);
			p_gameEntity.setHp(0);
		}
	}
}
