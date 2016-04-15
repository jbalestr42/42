#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <string>

class ScavTrap
{
private:
	std::string		m_Name;
	int				m_nHitPoints;
	int				m_nMaxHitPoints;
	int				m_nEnergyPoints;
	int				m_nMaxEnergyPoints;
	int				m_nLevel;
	int				m_nMeleeAttackDamage;
	int				m_nRangedAttackDamage;
	int				m_nArmorDamageReduction;

	ScavTrap(void);

public:
	ScavTrap(std::string p_Name);
	ScavTrap(ScavTrap const & p_ScavTrap);
	virtual ~ScavTrap(void);

	ScavTrap &	operator=(ScavTrap const & p_ScavTrap);

	void rangedAttack(std::string const & p_Target);
	void meleeAttack(std::string const & p_Target);
	void takeDamage(unsigned int p_nAmount);
	void beRepaired(unsigned int p_nAmount);
	void challengeNewcomer(void);

	void addHitPoint(int p_nAmount);
};

#endif /* !SCAVTRAP_HPP */

