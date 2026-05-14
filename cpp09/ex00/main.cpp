#include "BitcoinExchange.hpp"

/*
2011-01-03 => 3 = 0.9
2011-01-03 => 2 = 0.6
2011-01-03 => 1 = 0.3
2011-01-03 => 1.2 = 0.36
2011-01-09 => 1 = 0.32
Error: not a positive number.
Error: bad input => 2001-42-42
2012-01-11 => 1 = 7.1
Error: too large a number
*/

int	main( int ac, char **av) {

	if (ac != 2) {

		std::cerr << "Invalid Args" << std::endl;
		return 1;
	}
	try {
		BitcoinExchange	data;
		// data.printData();
		data.prossessInput(av[1]);
	}
	catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
		return 1;
	}
	// (void) av;

	// std::ifstream	file(av[1]);
	// std::string	line;

	// std::getline(file, line);
	// if (line != "date | value") {
	// 	std::cout << "file must start with 'date | value'" << std::endl;
	// 	return 1;
	// }
	// while (std::getline(file, line)) {

	// 	std::istringstream iss(line);
    //     std::string date, pipe;
    //     double value;
    //     std::string extra;

    //     if (!(iss >> date >> pipe >> value) || pipe != "|" || (iss >> extra)) {
    //         std::cout << "Error: bad input => " << line << std::endl;
    //         continue;
    //     }

    //     std::cout << "date=[" << date << "], value=[" << value << "]" << std::endl;
	// }
	return 0;
}
