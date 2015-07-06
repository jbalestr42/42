#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <string>
# include "Weapon.hpp"

class HumanB
{
private:
	Weapon *m_Weapon;
	std::string m_Name;

public:
	HumanB(std::string p_Name);
	~HumanB(void);

	void setWeapon(Weapon &p_Weapon);
	void attack(void) const;

};

#endif /* !HUMANB_HPP */