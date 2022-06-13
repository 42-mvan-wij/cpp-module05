#include <iostream>
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form("PresidentialPardonForm", 25, 5) {
	std::cout << "PresidentialPardonForm::PresidentialPardonForm() called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) {
	std::cout << "PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &) called" << std::endl;
	*this = src;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("PresidentialPardonForm", 25, 5), target(target) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs) {
	Form::operator=(rhs);
	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
	Form::execute(executor);
	std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
