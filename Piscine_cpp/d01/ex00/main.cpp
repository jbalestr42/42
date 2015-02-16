#include "Pony.hpp"
#include <iostream>

void ponyOnTheHeap(void)
{
	Pony *pony = new Pony();

	pony->eatGrass();
	pony->poopRainbow();

	delete pony;
}

void ponyOnTheStack(void)
{
	Pony pony;

	pony.eatGrass();
	pony.poopRainbow();
}

int main(void)
{
	std::cout << "There is a Pony on the heap !" << std::endl;
	ponyOnTheHeap();

	std::cout << "There is a Pony on the stack !" << std::endl;
	ponyOnTheStack();
	return (0);
}