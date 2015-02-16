#include "SuperTrap.hpp"

#include <iostream>

SuperTrap::SuperTrap(void) :
	ClapTrap("", 100, 100, 120, 120, 60, 20, 5),
	FragTrap(),
	NinjaTrap()
{
	std::cout << "Constructor: A new SuperTrap(" << this->m_Name << ") is born !" << std::endl;
}

SuperTrap::SuperTrap(std::string p_Name) :
	ClapTrap(p_Name, 100, 100, 120, 120, 60, 20, 5),
	FragTrap(),
	NinjaTrap()
{
	std::cout << "Constructor: A new SuperTrap(" << this->m_Name << ") is born !" << std::endl;
}

SuperTrap::SuperTrap(SuperTrap const & p_SuperTrap) :
	ClapTrap(p_SuperTrap),
	FragTrap(p_SuperTrap),
	NinjaTrap(p_SuperTrap)
{
	std::cout << "Constructor copy: A new SuperTrap(" << this->m_Name << ") is born !" << std::endl;
	*this = p_SuperTrap;
}

SuperTrap::~SuperTrap(void)
{
	std::cout << "Destructor: A SuperTrap(" << this->m_Name << ") is dead..." << std::endl;
}

