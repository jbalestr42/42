#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <string>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	ScavTrap(void);

public:
	ScavTrap(std::string p_Name);
	ScavTrap(ScavTrap const & p_ScavTrap);
	virtual ~ScavTrap(void);

	void challengeNewcomer(void);

};

#endif /* !SCAVTRAP_HPP */

