#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
class PresidentialPardonForm: public AForm {
	private:
		std::string	target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string &param);
		PresidentialPardonForm(const PresidentialPardonForm &other);
		~PresidentialPardonForm();
		void	operator=(const PresidentialPardonForm &other);

		const std::string	&getTarget(void) const;
		void				setTarget(const std::string &param);
		void				execute(const Bureaucrat &Ex) const;
};


#endif /* PRESIDENTIALPARDONFORM_HPP */
