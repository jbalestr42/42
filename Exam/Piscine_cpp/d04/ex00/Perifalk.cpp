#include "Perifalk.hpp"

#include <iostream>

Perifalk::Perifalk(void) { /* unused */ }

Perifalk::Perifalk(std::string p_name) :
	Victim(p_name)
{
	std::cout << "Peri peri." << std::endl;
}

Perifalk::Perifalk(Perifalk const & p_Perifalk) :
	Victim(p_Perifalk)
{
	std::cout << "Peri peri." << std::endl;
}

Perifalk::~Perifalk(void)
{
	std::cout << "Wuiiii..." << std::endl;
}

Perifalk & Perifalk::operator=(Perifalk const & p_Perifalk)
{
	Victim::operator=(p_Perifalk);
	return (*this);
}

void Perifalk::getPolymorphed(void) const
{
	std::cout << this->m_name << " has been turned into something unnamable!" << std::endl;
}
