#include "NinjaTrap.hpp"

#include <iostream>
#include <stdlib.h>
#include <time.h>

NinjaTrap::NinjaTrap(void) :
	ClapTrap("", 60, 60, 120, 120, 60, 5, 0)
{
	std::cout << "Constructor: A new NinjaTrap(" << this->m_Name << ") is born !" << std::endl;
}

NinjaTrap::NinjaTrap(std::string p_Name) :
	ClapTrap(p_Name, 60, 60, 120, 120, 60, 5, 0)
{
	std::cout << "Constructor: A new NinjaTrap(" << this->m_Name << ") is born !" << std::endl;
}

NinjaTrap::NinjaTrap(NinjaTrap const & p_NinjaTrap) :
	ClapTrap(p_NinjaTrap)
{
	std::cout << "Constructor copy: A new NinjaTrap(" << this->m_Name << ") is born !" << std::endl;
	*this = p_NinjaTrap;
}

NinjaTrap::~NinjaTrap(void)
{
	std::cout << "Destructor: A NinjaTrap(" << this->m_Name << ") is dead..." << std::endl;
}

void NinjaTrap::ninjaShoebox(NinjaTrap & p_Target)
{
	std::cout << "NINJ4-TP (" << this->m_Name << ") Hey an other NinjaTrap, how are you " << p_Target.getName() << " ?" << std::endl;
	std::cout << p_Target.getName() << " : I'm twerking around !" << std::endl;
}

void NinjaTrap::ninjaShoebox(ScavTrap & p_Target)
{
	std::cout << "NINJ4-TP (" << this->m_Name << ") Oh, a shitty ScavTrap (" << p_Target.getName() << "), you are so ugly !"<< std::endl;
	std::cout << p_Target.getName() << " : Leave me alone you sneaky bot !" << std::endl;
}

void NinjaTrap::ninjaShoebox(FragTrap & p_Target)
{
	std::cout << "NINJ4-TP (" << this->m_Name << ") Haha, what are you doing FragTrap ?"<< std::endl;
	std::cout << p_Target.getName() << " : get out of my way !" << std::endl;
}

