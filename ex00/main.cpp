#include <iostream>
#include <cstdlib>
#include <cassert>
#include "Bureaucrat.hpp"

void check_leaks() {
	std::cout << std::endl;
	std::system("leaks -q bureaucrat");
}

int main() {
	std::atexit(&check_leaks);
	Bureaucrat harry("Harry", 2);

	assert(harry.getName() == "Harry");
	assert(harry.getGrade() == 2);

	std::cout << harry << std::endl;

	harry.incrementGrade();
	assert(harry.getGrade() == 1);

	std::cout << harry << std::endl;

	try {
		harry.incrementGrade();
	} catch (Bureaucrat::GradeTooLowException &e) {
		std::cerr << "Unreachable" << std::endl;
	} catch (Bureaucrat::GradeTooHighException &e) {
		std::cerr << "Expected error: " << e.what() << std::endl;
	}

	Bureaucrat bob("Bob", 149);

	assert(bob.getName() == "Bob");
	assert(bob.getGrade() == 149);

	std::cout << bob << std::endl;

	bob.decrementGrade();
	assert(bob.getGrade() == 150);

	std::cout << bob << std::endl;

	try {
		bob.decrementGrade();
	} catch (Bureaucrat::GradeTooHighException &e) {
		std::cerr << "Unreachable" << std::endl;
	} catch (Bureaucrat::GradeTooLowException &e) {
		std::cerr << "Expected error: " << e.what() << std::endl;
	}

	std::cout << std::endl;

	return (0);
}
