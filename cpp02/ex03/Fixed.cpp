#include "Fixed.hpp"

Fixed::Fixed() : _rawBits(0) {}

Fixed::Fixed( int value ) {

	setRawBits(value << _fracBits);
}

Fixed::Fixed( float value ) {

	setRawBits((int) roundf(value * (1 << _fracBits)));
}

Fixed::Fixed( const Fixed &other ) {

	setRawBits(other._rawBits);
}

Fixed	&Fixed::operator=( const Fixed &other ) {

	if (this != &other) {

		setRawBits(other._rawBits);
	}
	return *this;
}

Fixed::~Fixed() {}


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

Fixed	&Fixed::operator++() {

	_rawBits++;
	return *this;
}

Fixed	Fixed::operator++( int ) {

	Fixed	tmp = *this;
	++*this;
	return tmp;
}

Fixed	&Fixed::operator--() {

	_rawBits--;
	return *this;
}

Fixed	Fixed::operator--( int ) {

	Fixed	tmp = *this;
	--*this;
	return tmp;
}

Fixed	&Fixed::min( Fixed &a, Fixed &b ) { return (a < b ? a : b); }

const Fixed	&Fixed::min( const Fixed &a, const Fixed &b ) { return (a < b ? a : b); }

Fixed	&Fixed::max( Fixed &a, Fixed &b ) { return (a > b ? a : b); }

const Fixed	&Fixed::max( const Fixed &a, const Fixed &b ) { return (a > b ? a : b); }
