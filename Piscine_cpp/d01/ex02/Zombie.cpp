#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string p_Name)
{
	m_Name = p_Name;
	m_Type = "";
	std::cout << "----> A zombie (" << p_Name << ") is born !" << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << "----> A zombie is dead !" << std::endl;
}

void Zombie::annonce(void) const
{
	std::cout << "<" << this->m_Name << " (" << this->m_Type << ")> Braiiiiiiinnnssss..." << std::endl;
}

void Zombie::setType(std::string p_Type)
{
	this->m_Type = p_Type;
}
