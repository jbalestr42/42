#include "Enemy.hpp"
#include "GameManager.hpp"
#include "Weapon.hpp"
#include "FlowerGun.hpp"
#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

// canonical
Enemy::Enemy(void) :
	GameEntity(),
	mp_weapon(NULL)
{
}

Enemy::Enemy(GameManager * pp_gameManager, int pn_x, int pn_y) :
	GameEntity(pp_gameManager, pn_x, pn_y, MAX_HP, GameEntity::e_Type_Enemy)
{
	srand(time(NULL));
	std::string t[MAX_HEIGHT] =
	{
		"           ",
		"        0o  ",
		"  .__--/||}_   ",
		"=/_--------_]=  ",
		"               ",
		"           ",
		"        oO  ",
		"  .__--/||}_   ",
		"=/_--------_]=  ",
		"               ",
		"           ",
		"        Oo  ",
		"  .__--/||}_   ",
		"=/_--------_]-  ",
		"               "
	};

	mp_model = new Model(t, 3, 5, this);
	mp_weapon = new FlowerGun(this);
}

Enemy::Enemy(Enemy const & p_enemy) :
	GameEntity()
{
	*this = p_enemy;
}

Enemy::~Enemy(void)
{
	mvprintw(mf_x + 1, mf_y + 1, "            ");
	mvprintw(mf_x + 2, mf_y + 1, "               ");
	mvprintw(mf_x + 3, mf_y + 1, "                ");
	mvprintw(mf_x + 3, mf_y, " ");
	if (mp_weapon)
		delete mp_weapon;
}

// operator
Enemy & 		Enemy::operator=(Enemy const & p_enemy)
{
	GameEntity::operator=(p_enemy);
	mp_weapon = p_enemy.mp_weapon;
	return (*this);
}

void		Enemy::display(void)
{
	if (mn_hp > 0)
		GameEntity::display();
}

void		Enemy::update(float pf_deltatime)
{
	int		x;
	int		y;
	int		randFire = rand() % 208;


	GameEntity::update(pf_deltatime);
	if (mp_weapon)
		mp_weapon->update(pf_deltatime);
	if (!randFire)
		attack();
	mf_y -= 40.f * pf_deltatime;
	getmaxyx(stdscr, x, y);
	(void)x;
	if (mf_y < 0)
	{
		mp_gameManager->addScore(-20);
		mn_hp = 0;
	}
}

void		Enemy::collision(GameEntity & p_gameEntity)
{
	if (mp_model->collision(p_gameEntity))
	{
		if (p_gameEntity.getType() == e_Type_Bullet)
		{
			Bullet *bullet = (Bullet *)&p_gameEntity;
			mn_hp -= bullet->getDamage();
			bullet->setHp(0);
			if (bullet->getSpeed() > 0)
				mp_gameManager->addScore(100);
		}
		else if (p_gameEntity.getType() == e_Type_Enemy)
		{
			p_gameEntity.setHp(0);
			setHp(0);
		}
		if (p_gameEntity.getType() == e_Type_Player)
		{
			Player * player = (Player *)&p_gameEntity;
			player->takeDamage(30);
			setHp(0);
		}
	}
}

void			Enemy::attack(void)
{
	if (mp_weapon)
		mp_weapon->attack(*mp_gameManager);
}

