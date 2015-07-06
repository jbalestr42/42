#ifndef SHRUBBERYFORM_HPP
# define SHRUBBERYFORM_HPP

# include "Form.hpp"

class ShrubberyForm : public Form
{
private:
	ShrubberyForm(ShrubberyForm const & p_form);
	ShrubberyForm &	operator=(ShrubberyForm const & p_form);

public:
	ShrubberyForm(void);
	ShrubberyForm(std::string p_target);
	virtual ~ShrubberyForm(void);

	virtual void		execute(Bureaucrat const & p_bureaucrat) const;

};

#endif /* !SHRUBBERYFORM_HPP */

