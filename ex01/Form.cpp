#include "./Form.hpp"
#include "./Bureaucrat.hpp"
#include <iostream>

// The OCF Implementation

Form::Form(void):
	name("Default-Form"),
	isSigned(false),
	signGrade(150),
	execGrade(150)
{
	std::cout << "[INFO]: (Default Construction){Form}\n";
};


Form::Form(const std::string &str, const int signG, const int execG):
	name(str),
	isSigned(false),
	signGrade(signG),
	execGrade(execG)
{
	if (signG > 150)
		throw GradeTooLowException();
	else if (signG < 0)
		throw GradeTooHighException();
	if (execG > 150)
		throw GradeTooLowException();
	else if (execG < 0)
		throw GradeTooHighException();
	std::cout << "[INFO]: (Parameterized Construction){Form}\n";
};

Form::Form(const Form &other):
	name(other.getName()),
	isSigned(other.getSignature()),
	signGrade(other.getSignGrade()),
	execGrade(other.getExecGrade())
{
	if (other.getSignGrade() > 150)
		throw GradeTooLowException();
	else if (other.getSignGrade() < 0)
		throw GradeTooHighException();
	if (other.getExecGrade() > 150)
		throw GradeTooLowException();
	else if (other.getExecGrade() < 0)
		throw GradeTooHighException();
	std::cout << "[INFO]: (Copy Construction){Form}\n";
};

Form::~Form(void) {
	std::cout << "[INFO]: (Destruction){Form}\n";
}

void	Form::operator=(const Form &other) {
	std::cout << "[INFO]: ({=} Operator Overload){Form}\n";
	if (this == &other)
		return ;
	throw AssignToConstException();
}

// Getters and Setters

const std::string	Form::getName(void) const {
	return (name);
}

bool 	Form::getSignature(void) const {
	return (isSigned);
}

size_t	Form::getExecGrade(void) const {
	return (execGrade);
}

size_t	Form::getSignGrade(void) const {
	return (signGrade);
}

void	Form::beSigned(const Bureaucrat &B) {
	if (B.getGrade() <= signGrade)
		isSigned = true;
	else
		throw GradeTooLowException();
}


// Exceptions Implementations

const char*	Form::GradeTooHighException::what() const throw() {
	return ("[FormException]: GradeTooHigh");
}

const char*	Form::GradeTooLowException::what() const throw() {
	return ("[FormException]: GradeTooLow");
}

const char*	Form::AssignToConstException::what() const throw() {
	return ("[FormException]: AssignToConst");
}

// Overloading the << operator

void operator<<(std::ostream &st, const Form &F) {
	st << "Form-Name:" + F.getName() + " |  Signature: " + (F.getSignature() ? "Yes" : "No")
		+ " |  SignGrade: " << F.getSignGrade() << " |  ExecGrade: " << F.getExecGrade() << std::endl;
}
