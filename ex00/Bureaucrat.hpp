#ifndef  BUREAUCRAT_HPP
# define  BUREAUCRAT_HPP

#include <string>
class Bureaucrat {
	private:
		const std::string name;
		size_t	grade;
	public:
		Bureaucrat();
		Bureaucrat(const std::string &param, const size_t &num);
		Bureaucrat(const Bureaucrat &other);
		~Bureaucrat();
		void	operator=(const Bureaucrat &other);
		const std::string &getName(void) const;
		const size_t &getGrade(void) const;
		void	setGrade(const int &param);
		void	incrementGrade(void);
		void	decrementGrade(void);
		// Nested Classes for the Exceptions
		class GradeTooHighException: public std::exception {
			public:
				virtual const char *what() const throw(); // Throw or noexcept means th function
														  // will not throw any objects
		};

		class GradeTooLowException: public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

void	operator<<(std::ostream &st, const Bureaucrat &b);

#endif
