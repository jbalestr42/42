#include <list>
#include <vector>
#include "easyfind.hpp"


int main(void)
{
	try
	{
		std::list<int> list;

		list.push_back(5);
		list.push_back(2);
		list.push_back(6);
		list.push_back(15);
		list.push_back(2);
		easyfind(list, 5);

		std::vector<int> vector;
		vector.push_back(2);
		vector.push_back(3);
		vector.push_back(4);
		vector.push_back(5);
		vector.push_back(6);
		easyfind(vector, 2);
		easyfind(vector, 1);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
