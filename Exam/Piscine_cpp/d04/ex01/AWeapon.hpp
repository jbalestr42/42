#ifndef AWEAPON_HPP
# define AWEAPON_HPP

# include <string>

class AWeapon
{
private:
	std::string		m_sName;
	int				m_nApCost;
	int				m_nDamage;

protected:
	AWeapon(void);

public:
	AWeapon(std::string const & p_sName, int p_nApCost, int p_nDamage);
	AWeapon(AWeapon const & p_AWeapon);
	virtual ~AWeapon(void);

	AWeapon &	operator=(AWeapon const & p_AWeapon);

	std::string const & getName(void) const;
	int getApCost(void) const;
	int getDamage(void) const;

	virtual void attack(void) const = 0;

};

#endif /* !AWEAPON_HPP */

