#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <string>
# include "Weapon.hpp"

class HumanA
{
private:
	Weapon *m_Weapon;
	std::string m_Name;

public:
	HumanA(std::string p_Name, Weapon &p_Weapon);
	~HumanA(void);

	void setWeapon(Weapon &p_Weapon);
	void attack(void) const;

};

#endif /* !HUMANA_HPP */
