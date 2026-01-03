#include "./Bureaucrat.hpp"
#include "./AForm.hpp"
#include <iostream>
#include <string>

Bureaucrat::Bureaucrat(void): name("Un-Named"), grade(150) {
	std::cout << "[INFO]: (Default Constructor){Bureaucrat}" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &param, const size_t &num): name(param), grade(num) {
	if (num < 0)
		throw Bureaucrat::GradeTooHighException();
	if (num > 150)
		throw Bureaucrat::GradeTooLowException();
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
	grade = other.getGrade();
	std::cout << "[INFO]: (Assignment operator overload){Bureaucrat}" << std::endl;
}

const std::string &Bureaucrat::getName(void) const {
	return (name);
}
const size_t &Bureaucrat::getGrade(void) const {
	return (grade);
}
void	Bureaucrat::setGrade(const int &param) {
	if (param < 1)
		throw Bureaucrat::GradeTooHighException();
	if (param > 150)
		throw Bureaucrat::GradeTooLowException();
	grade = param;
}

void	Bureaucrat::signForm(AForm &F) {
	try {
		F.beSigned(*this);
		std::cout << *this;
		std::cout << " signed ";
		std::cout << F;
	}
	catch (std::exception &e) {
		std::cout << *this;
		std::cout << "couldn’t sign ";
		std::cout << F;
		std::cout << "because ";
		std::cout << e.what();
	}
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw() {
	return ("{Bureaucrat Exception}: GradeTooHigh");
}
const char *Bureaucrat::GradeTooLowException::what(void) const throw() {
	return ("{Bureaucrat Exception}: GradeTooLow");
}

void	Bureaucrat::incrementGrade(void) {
	if (grade > 0)
		grade -= 1;
	else
		throw Bureaucrat::GradeTooHighException();
}
void	Bureaucrat::decrementGrade(void) {
	if (grade < 150)
		grade += 1;
	else
		throw Bureaucrat::GradeTooLowException();
}


void	operator<<(std::ostream &st, const Bureaucrat &b) {
	st << b.getName() + ", bureaucrat grade " << b.getGrade() << " ";
}

void	Bureaucrat::executeForm(const AForm &F) {
	try {
		F.execute(*this);
	}
	catch(std::exception &e) {
		std::cerr << "Catchd: " << e.what() << std::endl;
	}
		std::cout << *this;
		std::cout << " executed ";
		std::cout << F;
		std::cout << "\n";
}
