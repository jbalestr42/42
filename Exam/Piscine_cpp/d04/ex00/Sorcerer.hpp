#ifndef SORCERER_HPP
# define SORCERER_HPP

# include <string>
# include "Victim.hpp"

class Sorcerer
{
private:
	std::string m_name;
	std::string m_title;

	Sorcerer(void);

public:
	Sorcerer(std::string p_name, std::string p_title);
	Sorcerer(Sorcerer const & p_sorcerer);
	virtual ~Sorcerer(void);

	Sorcerer &	operator=(Sorcerer const & p_sorcerer);

	std::string getName(void) const;
	std::string getTitle(void) const;

	void polymorph(Victim const & p_victim) const;

};

std::ostream & operator<<(std::ostream & p_ostream, Sorcerer const & p_sorcerer);

#endif /* !SORCERER_HPP */

