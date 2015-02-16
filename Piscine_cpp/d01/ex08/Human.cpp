#include "Human.hpp"
#include <iostream>
#include <map>

Human::Human(void)
{

}

Human::~Human(void)
{

}

void Human::meleeAttack(std::string const & target)
{
	std::cout << "melee attack against " << target << std::endl;
}

void Human::rangedAttack(std::string const & target)
{
	std::cout << "ranged attack against " << target << std::endl;
}

void Human::intimidatingShout(std::string const & target)
{
	std::cout << "intimidating shoot against " << target << std::endl;
}

void Human::action(std::string const & action_name, std::string const & target)
{
	typedef void (Human::*f)(std::string const &);
	std::map<std::string, f> map;
	map.insert(std::pair<std::string, f>("melee", &Human::meleeAttack));
	map.insert(std::pair<std::string, f>("ranged", &Human::rangedAttack));
	map.insert(std::pair<std::string, f>("intimidating", &Human::intimidatingShout));

	f fp = map[action_name];
	if (fp)
		(this->*fp)(target);
}
