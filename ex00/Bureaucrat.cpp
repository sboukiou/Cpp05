#include "./Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(void): name("Un-Named"), grade(0) {
	std::cout << "[INFO]: (Default Constructor){Bureaucrat}" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &param, const unsigned int &num): name(param), grade(num) {
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
	grade = param;
}


void	Bureaucrat::incrementGrade(void) {
	/*TODO:Increment the crazy greade here*/
}
void	Bureaucrat::decrementGrade(void) {
	/*TODO:Decrement the crazy greade here*/
}
