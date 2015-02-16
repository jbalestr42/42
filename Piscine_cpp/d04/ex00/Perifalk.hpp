#ifndef PERIFALK_HPP
# define PERIFALK_HPP

# include "Victim.hpp"

class Perifalk : public Victim
{
private:
	Perifalk(void);

public:
	Perifalk(std::string p_name);
	Perifalk(Perifalk const & p_Perifalk);
	virtual ~Perifalk(void);

	Perifalk &	operator=(Perifalk const & p_Perifalk);

	virtual void getPolymorphed(void) const;

};

#endif /* !PERIFALK_HPP */

