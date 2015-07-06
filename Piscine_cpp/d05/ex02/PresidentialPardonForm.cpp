#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) :
	Form("Presidential Pardon Form", 25, 5, "empty")
{ /* unused */ }

PresidentialPardonForm::PresidentialPardonForm(std::string p_target) :
	Form("Presidential Pardon Form", 25, 5, p_target)
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & p_form) :
	Form("Presidential Pardon Form", 25, 5, "empty")
{
	*this = p_form;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & p_form)
{
	Form::operator=(p_form);
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const & p_bureaucrat) const
{
	Form::checkGradeToExec(p_bureaucrat.getGrade());

	std::cout << m_target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}
