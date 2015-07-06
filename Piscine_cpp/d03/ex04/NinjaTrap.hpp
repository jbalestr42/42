#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP

# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class NinjaTrap : public virtual ClapTrap
{
protected:
	NinjaTrap(void);

public:
	NinjaTrap(std::string p_Name);
	NinjaTrap(NinjaTrap const & p_NinjaTrap);
	virtual ~NinjaTrap(void);

	void ninjaShoebox(NinjaTrap & p_Target);
	void ninjaShoebox(ScavTrap & p_Target);
	void ninjaShoebox(FragTrap & p_Target);

};

#endif /* !NINJATRAP_HPP */

