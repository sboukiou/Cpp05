#ifndef INTERN_HPP
# define INTERN_HPP

#include "./AForm.hpp"
#include <string>

class Intern {
	private:
		std::string name;
		AForm*	(*genericForm[3])(const std::string &target);
	public:
		Intern(void);
		Intern(const std::string &name);
		Intern(const Intern &other);
		~Intern(void);
		void	operator=(const Intern &other);
		AForm*	makeForm(const std::string &formName, const std::string &targetName);
		// Classes for Exceptions
		class FormNotFoundException: public std::exception {
			public:
				const char*	what() const throw();
		};

};

#endif /* INTERN_HPP */
