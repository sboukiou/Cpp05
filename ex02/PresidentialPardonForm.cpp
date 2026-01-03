#include "./PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(void):
	AForm("PresidentialPardonForm", 25, 5),
	target("Default-Target")
{
	std::cout << "[INFO]: (Default construction){PresidentialPardonForm}\n";
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &param):
	AForm("PresidentialPardonForm", 25, 5),
	target(param)
{
	std::cout << "[INFO]: (Parameterized construction){PresidentialPardonForm}\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other):
	AForm("PresidentialPardonForm", 25, 5),
	target(other.getTarget())
{
	std::cout << "[INFO]: (Copy construction){PresidentialPardonForm}\n";
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
	std::cout << "[INFO]: (Destruction){PresidentialPardonForm}\n";
}

void	PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
	if (this == &other)
		return ;
	target = other.getTarget();
}

const std::string	&PresidentialPardonForm::getTarget(void) const {
	return (target);
}

void	PresidentialPardonForm::setTarget(const std::string &param) {
	target = param;
}

void	PresidentialPardonForm::execute(const Bureaucrat &Ex) const {
	if (AForm::getSignature() == false)
		throw FormNotSignedException();;
	if (Ex.getGrade() > AForm::getExecGrade())
		throw Bureaucrat::GradeTooLowException();
	std::cout << target << " has been pardoned by Zaphod Beeblebrox.\n";
}
