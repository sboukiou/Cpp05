#include <iostream>
#include "./Bureaucrat.hpp"
#include "Form.hpp"

void testBasicFunc(void) {
	std::cout << "\n\n##############################\n";
	Bureaucrat lilJeffy;
	Bureaucrat MadKing("MadKing", 88);
	Bureaucrat copyKing(MadKing);

	std::cout << "\nNames :\n";
	std::cout << "----------------\n";
	std::cout << lilJeffy.getName() << std::endl;
	std::cout << MadKing.getName() << std::endl;
	std::cout << copyKing.getName() << std::endl;
	std::cout << "\n----------------\n";

	std::cout << "\nGrades :\n";
	std::cout << "----------------\n";
	std::cout << lilJeffy.getGrade() << std::endl;
	std::cout << MadKing.getGrade() << std::endl;
	std::cout << copyKing.getGrade() << std::endl;
	std::cout << "\n----------------\n";
	std::cout << "##############################\n";


}



void testErrorCatch(void) {
	std::cout << "\n\n##############################\n";
	Bureaucrat lilCatch;
	Bureaucrat madThrow("madThrow", 88);
	Bureaucrat copyMad(madThrow);

	std::cout << "\nData :\n";
	std::cout << "----------------\n";
	std::cout << lilCatch;
	std::cout << madThrow;
	std::cout << copyMad;
	std::cout << "\n----------------\n";


	std::cout << "\nsetting wrong Grades :\n";
	std::cout << "----------------\n";
	try
	{
		lilCatch.setGrade(999);
	}
	catch (std::exception & e)
	{
		std::cout << "Catched: " << e.what() << std::endl; 
		std::cout
			<< "Tired to set a grade of "
			<< lilCatch.getGrade()
			<< "to the value: "
			<< 999 << std::endl;
	}
	try
	{
		madThrow.setGrade(-999);
	}
	catch (std::exception & e)
	{
		std::cout << "Catched: " << e.what() << std::endl;
		std::cout
			<< "Tired to set a grade of "
			<< madThrow.getGrade()
			<< "to the value: "
			<< -999 << std::endl;
	}

	std::cout << "\n----------------\n";
	std::cout << "##############################\n";

}

void	testOstreamOverload(void) {
	Bureaucrat DadUser("Dad", 0);
	Bureaucrat MomUser("Mom", 0);
	Bureaucrat ChildUser("Child", 0);

	std::cout << DadUser;
	std::cout << MomUser;
	std::cout << ChildUser;
}


void	testFormClass() {

	Bureaucrat Agent("Allal", 5);
	Bureaucrat fakeAgent("Lmadani", 100);
	Form Id("Id", 12, 12);
	Form driverLicense("D-License", 12, 12);
	std::cout << "Forms:\n";
	std::cout << Id;
	std::cout << driverLicense;
	std::cout << "Bureaucrats:\n";
	std::cout << Agent;
	std::cout << fakeAgent;
	std::cout << "\n------------\n";
	Agent.signForm(Id);
	fakeAgent.signForm(driverLicense);



}


int main(void) {

	// testBasicFunc();
	// testErrorCatch();
	// testOstreamOverload();
	testFormClass();

	return (0);
}
