#include "Bureaucrat.hpp"
#include "ShrubberyForm.hpp"
#include "RobotomyForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main(void)
{
	Bureaucrat peon("Henri", 145);
	Bureaucrat chief("Jack", 1);

	std::cout << "Shrubbery form" << std::endl;
	Form *form = new ShrubberyForm("Home");
	try
	{
		std::cout << *form << std::endl;
		chief.signForm(*form);
		peon.signForm(*form);
		std::cout << *form << std::endl;
		chief.executeForm(*form);
		peon.executeForm(*form);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	delete form;

	std::cout << std::endl << "Shrubbery form" << std::endl;
	Form *form0 = new ShrubberyForm("Home");
	try
	{
		std::cout << *form0 << std::endl;
		chief.executeForm(*form0);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	delete form0;

	std::cout << std::endl << "Robotomy form" << std::endl;
	Form *form1 = new RobotomyForm("Arthur Dent");
	try
	{
		std::cout << *form1 << std::endl;
		chief.signForm(*form1);
		std::cout << *form1 << std::endl;
		chief.executeForm(*form1);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	delete form1;

	std::cout << std::endl << "Presidential Pardon form" << std::endl;
	Form *form2 = new PresidentialPardonForm("Ford Prefect");
	try
	{
		std::cout << *form2 << std::endl;
		chief.signForm(*form2);
		std::cout << *form2 << std::endl;
		chief.executeForm(*form2);
		peon.executeForm(*form2);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	delete form2;

	return (0);
}
