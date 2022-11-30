#include <iostream>
#include "AForm.hpp"

AForm::AForm() :
	has_been_signed(false),
	sign_grade(WORST_GRADE),
	exec_grade(WORST_GRADE)
{
	std::cout << "Default AForm constructor called" << std::endl;
}

AForm::AForm(const AForm &src) :
	name(src.name),
	has_been_signed(src.has_been_signed),
	sign_grade(src.sign_grade),
	exec_grade(src.exec_grade)
{
	std::cout << "AForm copy constructor called" << std::endl;
	*this = src;
}

AForm::~AForm() {
	std::cout << "AForm destructor called" << std::endl;
}

AForm::AForm(std::string name, int sign_grade, int exec_grade) :
	name(name),
	has_been_signed(false),
	sign_grade(sign_grade),
	exec_grade(exec_grade)
{
	if (sign_grade > WORST_GRADE)
		throw AForm::GradeTooLowException();
	if (sign_grade < BEST_GRADE)
		throw AForm::GradeTooHighException();
	if (exec_grade > WORST_GRADE)
		throw AForm::GradeTooLowException();
	if (exec_grade < BEST_GRADE)
		throw AForm::GradeTooHighException();
}

AForm &AForm::operator=(AForm const &rhs) {
	if (this == &rhs)
		return *this;
	has_been_signed = rhs.has_been_signed;
	return *this;
}

char const * AForm::GradeTooHighException::what() const throw() {
	return "Grade too high";
}

char const * AForm::GradeTooLowException::what() const throw() {
	return "Grade too low";
}

char const * AForm::NotSignedException::what() const throw() {
	return "Form not signed";
}

std::string const AForm::getName() const {
	return name;
}

bool AForm::isSigned() const {
	return has_been_signed;
}

int AForm::getSignGrade() const {
	return sign_grade;
}

int AForm::getExecGrade() const {
	return exec_grade;
}

void AForm::beSigned(Bureaucrat const &bureaucrat) {
	if (bureaucrat.getGrade() > sign_grade) {
		throw AForm::GradeTooLowException();
	}
	has_been_signed = true;
}

void AForm::execute(Bureaucrat const &executor) const {
	if (has_been_signed == false) {
		throw AForm::NotSignedException();
	}
	if (executor.getGrade() > exec_grade) {
		throw AForm::GradeTooLowException();
	}
}

std::ostream &operator<<(std::ostream &ostream, AForm &form) {
	std::ostream::fmtflags before = ostream.setf(ostream.boolalpha);
	ostream << "Form <" << form.getName() << "> is_signed: " << form.isSigned() << ", sign_grade: " << form.getSignGrade() << ", exec_grade: " << form.getExecGrade() << ".";
	ostream.setf(before);
	return ostream;
}
