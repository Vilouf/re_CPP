#include "Span.hpp"
#include <stdlib.h>
#include <time.h>

int	main( void ) {

	Span	span(5);
	// std::vector<int>	test;
	// srand (time(NULL));

	try {

		// for (int i = 0; i < 10; i++)
		// 	test.push_back(i);
		// for (int i = 0; i < 100; i++) {

		// 	span.addNumber(rand() % 100000);
		// }
		// span.addNumberRange(test.begin(), test.end());
		span.addNumber(6);
		span.addNumber(3);
		span.addNumber(17);
		span.addNumber(9);
		span.addNumber(11);
		std::cout << span.shortestSpan() << std::endl;
		std::cout << span.longestSpan() << std::endl;
	}
	catch(std::exception &e) { std::cerr << e.what() << std::endl; }
}