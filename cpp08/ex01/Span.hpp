#pragma once

#include <iostream>
#include <vector>

class Span {

private:

	std::vector<int>	_numbers;
	unsigned int	_N;

public:

	Span( unsigned int );
	Span( const Span & );
	Span	&operator=( const Span & );
	~Span();

	class ContainerIsFullException : std::exception {
		virtual const char* what() const throw();
	}
	class NoSpanException : std::exception {
		virtual const char* what() const throw();
	}

	void	addNumber( int );

	int	shortestSpan( void );
	int	longestSpan( void );

};