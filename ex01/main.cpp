#include <iostream>
#include <cstdlib>
#include <cassert>
#include "Form.hpp"

#define RED_FG "\x1b[31m"
#define YELLOW_FG "\x1b[33m"
#define GREEN_FG "\x1b[32m"
#define RESET_COLOR "\x1b[0m"

void check_leaks() {
	std::cout << std::endl;
	std::system("leaks -q bureaucrat-form");
}

int main() {
	std::atexit(&check_leaks);
	Bureaucrat harry("Harry", 6);
	Form form("Test form", 5, 10);

	assert(form.getName() == "Test form");
	assert(form.isSigned() == false);
	assert(form.getSignGrade() == 5);
	assert(form.getExecGrade() == 10);

	std::cout << "1. " << form << std::endl;

	try {
		form.beSigned(harry);
		std::cerr << RED_FG << "Expected some error" << RESET_COLOR << std::endl;
	} catch (Form::GradeTooLowException &e) {
		std::cerr << "2. " << GREEN_FG << "Expected error: " << RESET_COLOR << e.what() << std::endl;
	} catch (std::exception &e) {
		std::cerr << RED_FG << "Unexpected error: " << RESET_COLOR << e.what() << std::endl;
		throw e;
	}

	harry.incrementGrade();

	form.beSigned(harry);
	std::cout << "3. " << form << std::endl;
	std::cout << std::endl;

	std::cout << "4. " << YELLOW_FG << "Should error because form is already signed" << RESET_COLOR << std::endl << "   ";
	harry.signForm(form);
	std::cout << std::endl;


	Form form2("Test form 2", 1, 1);
	std::cout << "5. " << YELLOW_FG << "Should error bureaucrat has a too low grade" << RESET_COLOR << std::endl << "   ";
	harry.signForm(form2);
	std::cout << std::endl;


	try {
		Form form3("Test form 3", 151, 70);
		std::cerr << RED_FG << "Expected some error" << RESET_COLOR << std::endl;
	} catch (Form::GradeTooLowException &e) {
		std::cerr << "6. " << GREEN_FG << "Expected error: " << RESET_COLOR << e.what() << std::endl;
	} catch (std::exception &e) {
		std::cerr << RED_FG << "Unexpected error: " << RESET_COLOR << e.what() << std::endl;
		throw e;
	}

	try {
		Form form4("Test form 4", 0, 70);
		std::cerr << RED_FG << "Expected some error" << RESET_COLOR << std::endl;
	} catch (Form::GradeTooHighException &e) {
		std::cerr << "7. " << GREEN_FG << "Expected error: " << RESET_COLOR << e.what() << std::endl;
	} catch (std::exception &e) {
		std::cerr << RED_FG << "Unexpected error: " << RESET_COLOR << e.what() << std::endl;
		throw e;
	}

	try {
		Form form5("Test form 5", 70, 151);
		std::cerr << RED_FG << "Expected some error" << RESET_COLOR << std::endl;
	} catch (Form::GradeTooLowException &e) {
		std::cerr << "8. " << GREEN_FG << "Expected error: " << RESET_COLOR << e.what() << std::endl;
	} catch (std::exception &e) {
		std::cerr << RED_FG << "Unexpected error: " << RESET_COLOR << e.what() << std::endl;
		throw e;
	}

	try {
		Form form6("Test form 6", 70, 0);
		std::cerr << RED_FG << "Expected some error" << RESET_COLOR << std::endl;
	} catch (Form::GradeTooHighException &e) {
		std::cerr << "9. " << GREEN_FG << "Expected error: " << RESET_COLOR << e.what() << std::endl;
	} catch (std::exception &e) {
		std::cerr << RED_FG << "Unexpected error: " << RESET_COLOR << e.what() << std::endl;
		throw e;
	}

	std::cout << std::endl;

	return (0);
}
