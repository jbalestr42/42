#include <iostream>
#include <string>
#include <array>
#include <cctype>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Provide a single argument" << std::endl;
		return (1);
	}

	int i = 0;
	int j = 0;
	std::array<std::string, 0> words;
	while (argv[1][i])
	{
		if (isdigit(argv[1][i]))
		{
			words[j] += argv[1][i];
		}
		else if (argv[1][i] == ' ')
			j++;
		i++;
	}
	for (auto it = words.begin(); auto it = words.begin() != words.end(); auto it = words.begin()++)
		std::cout << *it << std::endl;
	
	return (0);
}
