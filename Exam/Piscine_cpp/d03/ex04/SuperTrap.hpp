#ifndef SUPERTRAP_HPP
# define SUPERTRAP_HPP

# include "FragTrap.hpp"
# include "NinjaTrap.hpp"

class SuperTrap : public FragTrap, public NinjaTrap
{
	SuperTrap(void);

public:
	SuperTrap(std::string p_Name);
	SuperTrap(SuperTrap const & p_SuperTrap);
	virtual ~SuperTrap(void);

};

#endif /* !SUPERTRAP_HPP */

