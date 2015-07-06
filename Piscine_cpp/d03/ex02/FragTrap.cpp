#include "FragTrap.hpp"

#include <iostream>
#include <stdlib.h>
#include <time.h>

FragTrap::FragTrap(void) :
	ClapTrap()
{
	std::cout << "Constructor: A new FragTrap(" << this->m_Name << ") is born !" << std::endl;
}

FragTrap::FragTrap(std::string p_Name) :
	ClapTrap(p_Name, 100, 100, 100, 100, 30, 20, 5)
{
	std::cout << "Constructor: A new FragTrap(" << this->m_Name << ") is born !" << std::endl;
}

FragTrap::FragTrap(FragTrap const & p_FragTrap) :
	ClapTrap(p_FragTrap)
{
	std::cout << "Constructor copy: A new FragTrap(" << this->m_Name << ") is born !" << std::endl;
	*this = p_FragTrap;
}

FragTrap::~FragTrap(void)
{
	std::cout << "Destructor: A FragTrap(" << this->m_Name << ") is dead..." << std::endl;
}

void FragTrap::vaulthunter_dot_exe(std::string const & p_Target)
{
	std::string attacks[] =
	{
		"Second Wind",
		"Hyperion Punch",
		"Rainbow Coolant",
		"Cryogenic Exhaust Manifold",
		"Killbot",
	};

	if (this->m_nEnergyPoints >= ENERGY_COST)
	{
		std::cout << "FR4G-TP (" << this->m_Name << ") attacks " << p_Target << " with " << attacks[rand() % 4 + 1] << std::endl;
		this->m_nEnergyPoints -= ENERGY_COST;
	}
	else
		std::cout << "Not enough energy !" << std::endl;
}

