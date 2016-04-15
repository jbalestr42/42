#include "Human.hpp"
#include <iostream>

Human::Human(void)
{
}

Human::~Human(void)
{
}

std::string Human::identify(void) const
{
	return this->m_Brain.identify();
}

Brain const &Human::getBrain(void) const
{
	return this->m_Brain;
}