#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"
# include <string>

class Bureaucrat;

class AForm {
	public:
		AForm();
		AForm(AForm const &src);
		virtual ~AForm();

		AForm(std::string name, int sign_grade, int exec_grade);

		AForm &operator=(AForm const &rhs);

		class GradeTooHighException : public std::exception {
			public:
				char const * what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				char const * what() const throw();
		};

		class NotSignedException : public std::exception {
			public:
				char const * what() const throw();
		};

		virtual std::string const getName() const;
		virtual bool isSigned() const;
		virtual int getSignGrade() const;
		virtual int getExecGrade() const;

		virtual void beSigned(Bureaucrat const &bureaucrat);
		virtual void execute(Bureaucrat const &executor) const = 0;

	private:
		std::string const name;
		bool has_been_signed;
		int const sign_grade;
		int const exec_grade;
};

std::ostream &operator<<(std::ostream &ostream, AForm &form);
#endif
