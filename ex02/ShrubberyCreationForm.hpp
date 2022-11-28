#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
	private:
		ShrubberyCreationForm();

	public:
		ShrubberyCreationForm(ShrubberyCreationForm const &src);
		virtual ~ShrubberyCreationForm();

		ShrubberyCreationForm(std::string target);

		ShrubberyCreationForm &operator=(ShrubberyCreationForm const &rhs);

		virtual void execute(Bureaucrat const &executor) const;

	protected:
		std::string const target;
};

#endif
