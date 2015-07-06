#include "FlowerGun.hpp"
#include "GameManager.hpp"
#include "Bullet.hpp"

FlowerGun::FlowerGun(void) :
	Weapon()
{ /* unused */ }

FlowerGun::FlowerGun(GameEntity * pp_owner) :
	Weapon(50, 0.25f, "Flower Gun", pp_owner)
{
}

FlowerGun::FlowerGun(FlowerGun const & p_flowerGun) :
	Weapon()
{
	*this = p_flowerGun;
}

FlowerGun::~FlowerGun(void)
{

}

FlowerGun & FlowerGun::operator=(FlowerGun const & p_flowerGun)
{
	Weapon::operator=(p_flowerGun);
	return (*this);
}

void FlowerGun::attack(GameManager & p_gameManager)
{
	if (mf_timer >= mf_firerate)
	{
		mf_timer = 0;
		if (mp_owner->getType() == GameEntity::e_Type_Player)
			p_gameManager.addBullet(new Bullet(&p_gameManager, mp_owner->getX() + 4, mp_owner->getY() + 16, this));
		if (mp_owner->getType() == GameEntity::e_Type_Enemy)
			p_gameManager.addBullet(new Bullet(&p_gameManager, mp_owner->getX() + 1, mp_owner->getY() - 1, this));
	}
}
