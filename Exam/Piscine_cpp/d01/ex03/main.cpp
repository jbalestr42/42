#include <iostream>
#include "ZombieHorde.hpp"

int main(void)
{
	ZombieHorde *pZombieHorde = new ZombieHorde(10);
	pZombieHorde->annonce();
	delete pZombieHorde;
	return (0);
}