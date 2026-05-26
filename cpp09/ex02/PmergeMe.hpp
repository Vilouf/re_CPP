#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <sstream>
#include <limits>
#include <cstdlib>
#include <algorithm>
#include <sys/time.h>

class PmergeMe {

private:

	std::vector<int>	_vector;
	std::list<int>		_list;

	void CheckDuplicate();

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

	std::vector<int> 	getVector( void );
	std::list<int> 		getList( void );
	void 	setVector( std::vector<int> );
	void 	setList( std::list<int> );

	void	PrintVector( void );
	void	PrintList( void );
};