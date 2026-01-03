#include "./ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(void):
	AForm("ShrubberyCreationForm", 25, 5),
	target("Default-Target")
{
	std::cout << "[INFO]: (Default construction){ShrubberyCreationForm}\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &param):
	AForm("ShrubberyCreationForm", 25, 5),
	target(param)
{
	std::cout << "[INFO]: (Parameterized construction){ShrubberyCreationForm}\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other):
	AForm("ShrubberyCreationForm", 25, 5),
	target(other.getTarget())
{
	std::cout << "[INFO]: (Copy construction){ShrubberyCreationForm}\n";
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
	std::cout << "[INFO]: (Destruction){ShrubberyCreationForm}\n";
}

void	ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
	if (this == &other)
		return ;
	target = other.getTarget();
}

const std::string	&ShrubberyCreationForm::getTarget(void) const {
	return (target);
}

void	ShrubberyCreationForm::setTarget(const std::string &param) {
	target = param;
}

void	ShrubberyCreationForm::execute(const Bureaucrat &Ex) const {
	if (AForm::getSignature() == false)
		throw FormNotSignedException();;
	if (Ex.getGrade() > AForm::getExecGrade())
		throw GradeTooLowException();

	std::ofstream outFile((target + "[ShrubberyCreationForm]").c_str());

	outFile << "       _-_\n";
	outFile << "    /~~   ~~\\\n";
	outFile << " /~~         ~~\\\n";
	outFile << "{               }\n";
	outFile << " \\  _-     -_  /\n";
	outFile << "   ~  \\ //  ~\n";
	outFile << "_- -   | | _- _\n";
	outFile << "  _ -  | |   -_\n";
	outFile << "      // \\\\\n";
	outFile << std::endl;
	outFile.close();
}
