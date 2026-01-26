#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

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
	};
	class NoSpanException : std::exception {
		virtual const char* what() const throw();
	};

	void	addNumber( int );

	template <typename Iterator>
    void	addNumberRange( Iterator begin, Iterator end ) {
        int dist = std::distance(begin, end);

        if (dist <= 0)
            return ;
        for ( ; begin != end; begin++) {
            addNumber(*begin);
        }
    }

	int	shortestSpan( void );
	int	longestSpan( void );

};
