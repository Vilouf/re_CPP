#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {

	std::ifstream	file("data.csv");
	std::string	line;

	if (!file)
		throw NoDataException();
	std::getline(file, line);
	if (line != "date,exchange_rate")
		throw NoDataException();
	while (std::getline(file, line)) {

		int	com = line.find(',');
		std::string	date = line.substr(0, com);
		std::string value_str = line.substr(com + 1);
		float value = std::atof(value_str.c_str());
		_data[date] = value;
	}
}

BitcoinExchange::BitcoinExchange( const BitcoinExchange &other ) : _data(other._data) {}

BitcoinExchange	&BitcoinExchange::operator=( const BitcoinExchange &other ) {

	if (this != &other) {

		_data = other._data;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

const char*	BitcoinExchange::NoDataException::what() const throw() { return "Valid data.csv file needed to build database"; }

void	BitcoinExchange::printData( void ) {

	for (std::map<std::string, float>::iterator it = _data.begin(); it != _data.end(); it++) {

		std::cout << it->first << ',' << it->second << std::endl;
	}
}
