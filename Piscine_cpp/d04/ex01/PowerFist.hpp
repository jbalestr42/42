#ifndef POWERFIST_HPP
# define POWERFIST_HPP

# include "AWeapon.hpp"

class PowerFist : public AWeapon
{
public:
	PowerFist(void);
	PowerFist(PowerFist const & p_PowerFist);
	virtual ~PowerFist(void);

	PowerFist &	operator=(PowerFist const & p_PowerFist);

	virtual void attack(void) const;

};

#endif /* !POWERFIST_HPP */

