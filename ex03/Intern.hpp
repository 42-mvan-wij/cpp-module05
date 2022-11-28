#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"

class Intern {
	public:
		Intern();
		Intern(Intern const &src);
		virtual ~Intern();

		Intern &operator=(Intern const &rhs);

		AForm *makeForm(std::string const name, std::string const target);
};

#endif
