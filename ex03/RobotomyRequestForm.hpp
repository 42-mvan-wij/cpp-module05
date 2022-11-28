#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm : public AForm {
	private:
		RobotomyRequestForm();

	public:
		RobotomyRequestForm(RobotomyRequestForm const &src);
		virtual ~RobotomyRequestForm();

		RobotomyRequestForm(std::string target);

		RobotomyRequestForm &operator=(RobotomyRequestForm const &rhs);

		virtual void execute(Bureaucrat const &executor) const;

	protected:
		std::string const target;
};

#endif
