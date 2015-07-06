#include "ZombieEvent.hpp"
#include <stdlib.h>
#include <time.h>

ZombieEvent::ZombieEvent(void)
{
	srand((unsigned int)time(NULL));
}

ZombieEvent::~ZombieEvent(void)
{
}

void ZombieEvent::setZombieType(std::string p_Type)
{
	this->m_Type = p_Type;
}

Zombie* ZombieEvent::newZombie(std::string name)
{
	Zombie *pZombie = new Zombie(name);
	pZombie->setType(this->m_Type);

	return pZombie;
}

Zombie* ZombieEvent::randomChump(void)
{
	std::string names[6] = { "Ju", "Fran", "Pe", "Bra", "Mouff", "Mouch" };

	Zombie *pZombie = this->newZombie(names[rand() % 5 + 1]);
	pZombie->annonce();
	return pZombie;
}