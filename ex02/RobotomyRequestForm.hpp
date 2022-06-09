#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "Form.hpp"

class RobotomyRequestForm : public Form {
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(RobotomyRequestForm const &src);
		virtual ~RobotomyRequestForm();

		RobotomyRequestForm(std::string target);

		RobotomyRequestForm &operator=(RobotomyRequestForm const &rhs);

		virtual void execute(Bureaucrat const &executor) const;

	protected:
		std::string const target;
};

#endif
