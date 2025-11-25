#include "Fixed.hpp"

Fixed::Fixed() : _rawBits(0) { std::cout << "Default constructor called" << std::endl; }

Fixed::Fixed( int value ) {

	std::cout << "Int constructor called" << std::endl;
	setRawBits(value << _fracBits);
}

Fixed::Fixed( float value ) {

	std::cout << "Float constructor called" << std::endl;
	setRawBits((int) roundf(value * (1 << _fracBits)));
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

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }


int		Fixed::getRawBits( void ) const { return _rawBits; }

void	Fixed::setRawBits( int const raw ) { _rawBits = raw; }


float	Fixed::toFloat( void ) const { return (float)_rawBits / (1 << _fracBits); }

int		Fixed::toInt( void ) const { return _rawBits >> _fracBits; }


std::ostream	&operator<<( std::ostream &o, const Fixed &fxd ) {

	o << fxd.toFloat();
    return o;
}


bool	Fixed::operator>( const Fixed &other ) const { return getRawBits() > other.getRawBits(); }
bool	Fixed::operator<( const Fixed &other ) const { return getRawBits() < other.getRawBits(); }
bool	Fixed::operator>=( const Fixed &other ) const { return getRawBits() >= other.getRawBits(); }
bool	Fixed::operator<=( const Fixed &other ) const { return getRawBits() <= other.getRawBits(); }
bool	Fixed::operator==( const Fixed &other ) const { return getRawBits() == other.getRawBits(); }
bool	Fixed::operator!=( const Fixed &other ) const { return getRawBits() != other.getRawBits(); }

float	Fixed::operator+( const Fixed &other ) { return toFloat() + other.toFloat(); }
float	Fixed::operator-( const Fixed &other ) { return toFloat() - other.toFloat(); }
float	Fixed::operator*( const Fixed &other ) { return toFloat() * other.toFloat(); }
float	Fixed::operator/( const Fixed &other ) { return toFloat() / other.toFloat(); }
