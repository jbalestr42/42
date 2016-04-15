#include "ShrubberyForm.hpp"
#include <fstream>

ShrubberyForm::ShrubberyForm(void) :
	Form("Shrubbery Form", 145, 137, "empty")
{ /* unused */ }

ShrubberyForm::ShrubberyForm(std::string p_target) :
	Form("Shrubbery Form", 145, 137, p_target)
{ /* unused */ }

ShrubberyForm::ShrubberyForm(ShrubberyForm const & p_form) :
	Form("Shrubbery Form", 145, 137, "empty")
{
	*this = p_form;
}

ShrubberyForm::~ShrubberyForm(void)
{}

ShrubberyForm & ShrubberyForm::operator=(ShrubberyForm const & p_form)
{
	Form::operator=(p_form);
	return (*this);
}

void ShrubberyForm::execute(Bureaucrat const & p_bureaucrat) const
{
	Form::checkGradeToExec(p_bureaucrat.getGrade());
	std::string fileName = m_target + "_shrubbery";
	std::ofstream ofs;
	ofs.open(fileName.c_str());
	std::string tree =
	"       .#.\n"
	"      .###.\n"
	"     .#%##%.\n"
	"    .%##%###.\n"
	"   .##%###%##.\n"
	"  .#%###%##%##.\n"
	"        #\n"
	"        #\n";
	ofs << tree << tree;
	ofs.close();
}
