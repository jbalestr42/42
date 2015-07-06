#include "Peon.hpp"

#include <iostream>

Peon::Peon(void) { /* unused */ }

Peon::Peon(std::string p_name) :
	Victim(p_name)
{
	std::cout << "Zog zog." << std::endl;
}

Peon::Peon(Peon const & p_Peon) :
	Victim(p_Peon)
{
	std::cout << "Zog zog." << std::endl;
}

Peon::~Peon(void)
{
	std::cout << "Bleuark..." << std::endl;
}

Peon & Peon::operator=(Peon const & p_Peon)
{
	Victim::operator=(p_Peon);
	return (*this);
}

void Peon::getPolymorphed(void) const
{
	std::cout << this->m_name << " has been turned into a pink pony !" << std::endl;
}
