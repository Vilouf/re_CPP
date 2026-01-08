#pragma once

#include <iostream>
#include <cmath>
#include <limits.h>
#include <cstddef>

class ScalarConverter {

private:

	ScalarConverter();
	ScalarConverter( const ScalarConverter & );
	ScalarConverter	&operator=( const ScalarConverter & );
	~ScalarConverter();

public:
	char convertChar(std::string &litteral)
	static void	convert( const std::string & ) const;
};

