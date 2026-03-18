#pragma once

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <map>
#include <sstream>

class BitcoinExchange {

private:

	std::map<std::string, float>	_data;

public:

	BitcoinExchange();
	BitcoinExchange( const BitcoinExchange & );
	BitcoinExchange	&operator=( const BitcoinExchange & );
	~BitcoinExchange();

	class NoDataException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	void	printData( void );

};
