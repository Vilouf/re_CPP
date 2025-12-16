#include "Bureaucrat.hpp"

int main( void )
{
	try {

		Bureaucrat	A("aaaa", 10);
		Bureaucrat	B("bbbb", 50);

		B = A;
		A.demote();
		A.demote();
		A.demote();
		std::cout << A << std::endl;
		B.promote();
		B.promote();
		B.promote();
		std::cout << B << std::endl;
	}
	catch (std::exception &e) {

		std::cout << e.what() << std::endl;
	}
	return (0);
}
