#include "Brain.hpp"
#include <iostream>
#include <sstream> //for std::stringstream 
#include <string>  //for std::string

Brain::Brain(void)
{
}

Brain::~Brain(void)
{
}

std::string Brain::identify(void) const
{
	const void * address = (const void*)(this);
	std::stringstream ss;
	ss << address;  
	std::string name = "0x" + ss.str(); 

	return name;
}