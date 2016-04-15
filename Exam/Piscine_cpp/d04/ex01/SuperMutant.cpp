#include "SuperMutant.hpp"

#include <iostream>

SuperMutant::SuperMutant(void) :
	Enemy(170, "Super Mutant")
{
	std::cout << "Gaaah. Me want smash heads !" << std::endl;
}

SuperMutant::SuperMutant(SuperMutant const & p_SuperMutant) :
	Enemy(p_SuperMutant)
{
	std::cout << "Gaaah. Me want smash heads !" << std::endl;
}

SuperMutant::~SuperMutant(void)
{
	std::cout << "Aaargh ..." << std::endl;
}

SuperMutant & SuperMutant::operator=(SuperMutant const & p_SuperMutant)
{
	Enemy::operator=(p_SuperMutant);
	return (*this);
}

void SuperMutant::takeDamage(int p_nDamage)
{
	Enemy::takeDamage(p_nDamage - 3);
}
