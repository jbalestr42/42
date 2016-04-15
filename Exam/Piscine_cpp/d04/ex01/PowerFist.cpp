#include "PowerFist.hpp"

#include <iostream>

PowerFist::PowerFist(void) :
	AWeapon("Power Fist", 8, 50)
{

}

PowerFist::PowerFist(PowerFist const & p_PowerFist) :
	AWeapon(p_PowerFist)
{

}

PowerFist::~PowerFist(void)
{

}

PowerFist & PowerFist::operator=(PowerFist const & p_PowerFist)
{
	AWeapon::operator=(p_PowerFist);
	return (*this);
}

void PowerFist::attack(void) const
{
	std::cout << "* pschhh... SBAM! *" << std::endl;
}
