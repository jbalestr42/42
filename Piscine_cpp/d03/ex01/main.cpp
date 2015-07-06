#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main(void)
{
	FragTrap fragTrap("ClapTrap");
	FragTrap fragTrap2(fragTrap);

	fragTrap.rangedAttack("Dr Zed");
	fragTrap.meleeAttack("Dr Zed");
	fragTrap.takeDamage(20);
	fragTrap.takeDamage(100);
	fragTrap.beRepaired(30);
	fragTrap.beRepaired(80);

	for (int i = 0; i < 5; i ++)
		fragTrap.vaulthunter_dot_exe("Dr Zed");

	std::cout << std::endl;

	ScavTrap scavTrap("ScavTrap");
	ScavTrap scavTrap2(scavTrap);

	scavTrap.rangedAttack("Dr Zed");
	scavTrap.meleeAttack("Dr Zed");
	scavTrap.takeDamage(20);
	scavTrap.takeDamage(100);
	scavTrap.beRepaired(30);
	scavTrap.beRepaired(80);

	for (int i = 0; i < 5; i ++)
		scavTrap.challengeNewcomer();

	return (0);
}
