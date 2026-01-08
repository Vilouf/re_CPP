#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main( void )
{
	std::srand(std::time(NULL));
	try {

		Bureaucrat	A("bob", 5);
		ShrubberyCreationForm	S("SSSSS");
		RobotomyRequestForm	R("RRRRR");
		PresidentialPardonForm	P("PPPPP");

		A.signForm(S);
		A.signForm(R);
		A.signForm(P);
		A.executeForm(S);
		A.executeForm(R);
		A.executeForm(P);
	}
	catch (std::exception &e) {

		std::cout << e.what() << std::endl;
	}
	return (0);
}
