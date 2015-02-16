#include "RadScorpion.hpp"

#include <iostream>

RadScorpion::RadScorpion(void) :
	Enemy(80, "RadScorpion")
{
	std::cout << "* click click click *" << std::endl;
}

RadScorpion::RadScorpion(RadScorpion const & p_RadScorpion) :
	Enemy(p_RadScorpion)
{
	std::cout << "* click click click *" << std::endl;
}

RadScorpion::~RadScorpion(void)
{
	std::cout << "* SPROTCH *" << std::endl;
}

RadScorpion & RadScorpion::operator=(RadScorpion const & p_RadScorpion)
{
	Enemy::operator=(p_RadScorpion);
	return (*this);
}

void RadScorpion::takeDamage(int p_nDamage)
{
	Enemy::takeDamage(p_nDamage - 3);
}

