#include "Point.hpp"

int main( void ) {

	Point	a;
	Point	b(5, 0);
	Point	c(0, 5);

	Point	p(1, 3);

	std::cout << bsp(a, b, c, p) << std::endl;
	return 0;
}

