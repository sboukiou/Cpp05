#include <iostream>
#include "./Bureaucrat.hpp"

void testBasicFunc(void) {
	std::cout << "\n\n##############################\n";
	Bureaucrat lilJeffy;
	lilJeffy.setName("lilJeffy");
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
	lilCatch.setName("lilCatch");
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
		lilCatch.setGrade(-999);
	}
	catch (std::exception & e)
	{
		std::cout << "Catched: " << e.what() << std::endl; 
	}
	try
	{
		madThrow.setGrade(-999);
	}
	catch (std::exception & e)
	{
		std::cout << "Catched: " << e.what() << std::endl;
	}

	std::cout << "\n----------------\n";
	std::cout << "##############################\n";

}


int main(void) {

	testBasicFunc();
	testErrorCatch();

	return (0);
}
