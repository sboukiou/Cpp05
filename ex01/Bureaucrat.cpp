#include "./Bureaucrat.hpp"
#include "./Form.hpp"
#include <iostream>
#include <string>

Bureaucrat::Bureaucrat(void): name("Un-Named-Bureaucrat"), grade(150) {
	std::cout << "[INFO]: (Default Constructor){Bureaucrat}" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &param, const int &num): name(param), grade(num) {
	if (num < 0)
		throw GradeTooHighException();
	if (num > 150)
		throw GradeTooLowException();
	std::cout << "[INFO]: (Parameterized Constructor){Bureaucrat}" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other): name(other.getName() + "_copy"), grade(other.getGrade()) {
	std::cout << "[INFO]: (Copy Constructor){Bureaucrat}" << std::endl;
}
Bureaucrat::~Bureaucrat(void) {
	std::cout << "[INFO]: (Destructor){Bureaucrat}" << std::endl;
}

void	Bureaucrat::operator=(const Bureaucrat &other) {
	if (this == &other)
		return ;
	grade = other.getGrade();
	std::cout << "[INFO]: (Assignment operator overload){Bureaucrat}" << std::endl;
	std::cout << "[WARN]: Only grade is changeable, names ar constants\n";
}

const std::string &Bureaucrat::getName(void) const {
	return (name);
}
const size_t &Bureaucrat::getGrade(void) const {
	return (grade);
}
void	Bureaucrat::setGrade(const int &param) {
	if (param < 1)
		throw GradeTooHighException();
	if (param > 150)
		throw GradeTooLowException();
	grade = param;
}

void	Bureaucrat::incrementGrade(void) {
	if (grade > 0) {
		grade -= 1;
		if (grade == 0)
			std::cout << "Bureaucrat {" << name << "} is now an Ultimate bureaucrat\n";
	}
	else
		throw GradeTooHighException();
}
void	Bureaucrat::decrementGrade(void) {
	if (grade < 150) {
		grade += 1;
		if (grade == 150)
			std::cout << "Poor Bureaucrat {" << name << "} Can't go down any further\n";
	}
	else
		throw GradeTooLowException();
}



void	Bureaucrat::signForm(Form &F) {
	try {
		F.beSigned(*this);
		std::cout << *this;
		std::cout << " signed ";
		std::cout << F;
		std::cout << std::endl;
	}
	catch (std::exception &e) {
		std::cout << *this;
		std::cout << " couldn’t sign ";
		std::cout << F;
		std::cout << " because ";
		std::cout << e.what() << std::endl;
	}
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw() {
	return ("{Bureaucrat Exception}: GradeTooHigh");
}
const char *Bureaucrat::GradeTooLowException::what(void) const throw() {
	return ("{Bureaucrat Exception}: GradeTooLow");
}

void	operator<<(std::ostream &st, const Bureaucrat &b) {
	st << b.getName() + ", bureaucrat grade " << b.getGrade();
}
