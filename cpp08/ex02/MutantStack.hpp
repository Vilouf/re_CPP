#pragma once

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : std::stack<T> {

public:

	MutantStack();
	MutantStack( const MutantStack & );
	MutantStack	&operator=( const MutantStack & );
	~MutantStack();

};
