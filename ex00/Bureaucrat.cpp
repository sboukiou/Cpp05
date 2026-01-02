#include "./Bureaucrat.hpp"
#include <iostream>
#include <string>

Bureaucrat::Bureaucrat(void): name("Un-Named"), grade(150) {
	std::cout << "[INFO]: (Default Constructor){Bureaucrat}" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &param, const unsigned int &num): name(param), grade(num) {
	if (num < 0)
		throw GradeTooHighException();
	if (num > 150)
		throw GradeTooLowException();
	std::cout << "[INFO]: (Parameterized Constructor){Bureaucrat}" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other): name(other.getName()), grade(other.getGrade()) {
	std::cout << "[INFO]: (Copy Constructor){Bureaucrat}" << std::endl;
}
Bureaucrat::~Bureaucrat(void) {
	std::cout << "[INFO]: (Destructor){Bureaucrat}" << std::endl;
}

void	Bureaucrat::operator=(const Bureaucrat &other) {
	if (this == &other)
		return ;
	name = other.getName();
	grade = other.getGrade();
	std::cout << "[INFO]: (Assignment operator overload){Bureaucrat}" << std::endl;
}

const std::string &Bureaucrat::getName(void) const {
	return (name);
}
void	Bureaucrat::setName(const std::string &param) {
	name = param;
}
const unsigned int &Bureaucrat::getGrade(void) const {
	return (grade);
}
void	Bureaucrat::setGrade(const unsigned int &param) {
	if (param < 0)
		throw GradeTooHighException();
	if (param > 150)
		throw GradeTooLowException();
	grade = param;
}


const char *Bureaucrat::GradeTooHighException::what(void) const throw() {
	return ("Bureaucrat Exception: GradeTooHigh");
}
const char *Bureaucrat::GradeTooLowException::what(void) const throw() {
	return ("Bureaucrat Exception: GradeTooLow");
}

void	Bureaucrat::incrementGrade(void) {
	if (grade > 0)
		grade -= 1;
	else
		throw GradeTooLowException();
}
void	Bureaucrat::decrementGrade(void) {
	if (grade < 150)
		grade += 1;
	else
		throw GradeTooHighException();
}


void	operator<<(std::ostream &st, const Bureaucrat &b) {
	st << b.getName() + ", bureaucrat grade " << b.getGrade();
	st << std::endl;
}
