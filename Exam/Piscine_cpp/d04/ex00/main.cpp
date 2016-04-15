#include "Victim.hpp"
#include "Peon.hpp"
#include "Sorcerer.hpp"
#include "Perifalk.hpp"

#include <iostream>

int main()
{
	Sorcerer robert("Robert", "the Magnificent");
	Victim jim("Jimmy");
	Peon joe("Joe");
	std::cout << robert << jim << joe;
	robert.polymorph(jim);
	robert.polymorph(joe);
	std::cout << std::endl;

	Perifalk henri("Henri");
	std::cout << henri;
	robert.polymorph(henri);
	std::cout << std::endl;

	Peon copy(joe);
	Peon copy2("Franck");
	copy2 = copy;
	std::cout << std::endl;

	return 0;
}

