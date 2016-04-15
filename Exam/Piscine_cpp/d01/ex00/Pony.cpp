#include "Pony.hpp"
#include <iostream>

Pony::Pony(void)
{
	std::cout << "A pony is born." << std::endl;
}

Pony::~Pony(void)
{
	std::cout << "A pony is dead." << std::endl;
}

void Pony::eatGrass(void) const
{
	std::cout << "I eat grass !" << std::endl;
}

void Pony::poopRainbow(void) const
{
	std::cout << "Pooooooop !" << std::endl;
}