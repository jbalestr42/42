#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"
#include "ClapTrap.hpp"
#include "SuperTrap.hpp"
#include <iostream>

int main(void)
{
	std::cout << "FragTrap demonstration" << std::endl;
	FragTrap fragTrap("FragTrap");
	FragTrap fragTrap2(fragTrap);

	fragTrap.rangedAttack("Dr Zed");
	fragTrap.meleeAttack("Dr Zed");
	fragTrap.takeDamage(20);
	fragTrap.takeDamage(100);
	fragTrap.beRepaired(30);
	fragTrap.beRepaired(80);

	for (int i = 0; i < 5; i++)
		fragTrap.vaulthunter_dot_exe("Dr Zed");

	std::cout << std::endl << "ScavTrap demonstration" << std::endl;
	ScavTrap scavTrap("ScavTrap");
	ScavTrap scavTrap2(scavTrap);

	scavTrap.rangedAttack("Dr Zed");
	scavTrap.meleeAttack("Dr Zed");
	scavTrap.takeDamage(20);
	scavTrap.takeDamage(100);
	scavTrap.beRepaired(30);
	scavTrap.beRepaired(80);

	for (int i = 0; i < 5; i++)
		scavTrap.challengeNewcomer();

	std::cout << std::endl << "NinjaTrap demonstration" << std::endl;
	NinjaTrap ninjaTrap("NinjaTrap");
	NinjaTrap ninjaTrap2(ninjaTrap);

	ninjaTrap.rangedAttack("Dr Zed");
	ninjaTrap.meleeAttack("Dr Zed");
	ninjaTrap.takeDamage(20);
	ninjaTrap.takeDamage(100);
	ninjaTrap.beRepaired(30);
	ninjaTrap.beRepaired(80);

	ninjaTrap.ninjaShoebox(fragTrap);
	ninjaTrap.ninjaShoebox(scavTrap);
	ninjaTrap.ninjaShoebox(ninjaTrap);

	std::cout << std::endl << "SuperTrap demonstration" << std::endl;
	SuperTrap superTrap("SuperTrap");
	SuperTrap superTrap2(superTrap);

	superTrap.rangedAttack("Dr Zed");
	superTrap.meleeAttack("Dr Zed");
	superTrap.takeDamage(20);
	superTrap.takeDamage(100);
	superTrap.beRepaired(30);
	superTrap.beRepaired(80);

	superTrap.ninjaShoebox(fragTrap);
	superTrap.ninjaShoebox(scavTrap);
	superTrap.ninjaShoebox(ninjaTrap);

	for (int i = 0; i < 5; i++)
		superTrap.vaulthunter_dot_exe("Dr Zed");

	std::cout << std::endl;
	return (0);
}
