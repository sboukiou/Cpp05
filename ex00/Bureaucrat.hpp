#ifndef  BUREAUCRAT_HPP
# define  BUREAUCRAT_HPP

#include <string>
class Bureaucrat {
	private:
		std::string name;
		unsigned int grade;
	public:
		Bureaucrat();
		Bureaucrat(const std::string &param, const unsigned int &num);
		Bureaucrat(const Bureaucrat &other);
		~Bureaucrat();
		void	operator=(const Bureaucrat &other);
		const std::string &getName(void) const;
		void	setName(const std::string &param);
		const unsigned int &getGrade(void) const;
		void	setGrade(const unsigned int &param);
		void	incrementGrade(void);
		void	decrementGrade(void);
		// Nested Classes for the Exceptions
		class GradeTooHighException: public std::exception {
			public:
				virtual const char *what() const throw();
		};


		class GradeTooLowException: public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

void	operator<<(std::ostream &st, const Bureaucrat &b);

#endif
