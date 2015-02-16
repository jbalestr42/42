#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) :
	m_name("empty"),
	mn_grade(150)
{ /* unused */ }

Bureaucrat::Bureaucrat(std::string const & p_name, int pn_grade) :
	m_name(p_name),
	mn_grade(pn_grade)
{
	if (pn_grade > MIN_GRADE)
		throw GradeTooLowException();
	if (pn_grade < MAX_GRADE)
		throw GradeTooHighException();
}

Bureaucrat::Bureaucrat(Bureaucrat const & p_bureaucrat)
{
	*this = p_bureaucrat;
}

Bureaucrat::~Bureaucrat(void)
{}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & p_bureaucrat)
{
	mn_grade = p_bureaucrat.mn_grade;
	return (*this);
}

std::string const & Bureaucrat::getName(void) const
{
	return m_name;
}

int Bureaucrat::getGrade(void) const
{
	return mn_grade;
}

void Bureaucrat::decreaseGrade(void)
{
	if (mn_grade + 1 > MIN_GRADE)
		throw GradeTooLowException();
	else
		mn_grade++;
}

void Bureaucrat::increaseGrade(void)
{
	if (mn_grade - 1 < MAX_GRADE)
		throw GradeTooHighException();
	else
		mn_grade--;
}

std::ostream & operator<<(std::ostream & p_ostream, Bureaucrat const & p_bureaucrat)
{
	p_ostream << p_bureaucrat.getName() << ", bureaucrat grade " << p_bureaucrat.getGrade() << std::endl;
	return p_ostream;
}

// Nested class GradeTooLowException
Bureaucrat::GradeTooLowException::GradeTooLowException(void) { /* unused */ }

Bureaucrat::GradeTooLowException::GradeTooLowException(GradeTooLowException const & p_gradeTooLowException)
{
	*this = p_gradeTooLowException;
}

Bureaucrat::GradeTooLowException::~GradeTooLowException(void) throw() {}

Bureaucrat::GradeTooLowException & Bureaucrat::GradeTooLowException::operator=(GradeTooLowException const & p_gradeTooLowException)
{
	(void)p_gradeTooLowException;
	return (*this);
}

const char *		Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return "Too Low Exception";
}

// Nested class GradeTooHighException
Bureaucrat::GradeTooHighException::GradeTooHighException(void) { /* unused */ }

Bureaucrat::GradeTooHighException::GradeTooHighException(GradeTooHighException const & p_gradeTooHighException)
{
	*this = p_gradeTooHighException;
}

Bureaucrat::GradeTooHighException::~GradeTooHighException(void) throw() {}

Bureaucrat::GradeTooHighException & Bureaucrat::GradeTooHighException::operator=(GradeTooHighException const & p_gradeTooHighException)
{
	(void)p_gradeTooHighException;
	return (*this);
}

const char *		Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return "Too High Exception";
}
