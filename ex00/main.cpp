#include <iostream>
#include "./Bureaucrat.hpp"

void testBasicFunc(void) {
	std::cout << "\n\n############ Testing Basic functions of the Bureacrat ##################\n";
	Bureaucrat *lilJeffy = new Bureaucrat();;
	Bureaucrat *MadKing = new Bureaucrat("MadKing", 88);
	Bureaucrat *copyKing = new Bureaucrat(*MadKing);

	std::cout << "\nNames :\n";
	std::cout << "----------------\n";
	std::cout << lilJeffy->getName() << std::endl;
	std::cout << MadKing->getName() << std::endl;
	std::cout << copyKing->getName() << std::endl;
	std::cout << "\n----------------\n";

	std::cout << "\nGrades :\n";
	std::cout << "----------------\n";
	std::cout << lilJeffy->getGrade() << std::endl;
	std::cout << MadKing->getGrade() << std::endl;
	std::cout << copyKing->getGrade() << std::endl;
	delete lilJeffy;
	delete MadKing;
	delete copyKing;
	std::cout << "\n----------------\n";
	std::cout << "##############################\n";


}



void testErrorCatch(void) {
	std::cout << "\n\n############ Testing the Exceptions throwing and Catching ##################\n";
	Bureaucrat *lilCatch = new Bureaucrat();
	Bureaucrat *madThrow = new Bureaucrat("madThrow", 88);
	Bureaucrat *copyMad =  new Bureaucrat(*madThrow);

	std::cout << "\nData :\n";
	std::cout << "----------------\n";
	std::cout << *lilCatch;
	std::cout << std::endl;
	std::cout << *madThrow;
	std::cout << std::endl;
	std::cout << *copyMad;
	std::cout << std::endl;
	std::cout << "\n----------------\n";


	std::cout << "\nsetting wrong Grades :\n";
	std::cout << "----------------\n";
	try
	{
		lilCatch->setGrade(999);
	}
	catch (std::exception & e)
	{
		std::cout << "Catched: " << e.what() << std::endl; 
		std::cout
			<< "Tried to set a grade of {"
			<< 999
			<< "} to the value: "
			<< lilCatch->getGrade() << std::endl;
	}
	try
	{
		madThrow->setGrade(-999);
	}
	catch (std::exception & e)
	{
		std::cout << "Catched: " << e.what() << std::endl;
		std::cout
			<< "Tried to set a grade of {"
			<< -999
			<< "} to the value: "
			<< madThrow->getGrade() << std::endl;
	}

	std::cout << *lilCatch;
	std::cout << std::endl;
	std::cout << *madThrow;
	std::cout << std::endl;
	std::cout << *copyMad;
	std::cout << std::endl;
	std::cout << "\n----------------\n";
	std::cout << "##############################\n";

}

void	testOstreamOverload(void) {
	std::cout << "\n\n############ Testing the O-stream overloading ##################\n";
	Bureaucrat *DadUser = new Bureaucrat("Dad", 0);
	Bureaucrat *MomUser = new Bureaucrat("Mom", 0);
	Bureaucrat *ChildUser = new Bureaucrat("Child", 0);

	std::cout << *DadUser;
	std::cout << *MomUser;
	std::cout << *ChildUser;
	delete DadUser;
	delete MomUser;
	delete ChildUser;
	std::cout << "\n----------------\n";
	std::cout << "##############################\n";
}



int main(void) {

	testBasicFunc();
	testErrorCatch();
	testOstreamOverload();

	return (0);
}
