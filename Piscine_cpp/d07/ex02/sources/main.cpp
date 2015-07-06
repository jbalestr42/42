#include <iostream>
#include "Array.hpp"

int main(void)
{
	try
	{
		Array<std::string> array(5);
		for (int i = 0; i < array.size(); i++)
		{
			array[i] = "t1";
			std::cout << array[i] << std::endl;
		}
		Array<std::string> sarray(2);
		std::cout << std::endl;
		for (int i = 0; i < sarray.size(); i++)
		{
			sarray[i] = "t2";
			std::cout << sarray[i] << std::endl;
		}
		sarray = array;
		std::cout << std::endl;
		for (int i = 0; i < sarray.size(); i++)
		{
			std::cout << sarray[i] << std::endl;
		}
		std::cout << array[6] << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
