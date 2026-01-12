#include "Data.hpp"

Data::Data( void ) : _value(42) {}

Data::Data( const Data & other ) {

	_value = other._value;
}

Data	&Data::operator=( const Data & other ) {

	if (this != &other) {

		_value = other._value;
	}
	return *this;
}

Data::~Data( void ) {}

int	Data::getValue( void ) const { return _value; }

void	Data::setValue( int value ) { _value = value; }
