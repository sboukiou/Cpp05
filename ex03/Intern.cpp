#include "./Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <cstdlib>

AForm	*makePresident(const std::string &target) {
	return new PresidentialPardonForm(target);
}

AForm	*makeShrubbery(const std::string &target) {
	return new ShrubberyCreationForm(target);
}

AForm	*makeRobotomy(const std::string &target) {
	return new RobotomyRequestForm(target);
}

Intern::Intern(void): name("Dummy-Intern") {

	genericForm[0] = &makePresident;
	genericForm[1] = &makeShrubbery;
	genericForm[2] = &makeRobotomy;
	std::cout << "[INFO]: (Default construction){Intern}\n";
}

Intern::Intern(const std::string &param): name(param) {
	genericForm[0] = &makePresident;
	genericForm[1] = &makeShrubbery;
	genericForm[2] = &makeRobotomy;
	std::cout << "[INFO]: (Parameterized construction){Intern}\n";
}

Intern::Intern(const Intern &other): name(other.name) {
	genericForm[0] = &makePresident;
	genericForm[1] = &makeShrubbery;
	genericForm[2] = &makeRobotomy;
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

const char *Intern::FormNotFoundException::what(void) const throw() {
	return ("(InternException)[Form not Found !\n]");
}

AForm*	Intern::makeForm(const std::string &formName, const std::string &targetName) {
	AForm *form = NULL;
	const std::string FormsLabels[3] = {"PresidentialPardonForm"
		, "ShrubberyCreationForm", "RobotomyRequestForm"};
	for (int i = 0; i < 3; i += 1) {
		if (targetName == FormsLabels[i]) {
			std::cout << "Found it \n";
			form = genericForm[i](targetName);
			if (form == NULL) {
				std::cerr << "Failed to make the form " << formName << std::endl;
				exit(0);
			}
			return (form);
		}
	}
	if (form == NULL)
		throw Intern::FormNotFoundException();
	return (NULL);
}

