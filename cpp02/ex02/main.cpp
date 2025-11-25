#include "Fixed.hpp"

int main( void ) {
	
	Fixed a;
	Fixed const b( 5 );

	a = Fixed( 2.5f );

	std::cout << a + b << std::endl;
	std::cout << a - b << std::endl;
	std::cout << a * b << std::endl;
	std::cout << a / b << std::endl;
	std::cout << a << std::endl;

	return 0;
}
