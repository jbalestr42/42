#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include <string>

class FragTrap
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

	FragTrap(void);

public:
	FragTrap(std::string p_Name);
	FragTrap(FragTrap const & p_FragTrap);
	virtual ~FragTrap(void);

	FragTrap &	operator=(FragTrap const & p_FragTrap);

	void rangedAttack(std::string const & p_Target);
	void meleeAttack(std::string const & p_Target);
	void takeDamage(unsigned int p_nAmount);
	void beRepaired(unsigned int p_nAmount);
	void vaulthunter_dot_exe(std::string const & p_Target);

	void addHitPoint(int p_nAmount);
};

#endif /* !FRAGTRAP_HPP */

