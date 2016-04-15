#include "Sorcerer.hpp"

#include <iostream>

Sorcerer::Sorcerer(void) { /* unused */ }

Sorcerer::Sorcerer(std::string p_name, std::string p_title) :
	m_name(p_name),
	m_title(p_title)
{
	std::cout << this->m_name << ", " << this->m_title << ", is born !" << std::endl;
}

Sorcerer::Sorcerer(Sorcerer const & p_sorcerer)
{
	*this = p_sorcerer;
	std::cout << this->m_name << ", " << this->m_title << ", is born !" << std::endl;
}

Sorcerer::~Sorcerer(void)
{
	std::cout << this->m_name << ", " << this->m_title << ", is dead. Consequences will never be the same !" << std::endl;
}

Sorcerer & Sorcerer::operator=(Sorcerer const & p_sorcerer)
{
	this->m_name = p_sorcerer.m_name;
	this->m_title = p_sorcerer.m_title;
	return (*this);
}

std::string Sorcerer::getName(void) const
{
	return (this->m_name);
}

std::string Sorcerer::getTitle(void) const
{
	return (this->m_title);
}

void Sorcerer::polymorph(Victim const & p_victim) const
{
	p_victim.getPolymorphed();
}

std::ostream & operator<<(std::ostream & p_ostream, Sorcerer const & p_sorcerer)
{
	p_ostream << "I am " << p_sorcerer.getName() << ", " << p_sorcerer.getTitle() << ", and I like ponies !" << std::endl;
	return (p_ostream);
}
