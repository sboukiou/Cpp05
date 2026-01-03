#include "./Intern.hpp"
#include <iostream>

Intern::Intern(void): name("Dummy-Intern") {
	std::cout << "[INFO]: (Default construction){Intern}\n";
}

Intern::Intern(const std::string &param): name(param) {
	std::cout << "[INFO]: (Parameterized construction){Intern}\n";
}

Intern::Intern(const Intern &other): name(other.name) {
	std::cout << "[INFO]: (Copy construction){Intern}\n";
}

Intern::~Intern(void) {
	std::cout << "[INFO]: (Destruction){Intern}\n";
}

void	Intern::operator=(const Intern &other) {
	if (&other == this)
		return ;
	name = other.name;
	std::cout << "[INFO]: (Assignment operator overload){Intern}\n";
}

AForm*	makeForm(const std::string &formName, const std::string &targetName) {

}

