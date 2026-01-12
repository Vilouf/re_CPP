#include "ScalarConverter.hpp"

void	convertChar( double value ) {

	std::cout << "char: ";
	if (std::isnan(value) || std::isinf(value)) {

		std::cout << "impossible" << std::endl;
		return ;
	}
	char c = static_cast<char>(value); 
	if (!std::isprint(c)) {

        std::cout << "Non displayable" << std::endl;
		return ;
	}
    else
        std::cout << "'" << c << "'" << std::endl;
}

void	convertInt( double value ) {

	std::cout << "int: ";
	if (std::isnan(value) || std::isinf(value)) {

		std::cout << "impossible" << std::endl;
		return ;
	}
	if (value < INT_MIN || value > INT_MAX) {

        std::cout << "Non displayable" << std::endl;
		return ;
	}
	int i = static_cast<int>(value);
    std::cout << i << std::endl;
}

void	convertFloat( double value ) {

	std::cout << "float: ";
	float f = static_cast<float>(value);
	if (std::isnan(value) || std::isinf(value)) {

		std::cout << f << "f" << std::endl;
		return ;
	}
	if (f >= 1000000 || f <= -1000000)
    	std::cout << f << "f" << std::endl;
	else {

		if (f - static_cast<int>(f) == 0)
			std::cout << f << ".0f" << std::endl;
		else
			std::cout << f << "f" << std::endl;
	}
}

void	convertDouble( double value ) {

	std::cout << "double: ";
	if (std::isnan(value) || std::isinf(value)) {

		std::cout << value << std::endl;
		return ;
	}
	if (value >= 1000000 || value <= -1000000)
    	std::cout << value << std::endl;
	else {

		if (value - static_cast<int>(value) == 0)
			std::cout << value << ".0" << std::endl;
		else
			std::cout << value << std::endl;
	}
}

void	ScalarConverter::convert( const std::string &str ) {

	if (str.length() == 1 && !std::isdigit(str[0])) {

		char	c = str[0];
		std::cout << "char: ";
		if (std::isprint(c))
			std::cout << "'" << c << "'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
		std::cout << "int: " << static_cast<int>(c) << std::endl;
		std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
		return ;
	}

	char	*strEnd;
	double	value = std::strtod(str.c_str(), &strEnd);

	if (*strEnd != 0 && !(*strEnd == 'f' && *(strEnd + 1) == 0)) {

		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return ;
	}

	convertChar(value);
	convertInt(value);
	convertFloat(value);
	convertDouble(value);
}
