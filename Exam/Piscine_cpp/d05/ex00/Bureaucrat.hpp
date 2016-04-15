#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <stdexcept>

# define MIN_GRADE 150
# define MAX_GRADE 1

class Bureaucrat
{
private:
	std::string const	m_name;
	int					mn_grade;

public:
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

	Bureaucrat(void);
	Bureaucrat(std::string const & p_name, int pn_grade);
	Bureaucrat(Bureaucrat const & p_bureaucrat);
	virtual ~Bureaucrat(void);

	Bureaucrat &	operator=(Bureaucrat const & p_bureaucrat);

	std::string const &	getName(void) const;
	int					getGrade(void) const;

	void				increaseGrade(void);
	void				decreaseGrade(void);

};

std::ostream & operator<<(std::ostream & p_ostream, Bureaucrat const & p_bureaucrat);

#endif /* !BUREAUCRAT_HPP */

