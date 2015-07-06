#ifndef PLASMARIFLE_HPP
# define PLASMARIFLE_HPP

# include "AWeapon.hpp"

class PlasmaRifle : public AWeapon
{
public:
	PlasmaRifle(void);
	PlasmaRifle(PlasmaRifle const & p_PlasmaRifle);
	virtual ~PlasmaRifle(void);

	PlasmaRifle &	operator=(PlasmaRifle const & p_PlasmaRifle);

	virtual void attack(void) const;

};

#endif /* !PLASMARIFLE_HPP */

