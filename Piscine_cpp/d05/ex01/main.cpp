#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main(void)
{
	int			grades[] = { 1, 150, 0, 160, 100};
	std::string	names[] = { "Gui", "Pe", "Fran", "Bra", "Ju" };
	std::string	forms[] = {  "Form1", "Form2", "Form3", "Form4", "Form5", };

	Bureaucrat peon("Henri", 145);
	Bureaucrat chief("Jack", 1);

	for (int i = 0; i < 5; i++)
	{
		std::cout << "------------- Test " << i << std::endl;
		try
		{
			Form form(forms[i], grades[i], 120);
			std::cout << form << std::endl;
			chief.signForm(form);
			peon.signForm(form);
			std::cout << form << std::endl;
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << std::endl;

	for (int i = 0; i < 5; i++)
	{
		try
		{
			Bureaucrat b(names[i], grades[i]);
			std::cout << b << std::endl;
			std::cout << "increase : ";
			b.increaseGrade();
			std::cout << b << std::endl;
			std::cout << "decrease : ";
			b.decreaseGrade();
			std::cout << b << std::endl;
			std::cout << "decrease : ";
			b.decreaseGrade();
			std::cout << b << std::endl;
		}
		catch (std::exception & e)
		{
			std::cout << "Grade " << grades[i] << " "  << e.what() << std::endl;
		}
	}
	return (0);
}
