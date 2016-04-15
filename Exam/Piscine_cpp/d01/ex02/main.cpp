#include <iostream>
#include "Zombie.hpp"
#include "ZombieEvent.hpp"

void hill(void)
{
	Zombie zombie("Highlander");
	zombie.setType("Immortal");
	zombie.annonce();
	std::cout << "__> There is an immortal zombie on the stack !" << std::endl;
	std::cout << "__> Leave him roam... he will die when we will leave the hill" << std::endl;
}

void hospital(void)
{
	ZombieEvent zombieEvent;
	zombieEvent.setZombieType("Crazy");

	std::cout << std::endl << "__> There is a large amount of zombie on the heap." << std::endl;
	for (int i = 0; i < 5; i++)
	{
		std::cout << std::endl;
		Zombie *pZombie = zombieEvent.randomChump();
		std::cout << "__> I killed one of them !" << std::endl;
		delete pZombie;
	}

	std::cout << std::endl << "__> We must leave this place, there are coming indefinitely" << std::endl;
}

int main(void)
{
	hill();
	hospital();

	return (0);
}