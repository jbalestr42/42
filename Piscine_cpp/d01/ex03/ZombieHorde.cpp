#include "ZombieHorde.hpp"
#include <stdlib.h>
#include <time.h>

ZombieHorde::ZombieHorde(int p_nNbZombies)
	:m_nNbZombies(p_nNbZombies)
{
	srand((unsigned int)time(NULL));
	char const *names[6] = { "Ju", "Fran", "Pe", "Bra", "Mouff", "Mouch"};

	this->m_pZombies = new Zombie[p_nNbZombies];
	for (int i = 0; i < p_nNbZombies; i++)
		this->m_pZombies[i].init(names[rand() % 5 + 1], "Horde");
}

ZombieHorde::~ZombieHorde(void)
{
	delete [] this->m_pZombies;
}

void ZombieHorde::annonce(void) const
{
	for (int i = 0; i < this->m_nNbZombies; i++)
		this->m_pZombies[i].annonce();
}