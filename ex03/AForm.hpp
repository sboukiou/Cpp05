#ifndef AFORM_HPP
# define AFORM_HPP

class Bureaucrat;
#include <string>

class AForm {
	private:
		// Attributes/Data members of the class (private)
		const std::string	name;
		bool				isSigned;
		const size_t		signGrade;
		const size_t		execGrade;
	public:
		// Orthodox Canonical AForm
		AForm();
		AForm(const std::string &other, const int signG, const int execG);
		AForm(const AForm &other);
		virtual ~AForm();
		void	operator=(const AForm &other);
		// Public getters and setter for isSigned.
		const std::string	getName() const;
		bool				getSignature() const;
		size_t				getSignGrade() const;
		size_t				getExecGrade() const;
		void				beSigned(const Bureaucrat &B);
		virtual void		execute(const Bureaucrat &Ex) const = 0;

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
		class FormNotSignedException: public std::exception {
			public:
				const char*	what() const throw();
		};
		class FormAlreadySignedException: public std::exception {
			public:
				const char*	what() const throw();
		};
};

// Overloading the << operator
void operator<<(std::ostream &st, const AForm &f);

#endif /*AFORM_HPP*/
