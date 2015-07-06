#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string p_Name, Weapon &p_Weapon)
{
	m_Name = p_Name;
	m_Weapon = &p_Weapon;
}

HumanA::~HumanA(void)
{
}

void HumanA::setWeapon(Weapon &p_Weapon)
{
	this->m_Weapon = &p_Weapon;
}

void HumanA::attack(void) const
{
	std::cout << this->m_Name << " attacks with his " << this->m_Weapon->getType() << std::endl;
}
