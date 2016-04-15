#include "Bureaucrat.hpp"
#include <iostream>

int main(void)
{
	int			grades[] = { 1, 150, 0, 160, 100};
	std::string	names[] = { "Gui", "Pe", "Fran", "Bra", "Ju" };

	for (int i = 0; i < 5; i++)
	{
		try
		{
			Bureaucrat b(names[i], grades[i]);
			std::cout << b;
			std::cout << "increase : ";
			b.increaseGrade();
			std::cout << b;
			std::cout << "decrease : ";
			b.decreaseGrade();
			std::cout << b;
			std::cout << "decrease : ";
			b.decreaseGrade();
			std::cout << b;
		}
		catch(std::exception & e)
		{
			std::cout << "Grade " << grades[i] << " "  << e.what() << std::endl;
		}
	}
	return (0);
}
