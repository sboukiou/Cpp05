#ifndef FORM_HPP
# define FORM_HPP

class Bureaucrat;
#include <string>

class Form {
	private:
		// Attributes/Data members of the class (private)
		const std::string	name;
		bool				isSigned;
		const size_t		signGrade;
		const size_t		execGrade;
	public:
		// Orthodox Canonical Form
		Form();
		Form(const std::string &other, const int signG, const int execG);
		Form(const Form &other);
		~Form();
		void	operator=(const Form &other);
		// Public getters and setter for isSigned.
		const std::string	getName() const;
		bool				getSignature() const;
		size_t		getSignGrade() const;
		size_t		getExecGrade() const;
		void				beSigned(const Bureaucrat &B);

		// Nested Exceptions derived classes
		class GradeTooHighException: public std::exception {
			public:
				const char*	what() const throw();
		};
		class GradeTooLowException: public std::exception {
			public:
				const char*	what() const throw();
		};
		class AssignToConstException: public std::exception {
			public:
				const char*	what() const throw();
		};
};

// Overloading the << operator
void operator<<(std::ostream &st, const Form &f);

#endif /*FORM_HPP*/
