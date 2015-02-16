#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(void)
{
	m_Name = "";
	m_Type = "";
	std::cout << "Alivvveeee" << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << "Deaaaaaaad" << std::endl;
}

void Zombie::init(std::string p_Name, std::string p_Type)
{
	this->m_Name = p_Name;
	this->m_Type = p_Type;
}

void Zombie::annonce(void) const
{
	std::cout << "<" << this->m_Name << " (" << this->m_Type << ")> Braiiiiiiinnnssss..." << std::endl;
}

void Zombie::setType(std::string p_Type)
{
	this->m_Type = p_Type;
}
