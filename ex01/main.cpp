#include <iostream>
#include "./Bureaucrat.hpp"

void testFormsBureaucrats(void) {
	std::cout << "----------------Testing Basic Initializations---------------\n";
		Form	*EmptyForm = new Form();
		Form *idForm = NULL;
		try {
			idForm = new Form("IdForm", 138, 1100);
		}
		catch (Form::GradeTooHighException &e) {
			std::cout << "[CATCH]: "<< e.what() << std::endl;
			delete idForm;
			idForm = new Form("IdForm", 0, 100);
		}
		catch (Form::GradeTooLowException &e) {
			std::cout << "[CATCH]: "<< e.what() << std::endl;
			delete idForm;
			idForm = new Form("IdForm", 138, 100);
		}
	Form	*idFormRetry = new Form(*idForm);
	try {
		*EmptyForm = *idForm;
	}
	catch (Form::AssignToConstException &e) {
			std::cout << "[CATCH]: "<< e.what() << std::endl;
	}


	Bureaucrat *CouncelAgent = new Bureaucrat("Councel-Agent", 100);
	Bureaucrat *fakeAgent = new Bureaucrat("fake-Agent", 150);

	std::cout << *EmptyForm;
	std::cout << std::endl;
	std::cout << *idForm;
	std::cout << std::endl;
	std::cout << *idFormRetry;
	std::cout << std::endl;
	std::cout << *CouncelAgent;
	std::cout << std::endl;





	std::cout << "\n\n\n----------------Testing Forms Signing---------------\n";

	std::cout << "Trying to sign with low grade BT:\n";
	fakeAgent->signForm(*idFormRetry);
	std::cout << "-------------\n";
	std::cout << "Trying to sign with valid grade BT:\n";
	CouncelAgent->signForm(*idForm);
	std::cout << "-------------\n";
	std::cout << "Trying to sign already signed form with valid grade BT:\n";
	CouncelAgent->signForm(*idForm);
	std::cout << "-------------\n";
	std::cout << "Trying to sign already signed form with low grade BT:\n";
	fakeAgent->signForm(*idForm);
	std::cout << "-------------\n";


	delete idForm;
	delete EmptyForm;
	delete idFormRetry;
	delete  CouncelAgent;
}



int main(void) {

	testFormsBureaucrats();

	return (0);
}
