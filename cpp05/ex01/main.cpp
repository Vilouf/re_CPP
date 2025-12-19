#include "Bureaucrat.hpp"

int main( void )
{
	try {

		Bureaucrat	A("aaaa", 50);
		Form	F("TestForm", 50, 10);

		A.signForm(&F);
		A.signForm(&F);
	}
	catch (std::exception &e) {

		std::cout << e.what() << std::endl;
	}
	return (0);
}
