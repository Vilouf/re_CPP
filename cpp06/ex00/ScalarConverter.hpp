#pragma once

#include <iostream>
#include <cmath>
#include <limits.h>
#include <cstddef>
#include <stdlib.h>

class ScalarConverter {

private:

	ScalarConverter();
	ScalarConverter( const ScalarConverter & );
	ScalarConverter	&operator=( const ScalarConverter & );
	~ScalarConverter();

public:

	static void	convert( const std::string & );
};

