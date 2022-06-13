#include <iostream>
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {
	std::cout << "Bureaucrat::Bureaucrat() called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : name(src.name), grade(src.grade) {
	std::cout << "Bureaucrat::Bureaucrat(const Bureaucrat &) called" << std::endl;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name) {
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade = grade;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs) {
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
	if (grade <= 1) {
		throw GradeTooHighException();
	}
	--grade;
}

void Bureaucrat::decrementGrade() {
	if (grade >= 150) {
		throw GradeTooLowException();
	}
	++grade;
}

void Bureaucrat::signForm(Form &form) const {
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

void Bureaucrat::executeForm(Form const &form) const {
	try {
		form.execute(*this);
	} catch (std::exception &e) {
		std::cout << getName() << " couldn't execute " << form.getName() << " because: " << e.what() << std::endl;
		return ;
	}
	std::cout << getName() << " executed " << form.getName() << std::endl;
}

std::ostream &operator <<(std::ostream &ostream, Bureaucrat &bureaucrat) {
	ostream << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return ostream;
}
