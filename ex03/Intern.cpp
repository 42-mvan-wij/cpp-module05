#include <iostream>
#include "Intern.hpp"

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {
	std::cout << "Default Intern constructor called" << std::endl;
}

Intern::Intern(const Intern &src) {
	std::cout << "Intern copy constructor called" << std::endl;
	*this = src;
}

Intern::~Intern() {
	std::cout << "Intern destructor called" << std::endl;
}

Intern &Intern::operator=(Intern const &rhs) {
	if (this == &rhs)
		return *this;
	return *this;
}

template<typename T>
AForm *createForm(std::string const target) {
	return new T(target);
}

AForm *Intern::makeForm(std::string const form_name, std::string const target) {
	std::string form_names[] = {
		"ShrubberyCreationForm",
		"RobotomyRequestForm",
		"PresidentialPardonForm"
	};
	AForm *(*form_creator[])(std::string const) = {
		createForm<ShrubberyCreationForm>,
		createForm<RobotomyRequestForm>,
		createForm<PresidentialPardonForm>
	};

	for (unsigned int i = 0; i < (sizeof(form_names) / sizeof(*form_names)); i++) {
		if (form_names[i] == form_name) {
			std::cout << "Intern creates form \"" << form_name << "\"" << std::endl;
			return form_creator[i](target);
		}
	}
	std::cout << "Intern could not create form \"" << form_name << "\"" << std::endl;
	return NULL;
}
