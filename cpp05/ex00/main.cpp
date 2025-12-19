#include "Bureaucrat.hpp"

int main( void )
{
	try {

		Bureaucrat	A("aaaa", 50);
		Bureaucrat	B("bbbb", 150);

		B = A;
		A.demote(10);
		A.demote(10);
		A.demote(10);
		std::cout << A << std::endl;
		B.promote(10);
		B.promote(10);
		B.promote(10);
		std::cout << B << std::endl;
	}
	catch (std::exception &e) {

		std::cout << e.what() << std::endl;
	}
	return (0);
}
