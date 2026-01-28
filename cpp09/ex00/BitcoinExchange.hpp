#pragma once

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <map>

class BitcoinExchange {

private:

	std::map<std::string, float>	_data;

public:

	BitcoinExchange();
	BitcoinExchange( const BitcoinExchange & );
	BitcoinExchange	&operator=( const BitcoinExchange & );
	~BitcoinExchange();

	class NoDataException : std::exception {
		virtual const char* what() const throw();
	};

	void	printData( void );

};
