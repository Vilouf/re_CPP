#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {

private:

	int	_rawBits;
	static const int	_fracBits = 8;

public:

	Fixed();
	Fixed( const Fixed & );
	Fixed	&operator=( const Fixed & );
	~Fixed();

	int	getRawBits( void ) const;
	void	setRawBits( int const raw );
};

#endif