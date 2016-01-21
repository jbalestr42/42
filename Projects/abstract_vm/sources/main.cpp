#include <iostream>
#include "Operand.hpp"
#include "Factory.hpp"
#include "File.hpp"
#include "Exceptions.hpp"
#include "InstructionStack.hpp"

bool	checkEndOfRead(std::string const & line)
{
	if (line.length() >= 2)
	{
		if (line[0] == ';' && line[1] == ';')
			return (true);
	}
	return (false);
}

void	parse_args(int argc, char ** argv)
{
	InstructionStack stack;
	if (argc < 2)
	{
		std::string line;
		while (getline(std::cin, line))
		{
			if (checkEndOfRead(line))
				break;
			stack.processLine(line);
		}
	}
	else
	{
		File file(argv[1]);
		std::string line;
		while (file.readLine(line))
		{
			stack.processLine(line);
		}
	}
	stack.process();
}

int		main(int argc, char ** argv)
{
	try
	{
		parse_args(argc, argv);
	}
	catch (std::exception const & e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
