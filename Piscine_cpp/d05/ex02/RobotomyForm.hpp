#ifndef ROBOTOMYFORM_HPP
# define ROBOTOMYFORM_HPP

# include "Form.hpp"

class RobotomyForm : public Form
{
private:
	RobotomyForm(RobotomyForm const & p_form);
	RobotomyForm &	operator=(RobotomyForm const & p_form);

public:
	RobotomyForm(void);
	RobotomyForm(std::string p_target);
	virtual ~RobotomyForm(void);

	virtual void		execute(Bureaucrat const & p_bureaucrat) const;

};

#endif /* !ROBOTOMYFORM_HPP */

