#include <string>
#include <iostream>

int main(void)
{
	std::string string = "HI THIS IS BRAIN";
	std::string *pString = &string;
	std::string &rString = string;

	std::cout << "pointer string : " << *pString << std::endl;
	std::cout << "reference string : " << rString << std::endl;

	return (0);
}
