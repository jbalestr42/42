#ifndef PEON_HPP
# define PEON_HPP

# include "Victim.hpp"

class Peon : public Victim
{
private:
	Peon(void);

public:
	Peon(std::string p_name);
	Peon(Peon const & p_Peon);
	virtual ~Peon(void);

	Peon &	operator=(Peon const & p_Peon);

	virtual void getPolymorphed(void) const;

};

#endif /* !PEON_HPP */

