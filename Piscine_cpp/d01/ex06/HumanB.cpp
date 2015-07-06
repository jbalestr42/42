#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string p_Name)
{
	m_Name = p_Name;
	m_Weapon = NULL;
}

HumanB::~HumanB(void)
{
}

void HumanB::setWeapon(Weapon &p_Weapon)
{
	this->m_Weapon = &p_Weapon;
}

void HumanB::attack(void) const
{
	std::cout << this->m_Name << " attacks with his " << this->m_Weapon->getType() << std::endl;
}
