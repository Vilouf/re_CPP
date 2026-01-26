#include "Span.hpp"

Span::Span( unsigned int N ) : _N(N) {}

Span::Span( const Span &other ) : _numbers(other._numbers), _N(other._N) {

	if (_numbers.size() > _N)
		throw ContainerIsFullException();
}

Span	&Span::operator=( const Span &other ) {

	if (this != &other) {

		_numbers = other._numbers;
		_N = other._N;
	}
	return *this;
}

Span::~Span() {}

const char*	Span::ContainerIsFullException::what() const throw() { return "Cannot add any more numbers"; }

const char*	Span::NoSpanException::what() const throw() { return "No span can be found"; }

void	Span::addNumber( int n ) {

	if (_numbers.size() == _N)
		throw ContainerIsFullException();
	_numbers.push_back(n);
}

int	Span::shortestSpan( void ) {

	if (_numbers.size() < 2)
		throw NoSpanException();

	std::sort(_numbers.begin(), _numbers.end());

	int	shortest = _numbers[_numbers.size() - 1];
	for (size_t i = 1; i < _numbers.size(); i++) {

		if (shortest > _numbers[i] - _numbers[i - 1])
			shortest = _numbers[i] - _numbers[i - 1];
	}
	return shortest;
}

int	Span::longestSpan( void ) {

	if (_numbers.size() < 2)
		throw NoSpanException();

	std::sort(_numbers.begin(), _numbers.end());

	return _numbers[_numbers.size() - 1] - _numbers[0];
}
