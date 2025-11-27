#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {

private:

	int	_rawBits;
	static const int	_fracBits = 8;

public:

	Fixed();
	Fixed( const int value );
	Fixed( const float value );
	Fixed( const Fixed & );
	Fixed	&operator=( const Fixed & );
	~Fixed();

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );

	float	toFloat( void ) const;
	int		toInt( void ) const;

	bool	operator>( const Fixed & ) const;
	bool	operator<( const Fixed & ) const;
	bool	operator>=( const Fixed & ) const;
	bool	operator<=( const Fixed & ) const;
	bool	operator==( const Fixed & ) const;
	bool	operator!=( const Fixed & ) const;

	float	operator+( const Fixed & );
	float	operator-( const Fixed & );
	float	operator*( const Fixed & );
	float	operator/( const Fixed & );

	Fixed	&operator++();
	Fixed	operator++( int );
	Fixed	&operator--();
	Fixed	operator--( int );

	static Fixed	&min( Fixed&, Fixed& ) ;
	static const Fixed	&min( const Fixed&, const Fixed& );
	static Fixed	&max( Fixed&, Fixed& );
	static const Fixed	&max( const Fixed&, const Fixed& );
};

std::ostream	&operator<<( std::ostream &o, const Fixed &fxd );

#endif