#include "Fixed.hpp"

Fixed::Fixed() : _rawBits(0) {

	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const Fixed &other ) {

	std::cout << "Copy constructor called" << std::endl;
	setRawBits(other._rawBits);
}

Fixed	&Fixed::operator=( const Fixed &other) {

	std::cout << "Copy assignment constructor called" << std::endl;
	if (this != &other) {

		setRawBits(other._rawBits);
	}
	return *this;
}

Fixed::~Fixed() {

	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits( void ) const { 

	std::cout << "getRawBits member function called" << std::endl;
	return _rawBits;
}

void	Fixed::setRawBits( int const raw ) {

	std::cout << "SetRawBits member function called" << std::endl;
	_rawBits = raw;
}