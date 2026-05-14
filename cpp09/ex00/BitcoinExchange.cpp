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
const char*	BitcoinExchange::NoInputException::what() const throw() { return "No valid input file found"; }

void	BitcoinExchange::printData( void ) {

	for (std::map<std::string, float>::iterator it = _data.begin(); it != _data.end(); it++) {

		std::cout << it->first << ',' << it->second << std::endl;
	}
}

bool	BitcoinExchange::is_numeric(const std::string& s) {
	if (s.empty()) return false;

	for (std::string::size_type i = 0; i < s.length(); ++i) {
		if (!std::isdigit(static_cast<unsigned char>(s[i]))) {
			return false;
		}
	}
	return true;
}

void	BitcoinExchange::prossessInput( const char *input ) {

	std::ifstream	file(input);
	std::string	line;

	if (!file)
		throw NoInputException();
	std::getline(file, line);
	if (line != "date | value")
		throw NoInputException();
	while (std::getline(file, line)) {

		std::istringstream iss(line);
        std::string date, pipe;
        float value;
        std::string extra;

        if (!(iss >> date >> pipe >> value) || pipe != "|" || (iss >> extra)) {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
		if (value < 0) {
            std::cout << "Error: not a positive number. " << std::endl;
            continue;
        }
		if (value > 1000) {
            std::cout << "Error: too large number. " << std::endl;
            continue;
        }

		size_t hyphenyear = date.find('-');

		if (hyphenyear == std::string::npos || hyphenyear == 0 || hyphenyear != 4)
		{
			std::cout << "Error: bad input => " << date << std::endl;
			continue;
		}
		std::string year = date.substr(0, hyphenyear);


		size_t hyphenmonth = date.find('-', hyphenyear + 1);
		if (hyphenmonth == std::string::npos || hyphenmonth == 0 || hyphenmonth - hyphenyear != 3)
		{
			std::cout << "Error: bad input => " << date << std::endl;
			continue;
		}
		std::string month = date.substr(hyphenyear + 1, 2);

		std::string day = date.substr(hyphenmonth + 1);
		if (day.length() != 2)
		{
			std::cout << "Error: bad input => " << date << std::endl;
			continue;
		}

		if (!is_numeric(year) || !is_numeric(month) || !is_numeric(day))
		{
			std::cout << "Error: bad input => " << date << std::endl;
			continue;
		}

		int yeari = std::atoi(year.c_str());
		int monthi = std::atoi(month.c_str());
		int dayi = std::atoi(day.c_str());

		if (yeari < 2009 || yeari > 2022)
		{
			std::cout << "Error: database is between 2009 and 2022 => " << date << std::endl;
			continue;
		}
		if (monthi > 12)
		{
			std::cout << "Error: bad input => " << date << std::endl;
			continue;
		}
		if (((monthi == 1 || monthi == 3 ||  monthi == 5 ||  monthi == 7 ||  monthi == 8 ||  monthi == 10 ||  monthi == 12) && dayi > 31) ||
			((monthi == 4 || monthi == 6 || monthi == 9 || monthi == 11) && dayi > 30) ||
			(monthi == 2 && (yeari % 4 == 0) && dayi > 29) || (monthi == 2 && (yeari % 4 != 0) && dayi > 28))
		{
			std::cout << "Error: bad input => " << date << std::endl;
			continue;
		}

		std::map<std::string, float>::iterator it = _data.lower_bound(date);
		if (it == _data.end())
			it--;
		else if (it->first != date && it != _data.begin())
			it--;
		std::cout << date << " => " << value << " = " << value * it->second << std::endl;
	}
}
