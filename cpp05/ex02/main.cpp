#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main( void )
{
	try {

		Bureaucrat	A("aaaa", 5);
		Bureaucrat	B(A);
		PresidentialPardonForm	F("test1");
		PresidentialPardonForm	H("test2");

		A.signForm(&F);
		A.signForm(&F);
		B.signForm(&F);
		std::cout << H.getTarget() << std::endl;
		B.signForm(&H);
	}
	catch (std::exception &e) {

		std::cout << e.what() << std::endl;
	}
	return (0);
}
