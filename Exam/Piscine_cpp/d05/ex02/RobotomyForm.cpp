#include "RobotomyForm.hpp"
#include <fstream>
#include <stdlib.h>
#include <time.h>

RobotomyForm::RobotomyForm(void) :
	Form("Robotomy Form", 72, 45, "empty")
{ /* unused */ }

RobotomyForm::RobotomyForm(std::string p_target) :
	Form("Robotomy Form", 72, 45, p_target)
{
	srand(time(NULL));
}

RobotomyForm::RobotomyForm(RobotomyForm const & p_form) :
	Form("Robotomy Form", 72, 45, "empty")
{
	*this = p_form;
}

RobotomyForm::~RobotomyForm(void)
{}

RobotomyForm & RobotomyForm::operator=(RobotomyForm const & p_form)
{
	Form::operator=(p_form);
	return (*this);
}

void RobotomyForm::execute(Bureaucrat const & p_bureaucrat) const
{
	Form::checkGradeToExec(p_bureaucrat.getGrade());

	std::cout << "\a\a\a\a" << std::endl;
	if ((rand() % 100 + 0) <= 50)
		std::cout << p_bureaucrat.getName() << " has been robotomized !" << std::endl;
	else
		std::cout << "Robotomized failed !" << std::endl;
}
