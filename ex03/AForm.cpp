#include "./AForm.hpp"
#include "./Bureaucrat.hpp"
#include <iostream>

// The OCF Implementation

AForm::AForm(void):
	name("Default-AForm"),
	isSigned(false),
	signGrade(150),
	execGrade(150)
{
	std::cout << "[INFO]: (Default Construction){AForm}\n";
};


AForm::AForm(const std::string &str, const int signG, const int execG):
	name(str),
	isSigned(false),
	signGrade(signG),
	execGrade(execG)
{
	if (signG > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (signG < 0)
		throw Bureaucrat::GradeTooHighException();
	if (execG > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (execG < 0)
		throw Bureaucrat::GradeTooHighException();
	std::cout << "[INFO]: (Parameterized Construction){AForm}\n";
};

AForm::AForm(const AForm &other):
	name(other.getName()),
	isSigned(other.getSignature()),
	signGrade(other.getSignGrade()),
	execGrade(other.getExecGrade())
{
	if (other.getSignGrade() > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (other.getSignGrade() < 0)
		throw Bureaucrat::GradeTooHighException();
	if (other.getExecGrade() > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (other.getExecGrade() < 0)
		throw Bureaucrat::GradeTooHighException();
	std::cout << "[INFO]: (Copy Construction){AForm}\n";
};

AForm::~AForm(void) {
	std::cout << "[INFO]: (Destruction){AForm}\n";
}

void	AForm::operator=(const AForm &other) {
	std::cout << "[INFO]: ({=} Operator Overload){AForm}\n";
	if (this == &other)
		return ;
	throw AssignToConstException();
}

// Getters and Setters

const std::string	AForm::getName(void) const {
	return (name);
}

bool 	AForm::getSignature(void) const {
	return (isSigned);
}

size_t	AForm::getExecGrade(void) const {
	return (execGrade);
}

size_t	AForm::getSignGrade(void) const {
	return (signGrade);
}

void	AForm::beSigned(const Bureaucrat &B) {
	if (B.getGrade() <= signGrade)
		isSigned = true;
	else
		throw Bureaucrat::GradeTooLowException();
}


// Exceptions Implementations

const char*	AForm::GradeTooHighException::what() const throw() {
	return ("[AFormException]: GradeTooHigh");
}

const char*	AForm::GradeTooLowException::what() const throw() {
	return ("[AFormException]: GradeTooLow");
}

const char*	AForm::AssignToConstException::what() const throw() {
	return ("[AFormException]: AssignToConst");
}

const char*	AForm::FormNotSignedException::what() const throw() {
	return ("[AFormException]: FormNotSigned");
}

// Overloading the << operator

void operator<<(std::ostream &st, const AForm &F) {
	st << "AForm-Name:" + F.getName() + " |  Signature: " + (F.getSignature() ? "Yes" : "No")
		+ " |  SignGrade: " << F.getSignGrade() << " |  ExecGrade: " << F.getExecGrade() << std::endl;
}
