#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
class ShrubberyCreationForm: public AForm {
	private:
		std::string	target;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string &param);
		ShrubberyCreationForm(const ShrubberyCreationForm &other);
		~ShrubberyCreationForm();
		void	operator=(const ShrubberyCreationForm &other);

		const std::string	&getTarget(void) const;
		void				setTarget(const std::string &param);
		void				execute(const Bureaucrat &Ex) const;
};


#endif /* SHRUBBERYCREATIONFORM_HPP */
