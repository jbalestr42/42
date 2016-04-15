#ifndef ZOMBIE_HORDE_HPP
# define ZOMBIE_HORDE_HPP

# include <string>
# include "Zombie.hpp"

class ZombieHorde
{
private:
	std::string m_Type;
	int m_nNbZombies;
	Zombie *m_pZombies;

public:
	ZombieHorde(int p_nNbZombies);
	~ZombieHorde(void);

	void annonce(void) const;
};

#endif /* !ZOMBIE_HORDE_HPP */