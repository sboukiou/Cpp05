#include "./Bureaucrat.hpp"
#include "Intern.hpp"
#include <iostream>

int main(void)
{
	Intern *intern = new Intern("David");
	AForm	*Pform = intern->makeForm("President", "PresidentialPardonForm" );
	AForm	*Sform = intern->makeForm("Farmer", "ShrubberyCreationForm");
	AForm	*Rform = intern->makeForm("Maker", "RobotomyRequestForm");
	
	
	

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
	std::cout << "\n----------------------\n";
	P->signForm(*Pform);
	std::cout << "\n----------------------\n";
	S->signForm(*Sform);
	std::cout << "\n----------------------\n";
	R->signForm(*Rform);
	std::cout << "\n----------------------\n";

	std::cout << "\n----------------------\n";
	P->executeForm(*Pform);
	std::cout << "\n----------------------\n";
	S->executeForm(*Sform);
	std::cout << "\n----------------------\n";
	R->executeForm(*Rform);
	std::cout << "\n----------------------\n";
}

