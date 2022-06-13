#include <iostream>
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form("RobotomyRequestForm", 72, 45) {
	std::cout << "RobotomyRequestForm::RobotomyRequestForm() called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) {
	std::cout << "RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &) called" << std::endl;
	*this = src;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("RobotomyRequestForm", 72, 45), target(target) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs) {
	Form::operator=(rhs);
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
	Form::execute(executor);
	if (rand() % 100 >= 50) {
		std::cout << target << " was successfully robotomized." << std::endl;
	} else {
		std::cout << target << " was unsuccessfully robotomized." << std::endl;
	}
}
