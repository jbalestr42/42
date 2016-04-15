#ifndef ZOMBIE_EVENT_HPP
# define ZOMBIE_EVENT_HPP

# include <string>
# include "Zombie.hpp"

class ZombieEvent
{
private:
	std::string m_Type;

public:
	ZombieEvent(void);
	~ZombieEvent(void);

	void setZombieType(std::string p_Type);
	Zombie *newZombie(std::string name);
	Zombie *randomChump(void);

};

#endif /* !ZOMBIE_EVENT_HPP */