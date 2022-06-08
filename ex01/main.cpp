#include <iostream>
#include "Form.hpp"

#define YELLOW_FG "\e[33m"
#define RESET_COLOR "\e[0m"

__attribute__((destructor))
void check_leaks() {
	std::cout << std::endl;
	system("leaks -q bureaucrat-form");
}

int main() {
	Bureaucrat harry("Harry", 6);
	Form form("Test form", 5, 10);

	assert(form.getName() == "Test form");
	assert(form.isSigned() == false);
	assert(form.getSignGrade() == 5);
	assert(form.getExecGrade() == 10);

	std::cout << form << std::endl;

	try {
		form.beSigned(harry);
	} catch (Form::GradeTooHighException &e) {
		throw e;
	} catch (Form::GradeTooLowException &e) {
		std::cerr << "Expected error: " << e.what() << std::endl;
	}

	harry.incrementGrade();

	form.beSigned(harry);
	std::cout << form << std::endl;

	std::cout << std::endl << YELLOW_FG << "Should error because form is already signed" << RESET_COLOR << std::endl;
	harry.signForm(form);


	Form form2("Test form 2", 1, 1);
	std::cout << std::endl << YELLOW_FG << "Should error bureaucrat has a too low grade" << RESET_COLOR << std::endl;
	harry.signForm(form2);

	std::cout << std::endl;

	return (0);
}
