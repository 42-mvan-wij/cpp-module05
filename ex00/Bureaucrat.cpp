#include <iostream>
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): grade(WORST_GRADE) {
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

std::ostream &operator<<(std::ostream &ostream, Bureaucrat &bureaucrat) {
	ostream << "bureaucrat name: " << bureaucrat.getName() << ", grade: " << bureaucrat.getGrade() << ".";
	return ostream;
}
