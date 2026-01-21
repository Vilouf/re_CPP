#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <stdlib.h>
#include <time.h>

Base	*generate( void ) {

	switch (std::rand() % 3) {

		case 0:
			return new A();
		case 1:
			return new B();
		default:
			return new C();
	}
}

void	identify( Base *p ) {

	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void	identify( Base &p ) {

	try {

		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	}
	catch (...) {}
	try {

		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
	}
	catch (...) {}
	try {

		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
	}
	catch (...) {}
}

int	main( void ) {

	srand (time(NULL));
	Base	*ptr = generate();
	Base	&ref = *ptr;
	identify(ptr);
	identify(ref);
	delete ptr;
}