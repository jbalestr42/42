#include <iostream>
#include <string>
#include <vector>
#include <cctype>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Provide a single argument" << std::endl;
		return (1);
	}

	std::vector<std::string> words;
	std::string str = argv[1];
	std::string newExpr;
	for (std::string::iterator it = str.begin(); it != str.end(); ++it)
	{
		if (isdigit(*it))
			newExpr.push_back(*it);
		else
		{
			if (newExpr.length())
			{
				words.push_back(newExpr);
				newExpr = "";
			}
		}
	}
	if (newExpr.length() > 0)
		words.push_back(newExpr);

	for (std::vector<std::string>::iterator it = words.begin(); it != words.end(); it++)
		std::cout << (*it) << std::endl;

	return (0);
}
