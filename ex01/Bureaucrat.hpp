#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include "Form.hpp"
# include <string>

class Form;

class Bureaucrat {
	public:
		Bureaucrat();
		Bureaucrat(Bureaucrat const &src);
		virtual ~Bureaucrat();

		Bureaucrat(std::string name, int grade);

		Bureaucrat &operator=(Bureaucrat const &rhs);

		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};

		std::string const getName() const;
		int getGrade() const;
		void incrementGrade();
		void decrementGrade();

		void signForm(Form &form);

	protected:
		std::string const name;
		int grade;
};

std::ostream &operator <<(std::ostream &ostream, Bureaucrat &bureaucrat);

#endif
