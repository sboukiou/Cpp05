#include "./Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int main(void)
{
	AForm	*Pform = new PresidentialPardonForm("pTarget");
	AForm	*Sform = new ShrubberyCreationForm("STarget");
	AForm	*Rform = new RobotomyRequestForm("rTarget");

	Bureaucrat *P;
	Bureaucrat *S;
	Bureaucrat *R;
	try {
		P = new Bureaucrat("President", 0);
		S =  new Bureaucrat("Farmer", 10);
		R = new Bureaucrat("Maker", 20);
	}
	catch (std::exception &e) {
		std::cout << "Catched : " << e.what() << std::endl;
	}
	P->signForm(*Pform);
	S->signForm(*Sform);
	R->signForm(*Rform);

	P->executeForm(*Pform);
	S->executeForm(*Sform);
	R->executeForm(*Rform);
}

