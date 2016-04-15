#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <string>
# include "AWeapon.hpp"
# include "Enemy.hpp"

class Character
{
private:
	std::string m_sName;
	int			m_nAp;
	int			m_nMaxAp;
	AWeapon		*m_pWeapon;

	Character(void);

public:
	Character(std::string const & p_sName);
	Character(Character const & p_Character);
	virtual ~Character(void);

	Character &	operator=(Character const & p_Character);

	void recoverAp(void);
	void equip(AWeapon *p_pAWeapon);
	void attack(Enemy *p_pEnemy);

	std::string const & getName(void) const;
	int getAp(void) const;
	int getMaxAp(void) const;
	AWeapon *getWeapon(void) const;

};

std::ostream & operator<<(std::ostream & p_ostream, Character const & p_character);

#endif /* !CHARACTER_HPP */

