#include "PlasmaRifle.hpp"

#include <iostream>

PlasmaRifle::PlasmaRifle(void) :
	AWeapon("Plasma Rifle", 5, 21)
{

}

PlasmaRifle::PlasmaRifle(PlasmaRifle const & p_PlasmaRifle) :
	AWeapon(p_PlasmaRifle)
{

}

PlasmaRifle::~PlasmaRifle(void)
{

}

PlasmaRifle & PlasmaRifle::operator=(PlasmaRifle const & p_PlasmaRifle)
{
	AWeapon::operator=(p_PlasmaRifle);
	return (*this);
}

void PlasmaRifle::attack(void) const
{
	std::cout << "* piouuu piouuu piouuu *" << std::endl;
}
