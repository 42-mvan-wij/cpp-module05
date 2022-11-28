#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>

# define WORST_GRADE 150
# define BEST_GRADE 1

class Bureaucrat {
	private:
		Bureaucrat();

	public:
		Bureaucrat(Bureaucrat const &src);
		virtual ~Bureaucrat();

		Bureaucrat(std::string name, unsigned int grade);

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

	protected:
		std::string const name;
		unsigned int grade;
};

std::ostream &operator<<(std::ostream &ostream, Bureaucrat &bureaucrat);

#endif
