#include "Victim.hpp"

#include <iostream>

Victim::Victim(void) { /* unused */ }

Victim::Victim(std::string p_name) :
	m_name(p_name)
{
	std::cout << "Some random victim called " << this->m_name << " just popped !" << std::endl;
}

Victim::Victim(Victim const & p_victim)
{
	*this = p_victim;
	std::cout << "Some random victim called " << this->m_name << " just popped !" << std::endl;
}

Victim::~Victim(void)
{
	std::cout << "Victim " << this->m_name << " just died for no apparent reason !" << std::endl;
}

Victim & Victim::operator=(Victim const & p_victim)
{
	this->m_name = p_victim.m_name;
	return (*this);
}

std::string Victim::getName(void) const
{
	return (this->m_name);
}

void Victim::getPolymorphed(void) const
{
	std::cout << this->m_name << "has been turned into a cute little sheep !" << std::endl;
}

std::ostream & operator<<(std::ostream & p_ostream, Victim const & p_victim)
{
	p_ostream << "I'm " << p_victim.getName() << " and i like otters !" << std::endl;
	return (p_ostream);
}
