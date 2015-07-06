#include <stdexcept>
#include <iostream>
#include <algorithm>

template<typename T>
void easyfind(T & pt_container, int pn_toFind)
{
	typename T::iterator it;
	it = std::find(pt_container.begin(), pt_container.end(), pn_toFind);
	if (it != pt_container.end())
		std::cout << "Found " << pn_toFind << "." << std::endl;
	else
		throw std::exception();
}
