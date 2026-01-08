#include "ScalarConverter.hpp"


ScalarConverter::ScalarConverter( void ) {}

ScalarConverter::ScalarConverter( std::string name ) {}

ScalarConverter::ScalarConverter( const ScalarConverter & other ) {

	(void) other;
}

ScalarConverter	&ScalarConverter::operator=( const ScalarConverter & other ) {

	(void) other;
	return *this;
}

ScalarConverter::~ScalarConverter( void ) {}

void	ScalarConverter::convert( const std::string &str ) const {

	size_t	i;
	bool	point = false;
	bool	invalid = false;

	for (i = 0; i < str.length(); i++) {

		if (str[i] == '.') {

			if (point == true)
				invalid = true;
			else
				point = true;
		}
		else if (std::isdigit(str[i]) == false)
			break ;
	}
	std::
}

ScalarConverter::convertChar(std::string &litteral){
	double value = litteral;
	if ( std::numeric_limits::min(value) || std::numeric_limits::max(value))
		std::cout << "non displayable" << std::endl;
	char c = static_cast<char>(value); 
	if (!std::isprint(c))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << c << "'" << std::endl;

}

ScalarConverter::convertint(std::string &litteral){
	double value = litteral;
	if ( std::numeric_limits::min(value) || std::numeric_limits::max(value))
		std::cout << "non displayable" << std::endl;
	int c = static_cast<intr>(value); 
	if (!std::isprint(c))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << c << "'" << std::endl;

}