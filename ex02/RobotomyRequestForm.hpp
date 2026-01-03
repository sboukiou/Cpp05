#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm: public AForm {
	private:
		std::string target;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string &target);
		RobotomyRequestForm(const RobotomyRequestForm &other);
		~RobotomyRequestForm();
		void	operator=(const RobotomyRequestForm &other);
		const std::string	&getTarget(void) const;
		void				setTarget(const std::string &param);
		void				execute(const Bureaucrat &Ex) const;
};


#endif /* ROBOTOMYREQUESTFORM_HPP */
