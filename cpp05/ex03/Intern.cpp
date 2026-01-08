#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern( const Intern &other ) {

	(void) other;
}

Intern	&Intern::operator=( const Intern &other ) {

	(void) other;
	return *this;
}

Intern::~Intern() {}

AForm	*Shrubbery( const std::string target ) { return new ShrubberyCreationForm(target);}
AForm	*Robotomy( const std::string target ) { return new RobotomyRequestForm(target);}
AForm	*Presidential( const std::string target ) { return new PresidentialPardonForm(target);}

AForm	*Intern::makeForm( const std::string &form, const std::string &target ) const {

	AForm	*(*ptr[3])( const std::string ) = { &Shrubbery, &Robotomy, &Presidential };
	std::string	strtab[3] = { "shrubbery request", "robotomy request", "presidential request" };
	AForm	*F;
	for (int i = 0; i < 4; i++) {

		if (form == strtab[i]) {

			F = (*ptr[i])(target);
			std::cout << "Intern creates " << *F << std::endl;
			return F;
		}
	}
	std::cout << "No form found for '" << form << "'" << std::endl;
	return NULL;
}
