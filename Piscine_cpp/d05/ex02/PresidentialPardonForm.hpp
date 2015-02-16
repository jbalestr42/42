#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "Form.hpp"

class PresidentialPardonForm : public Form
{
private:
	PresidentialPardonForm(PresidentialPardonForm const & p_form);
	PresidentialPardonForm &	operator=(PresidentialPardonForm const & p_form);

public:
	PresidentialPardonForm(void);
	PresidentialPardonForm(std::string p_target);
	virtual ~PresidentialPardonForm(void);

	virtual void		execute(Bureaucrat const & p_bureaucrat) const;

};

#endif /* !PRESIDENTIALPARDONFORM_HPP */

