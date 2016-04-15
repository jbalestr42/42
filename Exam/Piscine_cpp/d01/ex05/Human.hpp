#ifndef HUMAN_HPP
# define HUMAN_HPP

# include <string>
# include "Brain.hpp"

class Human
{
private:
	Brain const m_Brain;

public:
	Human(void);
	~Human(void);

	std::string identify(void) const;
	Brain const &getBrain(void) const;

};

#endif /* !HUMAN_HPP */