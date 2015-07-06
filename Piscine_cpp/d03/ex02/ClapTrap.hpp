#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>

#define ENERGY_COST 25

class ClapTrap
{
protected:
	std::string		m_Name;
	int				m_nHitPoints;
	int				m_nMaxHitPoints;
	int				m_nEnergyPoints;
	int				m_nMaxEnergyPoints;
	int				m_nLevel;
	int				m_nMeleeAttackDamage;
	int				m_nRangedAttackDamage;
	int				m_nArmorDamageReduction;

	ClapTrap(void);

public:
	ClapTrap(std::string p_Name, int p_nHitPoints, int p_nMaxHitPoints, int p_nEnergyPoints, int p_nMaxEnergyPoint, int p_nMeleeAttackDamage, int p_nRangedAttackDamage, int p_nArmorDamageReduction);
	ClapTrap(ClapTrap const & p_ClapTrap);
	virtual ~ClapTrap(void);

	ClapTrap &	operator=(ClapTrap const & p_ClapTrap);

	void rangedAttack(std::string const & p_Target);
	void meleeAttack(std::string const & p_Target);
	void takeDamage(unsigned int p_nAmount);
	void beRepaired(unsigned int p_nAmount);
	void addHitPoint(int p_nAmount);

};

#endif /* !CLAPTRAP_HPP */

