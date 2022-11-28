#include <iostream>
#include "Form.hpp"

Form::Form() :
	has_been_signed(false),
	sign_grade(WORST_GRADE),
	exec_grade(WORST_GRADE)
{
	std::cout << "Default Form constructor called" << std::endl;
}

Form::Form(const Form &src) :
	name(src.name),
	has_been_signed(src.has_been_signed),
	sign_grade(src.sign_grade),
	exec_grade(src.exec_grade)
{
	std::cout << "Form copy constructor called" << std::endl;
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
	if (sign_grade > WORST_GRADE)
		throw Form::GradeTooLowException();
	if (sign_grade < BEST_GRADE)
		throw Form::GradeTooHighException();
	if (exec_grade > WORST_GRADE)
		throw Form::GradeTooLowException();
	if (exec_grade < BEST_GRADE)
		throw Form::GradeTooHighException();
}

Form &Form::operator=(Form const &rhs) {
	if (this == &rhs)
		return *this;
	has_been_signed = rhs.has_been_signed;
	return *this;
}

char const * Form::GradeTooHighException::what() const throw() {
	return "Grade too high";
}

char const * Form::GradeTooLowException::what() const throw() {
	return "Grade too low";
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

void Form::beSigned(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > sign_grade) {
		throw Form::GradeTooLowException();
	}
	has_been_signed = true;
}

std::ostream &operator<<(std::ostream &ostream, Form &form) {
	std::ostream::fmtflags before = ostream.setf(ostream.boolalpha);
	ostream << "Form <" << form.getName() << "> is_signed: " << form.isSigned() << ", sign_grade: " << form.getSignGrade() << ", exec_grade: " << form.getExecGrade() << ".";
	ostream.setf(before);
	return ostream;
}
