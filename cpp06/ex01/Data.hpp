#pragma once

#include <iostream>

class Data {

private:

	int	_value;

public:

	Data();
	Data( const Data & );
	Data	&operator=( const Data & );
	~Data();

	int	getValue( void ) const;
	void	setValue( int );
};
