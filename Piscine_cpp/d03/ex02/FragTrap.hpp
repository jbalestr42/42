#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <string>
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	FragTrap(void);

public:
	FragTrap(std::string p_Name);
	FragTrap(FragTrap const & p_FragTrap);
	virtual ~FragTrap(void);

	void vaulthunter_dot_exe(std::string const & p_Target);

};

#endif /* !FRAGTRAP_HPP */

