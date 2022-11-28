#include <iostream>
#include <cstdlib>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

#define YELLOW_FG "\x1b[33m"
#define GREEN_FG "\x1b[32m"
#define RESET_COLOR "\x1b[0m"

void check_leaks() {
	std::cout << std::endl;
	std::system("leaks -q interns");
}

int main() {
	std::atexit(&check_leaks);
	Bureaucrat bureaucrat("Joe", 1);
	Intern intern;

	AForm *form = intern.makeForm("ShrubberyCreationForm", "house");
	assert(form->getName() == "ShrubberyCreationForm");
	assert(form->isSigned() == false);
	assert(form->getSignGrade() == 145);
	assert(form->getExecGrade() == 137);
	form->beSigned(bureaucrat);
	form->execute(bureaucrat);

	AForm *form2 = intern.makeForm("RobotomyRequestForm", "Will");
	assert(form2->getName() == "RobotomyRequestForm");
	assert(form2->isSigned() == false);
	assert(form2->getSignGrade() == 72);
	assert(form2->getExecGrade() == 45);
	form2->beSigned(bureaucrat);
	form2->execute(bureaucrat);

	AForm *form3 = intern.makeForm("PresidentialPardonForm", "Joe");
	assert(form3->getName() == "PresidentialPardonForm");
	assert(form3->isSigned() == false);
	assert(form3->getSignGrade() == 25);
	assert(form3->getExecGrade() == 5);
	form3->beSigned(bureaucrat);
	form3->execute(bureaucrat);

	std::cout << std::endl;

	delete form;
	delete form2;
	delete form3;

	return (0);
}
