#ifndef FLOWERGUN_HPP
# define FLOWERGUN_HPP

# include <string>

# include "Weapon.hpp"

class FlowerGun : public Weapon
{
protected:
	FlowerGun(void);
	FlowerGun(FlowerGun const & p_flowerGun);
	FlowerGun &	operator=(FlowerGun const & p_flowerGun);

public:
	FlowerGun(GameEntity * pp_owner);
	virtual ~FlowerGun(void);

	void attack(GameManager & p_gameManager);

};

#endif /* !FLOWERGUN_HPP */
