#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <sstream>
#include <limits>
#include <cstdlib>

class PmergeMe {

private:

	std::vector<int>	_vector;
	std::list<int>		_list;

public:

	PmergeMe( );
	PmergeMe( const PmergeMe & );
	PmergeMe	&operator=( const PmergeMe & );
	~PmergeMe();

	class InputErrorException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	void	Parsing( int argc, const char *argv[] );

	void	PrintContainers( void );
};