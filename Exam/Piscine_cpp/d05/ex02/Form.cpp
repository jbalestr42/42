#include "Form.hpp"

Form::Form(void) :
	m_name("empty"),
	mn_gradeToSign(1),
	mn_gradeToExec(1),
	mb_isSigned(false),
	m_target("empty")
{ /* unused */ }

Form::Form(std::string const & p_name, int pn_gradeToSign, int pn_gradeToExec, std::string const & p_target) :
	m_name(p_name),
	mn_gradeToSign(pn_gradeToSign),
	mn_gradeToExec(pn_gradeToExec),
	mb_isSigned(false),
	m_target(p_target)
{
	checkGrade(pn_gradeToSign);
	checkGrade(pn_gradeToExec);
}

Form::Form(Form const & p_form) :
	m_name("empty"),
	mn_gradeToSign(1),
	mn_gradeToExec(1),
	mb_isSigned(false),
	m_target("empty")
{
	*this = p_form;
}

Form::~Form(void)
{}

Form & Form::operator=(Form const & p_form)
{
	mb_isSigned = p_form.mb_isSigned;
	return (*this);
}

std::string const & Form::getName(void) const
{
	return m_name;
}

int Form::getGradeToSign(void) const
{
	return mn_gradeToSign;
}

int Form::getGradeToExec(void) const
{
	return mn_gradeToExec;
}

bool Form::getSigned(void) const
{
	return mb_isSigned;
}

void Form::checkGrade(int pn_grade) const
{
	if (pn_grade > MIN_GRADE)
		throw GradeTooLowException();
	if (pn_grade < MAX_GRADE)
		throw GradeTooHighException();
}

void Form::checkGradeToSign(int pn_grade) const
{
	if (pn_grade > mn_gradeToSign)
		throw GradeTooLowException();
}

void Form::checkGradeToExec(int pn_grade) const
{
	if (mb_isSigned)
	{
		if (pn_grade > mn_gradeToExec)
			throw GradeTooLowException();
	}
	else
		throw UnsignedFormException();
}

void Form::beSigned(Bureaucrat & p_bureaucrat)
{
	if (p_bureaucrat.getGrade() <= mn_gradeToSign)
		mb_isSigned = true;
	else
		throw Form::GradeTooLowException();
}

std::ostream & operator<<(std::ostream & p_ostream, Form const & p_form)
{
	p_ostream << "Form : " << p_form.getName() << ", grade to sign (" << p_form.getGradeToSign() << "), grade to execute (" << p_form.getGradeToExec() << "), signed (" << p_form.getSigned() << ")";
	return p_ostream;
}

// Nested class GradeTooLowException
Form::GradeTooLowException::GradeTooLowException(void) { /* unused */ }

Form::GradeTooLowException::GradeTooLowException(GradeTooLowException const & p_gradeTooLowException)
{
	*this = p_gradeTooLowException;
}

Form::GradeTooLowException::~GradeTooLowException(void) throw() {}

Form::GradeTooLowException & Form::GradeTooLowException::operator=(GradeTooLowException const & p_gradeTooLowException)
{
	(void)p_gradeTooLowException;
	return (*this);
}

const char *		Form::GradeTooLowException::what(void) const throw()
{
	return "Form Too Low Exception";
}

// Nested class GradeTooHighException
Form::GradeTooHighException::GradeTooHighException(void) { /* unused */ }

Form::GradeTooHighException::GradeTooHighException(GradeTooHighException const & p_gradeTooHighException)
{
	*this = p_gradeTooHighException;
}

Form::GradeTooHighException::~GradeTooHighException(void) throw() {}

Form::GradeTooHighException & Form::GradeTooHighException::operator=(GradeTooHighException const & p_gradeTooHighException)
{
	(void)p_gradeTooHighException;
	return (*this);
}

const char *		Form::GradeTooHighException::what(void) const throw()
{
	return "Form Too High Exception";
}

// Nested class UnsignedFormException
Form::UnsignedFormException::UnsignedFormException(void) { /* unused */ }

Form::UnsignedFormException::UnsignedFormException(UnsignedFormException const & p_gradeTooHighException)
{
	*this = p_gradeTooHighException;
}

Form::UnsignedFormException::~UnsignedFormException(void) throw() {}

Form::UnsignedFormException & Form::UnsignedFormException::operator=(UnsignedFormException const & p_gradeTooHighException)
{
	(void)p_gradeTooHighException;
	return (*this);
}

const char *		Form::UnsignedFormException::what(void) const throw()
{
	return "Unsigned Form Exception";
}

