#ifndef INTERN_HPP
# define INTERN_HPP

#include "./AForm.hpp"
#include <string>

class Intern {
	private:
		std::string name;
	public:
		Intern(void);
		Intern(const std::string &name);
		Intern(const Intern &other);
		~Intern(void);
		void	operator=(const Intern &other);
		AForm*	makeForm(const std::string &formName, const std::string &targetName);

};

#endif /* INTERN_HPP */
