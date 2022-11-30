#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"
# include <string>

class Bureaucrat;

class Form {
	public:
		Form();
		Form(Form const &src);
		virtual ~Form();

		Form(std::string name, int sign_grade, int exec_grade);

		Form &operator=(Form const &rhs);

		class GradeTooHighException : public std::exception {
			public:
				char const * what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				char const * what() const throw();
		};

		std::string const getName() const;
		bool isSigned() const;
		int getSignGrade() const;
		int getExecGrade() const;

		void beSigned(Bureaucrat const &bureaucrat);

	private:
		std::string const name;
		bool has_been_signed;
		int const sign_grade;
		int const exec_grade;
};

std::ostream &operator<<(std::ostream &ostream, Form &form);
#endif
