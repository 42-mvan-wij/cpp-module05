#include <iostream>
#include <fstream>
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137) {
	std::cout << "Default ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm(src), target(src.target) {
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), target(target) {
	std::cout << "ShrubberyCreationForm(std::string) constructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs) {
	if (this == &rhs)
		return *this;
	AForm::operator=(rhs);
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	AForm::execute(executor);
	std::ofstream file((target + "_shrubbery").c_str());
	file
		<< "            ,@@@@@@@," << std::endl
		<< "    ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl
		<< " ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl
		<< ",%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl
		<< "%&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl
		<< "%&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl
		<< "`&%\\ ` /%&'    |.|        \\ '|8'" << std::endl
		<< "    |o|        | |         | |" << std::endl
		<< "    |.|        | |         | |" << std::endl
		<< " \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_" << std::endl;
	file.close();
}
