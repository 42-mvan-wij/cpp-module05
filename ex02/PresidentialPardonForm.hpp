#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "Form.hpp"

class PresidentialPardonForm : public Form {
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(PresidentialPardonForm const &src);
		virtual ~PresidentialPardonForm();

		PresidentialPardonForm(std::string target);

		PresidentialPardonForm &operator=(PresidentialPardonForm const &rhs);

		virtual void execute(Bureaucrat const &executor) const;

	protected:
		std::string const target;
};

#endif
