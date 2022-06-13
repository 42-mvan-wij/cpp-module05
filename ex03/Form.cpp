#include <iostream>
#include "Form.hpp"

Form::Form() :
	has_been_signed(false),
	sign_grade(150),
	exec_grade(150)
{
	std::cout << "Form::Form() called" << std::endl;
}

Form::Form(const Form &src) :
	name(src.name),
	has_been_signed(src.has_been_signed),
	sign_grade(src.sign_grade),
	exec_grade(src.exec_grade)
{
	std::cout << "Form::Form(const Form &) called" << std::endl;
	*this = src;
}

Form::~Form() {
	std::cout << "Form destructor called" << std::endl;
}

Form::Form(std::string name, int sign_grade, int exec_grade) :
	name(name),
	has_been_signed(false),
	sign_grade(sign_grade),
	exec_grade(exec_grade)
{
	if (sign_grade > 150)
		throw Form::GradeTooLowException();
	if (sign_grade < 1)
		throw Form::GradeTooHighException();
	if (exec_grade > 150)
		throw Form::GradeTooLowException();
	if (exec_grade < 1)
		throw Form::GradeTooHighException();
}

Form &Form::operator=(Form const &rhs) {
	has_been_signed = rhs.has_been_signed;
	return *this;
}

char const * Form::GradeTooHighException::what() const throw() {
	return "Grade too high";
}

char const * Form::GradeTooLowException::what() const throw() {
	return "Grade too low";
}

char const * Form::NotSignedException::what() const throw() {
	return "Form not signed";
}

std::string const Form::getName() const {
	return name;
}

bool Form::isSigned() const {
	return has_been_signed;
}

int Form::getSignGrade() const {
	return sign_grade;
}

int Form::getExecGrade() const {
	return exec_grade;
}

void Form::beSigned(Bureaucrat const &bureaucrat) {
	if (bureaucrat.getGrade() > sign_grade) {
		throw Form::GradeTooLowException();
	}
	has_been_signed = true;
}

void Form::execute(Bureaucrat const & executor) const {
	if (has_been_signed == false) {
		throw Form::NotSignedException();
	}
	if (executor.getGrade() > exec_grade) {
		throw Form::GradeTooLowException();
	}
}

std::ostream &operator <<(std::ostream &ostream, Form &form) {
	ostream << "Form <" << form.getName() << "> is_signed: " << (form.isSigned() ? "true" : "false") << ", sign_grade: " << form.getSignGrade() << ", exec_grade: " << form.getExecGrade() << ".";
	return ostream;
}
