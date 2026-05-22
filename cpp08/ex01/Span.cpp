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

long Span::shortestSpan( void )
{
    if (_numbers.size() < 2)
        throw NoSpanException();

    std::sort(_numbers.begin(), _numbers.end());

    long	shortest = _numbers.back();
    for (size_t i = 1; i < _numbers.size(); i++)
    {
        long diff = static_cast<long>(_numbers[i]) - _numbers[i - 1];
        if (diff < shortest)
            shortest = static_cast<long>(diff);
    }
    return shortest;
}

long Span::longestSpan( void )
{
    if (_numbers.size() < 2)
        throw NoSpanException();

    std::sort(_numbers.begin(), _numbers.end());

    return static_cast<long>(_numbers.back()) - _numbers.front();
}
