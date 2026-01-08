#include "Intern.hpp"

int main( void )
{
	std::srand(std::time(NULL));
	Intern someRandomIntern;
	AForm* Form;
	Form = someRandomIntern.makeForm("shrubbery request", "Bender");

	try {

		Bureaucrat	B("bob", 5);

		if (Form) {

			B.signForm(*Form);
			B.executeForm(*Form);
		}
	}
	catch (std::exception &e) {

		std::cout << e.what() << std::endl;
	}
	if (Form)
		delete Form;
	return (0);
}
