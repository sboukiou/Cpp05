#include "./RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(void):
	AForm("RobotomyRequestForm", 25, 5),
	target("Default-Target")
{
	std::cout << "[INFO]: (Default construction){RobotomyRequestForm}\n";
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &param):
	AForm("RobotomyRequestForm", 25, 5),
	target(param)
{
	std::cout << "[INFO]: (Parameterized construction){RobotomyRequestForm}\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other):
	AForm("RobotomyRequestForm", 25, 5),
	target(other.getTarget())
{
	std::cout << "[INFO]: (Copy construction){RobotomyRequestForm}\n";
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
	std::cout << "[INFO]: (Destruction){RobotomyRequestForm}\n";
}

void	RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
	if (this == &other)
		return ;
	target = other.getTarget();
}

const std::string	&RobotomyRequestForm::getTarget(void) const {
	return (target);
}

void	RobotomyRequestForm::setTarget(const std::string &param) {
	target = param;
}

void	RobotomyRequestForm::execute(const Bureaucrat &Ex) const {
	if (AForm::getSignature() == false)
		throw FormNotSignedException();;
	if (Ex.getGrade() > AForm::getExecGrade())
		throw Bureaucrat::GradeTooLowException();
	std::cout << target << " has been robotomized successfully 50% of the time. \n";
}
