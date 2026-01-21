#include "Span.hpp"

Span::Span( unsigned int N ) : _N(N) {}

Span::Span( const Span &other ) : _N(other.N), _numbers(other._numbers) {}

Span	&Span::operator=( const Span &other ) {

	if (this != &other) {

		_numbers = other._numbers;
		_N = other._N;
	}
	return *this;
}

Span::~Span() {}

virtual const char*	Span::ContainerIsFullException::what() const throw() { return "Cannot add any more numbers" }

virtual const char*	Span::NoSpanException::what() const throw() { return "No span can be found" }

void	Span::addNumber( int n ) {

	if (_numbers.size() == N)
		throw ContainerIsFullException;
	_numbers.push_back(n);
}
