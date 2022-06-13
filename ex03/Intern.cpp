#include <iostream>
#include "Intern.hpp"

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {
	std::cout << "Intern::Intern() called" << std::endl;
}

Intern::Intern(const Intern &src) {
	std::cout << "Intern::Intern(const Intern &) called" << std::endl;
	*this = src;
}

Intern::~Intern() {
	std::cout << "Intern destructor called" << std::endl;
}

Intern &Intern::operator=(Intern const &rhs) {
	(void)rhs;
	return *this;
}

template<typename T>
Form *createFormInstance(std::string const target) {
	return new T(target);
}

#define N_FORMS 3

Form *Intern::makeForm(std::string const form_name, std::string const target) {
	std::string arr[N_FORMS] = { "ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm" };
	Form* (*arr2[N_FORMS])(std::string const) = { createFormInstance<ShrubberyCreationForm>, createFormInstance<RobotomyRequestForm>, createFormInstance<PresidentialPardonForm> };
	for (int i = 0; i < N_FORMS; i++) {
		if (arr[i] == form_name) {
			std::cout << "Intern creates form \"" << form_name << "\"" << std::endl;
			return arr2[i](target);
		}
	}
	std::cout << "Intern could not create form \"" << form_name << "\"" << std::endl;
	return nullptr;
}
