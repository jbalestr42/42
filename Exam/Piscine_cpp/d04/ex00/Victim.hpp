#ifndef VICTIM_HPP
# define VICTIM_HPP

# include <string>

class Victim
{
protected:
	std::string m_name;

	Victim(void);

public:
	Victim(std::string p_name);
	Victim(Victim const & p_victim);
	virtual ~Victim(void);

	Victim &	operator=(Victim const & p_victim);

	std::string getName(void) const;
	virtual void getPolymorphed(void) const;

};

std::ostream & operator<<(std::ostream & p_ostream, Victim const & p_victim);

#endif /* !VICTIM_HPP */

