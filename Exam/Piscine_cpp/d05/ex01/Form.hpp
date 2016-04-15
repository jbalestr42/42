#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <stdexcept>
# include "Bureaucrat.hpp"

# define MIN_GRADE 150
# define MAX_GRADE 1

class Form
{
private:
	std::string const	m_name;
	int const			mn_gradeToSign;
	int const			mn_gradeToExec;
	bool				mb_isSigned;

	class GradeTooLowException : public std::exception
	{
	public:
		GradeTooLowException(void);
		GradeTooLowException(GradeTooLowException const & p_gradeTooLowException);
		virtual ~GradeTooLowException(void) throw();

		GradeTooLowException & operator=(GradeTooLowException const & p_gradeTooLowException);
		virtual const char * what(void) const throw();

	};

	class GradeTooHighException : public std::exception
	{
	public:
		GradeTooHighException(void);
		GradeTooHighException(GradeTooHighException const & p_gradeTooHighException);
		virtual ~GradeTooHighException(void) throw();

		GradeTooHighException & operator=(GradeTooHighException const & p_gradeTooHighException);
		virtual const char * what(void) const throw();

	};

public:
	Form(void);
	Form(std::string const & p_name, int pn_gradeToSign, int pn_gradeToExec);
	Form(Form const & p_form);
	virtual ~Form(void);

	Form &	operator=(Form const & p_form);

	std::string const &	getName(void) const;
	int					getGradeToSign(void) const;
	int					getGradeToExec(void) const;
	bool				getSigned(void) const;

	void				checkGrade(int pn_grade) const;
	void				beSigned(Bureaucrat & p_bureaucrat);

};

std::ostream & operator<<(std::ostream & p_ostream, Form const & p_form);

#endif /* !FORM_HPP */

