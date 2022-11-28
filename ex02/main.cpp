#include <iostream>
#include <cstdlib>
#include <cassert>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#define YELLOW_FG "\x1b[33m"
#define GREEN_FG "\x1b[32m"
#define RESET_COLOR "\x1b[0m"

void check_leaks() {
	std::cout << std::endl;
	std::system("leaks -q more-forms");
}

int main() {
	std::atexit(&check_leaks);
	Bureaucrat intern("Intern", 150);
	Bureaucrat shrub_signer("Shrub signer", 140);
	Bureaucrat shrub_exec("Shrub executor", 100);
	Bureaucrat robot_signer("Robot signer", 50);
	Bureaucrat robot_exec("Robot executor", 40);
	Bureaucrat pres_signer("President signer", 20);
	Bureaucrat pres_exec("President executor", 3);

	// Shrubbery Creation Form
	{
		ShrubberyCreationForm form("home");

		assert(form.getName() == "ShrubberyCreationForm");
		assert(form.isSigned() == false);
		assert(form.getSignGrade() == 145);
		assert(form.getExecGrade() == 137);

		try {
			form.beSigned(intern);
		} catch (AForm::GradeTooLowException &e) {
			std::cerr << "1. " << GREEN_FG << "Expected error: " << RESET_COLOR << e.what() << std::endl << "   ";
		}
		intern.signForm(form);

		try {
			form.execute(shrub_exec);
		} catch (AForm::NotSignedException &e) {
			std::cerr << "2. " << GREEN_FG << "Expected error: " << RESET_COLOR << e.what() << std::endl << "   ";
		}
		shrub_exec.executeForm(form);

		std::cout << "3. "; shrub_signer.signForm(form);

		try {
			form.execute(shrub_signer);
		} catch (AForm::GradeTooLowException &e) {
			std::cerr << "4. " << GREEN_FG << "Expected error: " << RESET_COLOR << e.what() << std::endl << "   ";
		}
		shrub_signer.executeForm(form);

		std::cout << "5. "; shrub_exec.executeForm(form);

		std::cout << std::endl;
	}

	// Robotomy Request Form
	{
		RobotomyRequestForm form("The intern");

		assert(form.getName() == "RobotomyRequestForm");
		assert(form.isSigned() == false);
		assert(form.getSignGrade() == 72);
		assert(form.getExecGrade() == 45);

		std::cout << "6. "; robot_signer.signForm(form); std::cout << std::endl;

		std::cout << "7. "; robot_exec.executeForm(form); std::cout << std::endl;
		std::cout << "8. "; robot_exec.executeForm(form); std::cout << std::endl;
		std::cout << "9. "; robot_exec.executeForm(form); std::cout << std::endl;
		std::cout << "10. "; robot_exec.executeForm(form); std::cout << std::endl;
		std::cout << "11. "; robot_exec.executeForm(form); std::cout << std::endl;
		std::cout << "12. "; robot_exec.executeForm(form); std::cout << std::endl;
		std::cout << "13. "; robot_exec.executeForm(form); std::cout << std::endl;

		std::cout << std::endl;
	}

	// Presidential Pardon Form
	{
		PresidentialPardonForm form("Zaphod Beeblebrox");

		assert(form.getName() == "PresidentialPardonForm");
		assert(form.isSigned() == false);
		assert(form.getSignGrade() == 25);
		assert(form.getExecGrade() == 5);

		std::cout << "14. "; pres_signer.signForm(form); std::cout << std::endl;
		std::cout << "15. "; pres_exec.executeForm(form); std::cout << std::endl;

		std::cout << std::endl;
	}

	std::cout << std::endl;

	return (0);
}
