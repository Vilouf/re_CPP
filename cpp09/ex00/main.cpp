#include "BitcoinExchange.hpp"

int	main( int ac, char **av) {

	if (ac != 2) {

		std::cerr << "Invalid Args" << std::endl;
		return 1;
	}
	(void) av;
	try {
		BitcoinExchange	data;
		data.printData();
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}
