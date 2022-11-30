#include <iostream>
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : grade(WORST_GRADE) {
	std::cout << "Default Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : name(src.name), grade(src.grade) {
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, unsigned int grade) : name(name), grade(grade) {
	if (grade < BEST_GRADE)
		throw Bureaucrat::GradeTooHighException();
	if (grade > WORST_GRADE)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs) {
	if (this == &rhs)
		return *this;
	grade = rhs.grade;
	return *this;
}

char const * Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade too high";
}

char const * Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade too low";
}

std::string const Bureaucrat::getName() const {
	return name;
}

int Bureaucrat::getGrade() const {
	return grade;
}

void Bureaucrat::incrementGrade() {
	if (grade <= BEST_GRADE) {
		throw GradeTooHighException();
	}
	--grade;
}

void Bureaucrat::decrementGrade() {
	if (grade >= WORST_GRADE) {
		throw GradeTooLowException();
	}
	++grade;
}

void Bureaucrat::signForm(AForm &form) const {
	if (form.isSigned()) {
		std::cout << getName() << " couldn't sign " << form.getName() << " because: " << "Form is already signed" << std::endl;
		return ;
	}
	try {
		form.beSigned(*this);
	} catch (std::exception &e) {
		std::cout << getName() << " couldn't sign " << form.getName() << " because: " << e.what() << std::endl;
		return ;
	}
	std::cout << getName() << " signed " << form.getName() << std::endl;
}

void Bureaucrat::executeForm(AForm const &form) const {
	try {
		form.execute(*this);
	} catch (std::exception &e) {
		std::cout << getName() << " couldn't execute " << form.getName() << " because: " << e.what() << std::endl;
		return ;
	}
	std::cout << getName() << " executed " << form.getName() << std::endl;
}

std::ostream &operator<<(std::ostream &ostream, Bureaucrat &bureaucrat) {
	ostream << "Bureaucrat name: " << bureaucrat.getName() << ", grade: " << bureaucrat.getGrade() << ".";
	return ostream;
}
