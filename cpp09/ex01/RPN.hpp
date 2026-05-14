#pragma once

#include <iostream>
#include <stack>
#include <sstream>

class RPN {

private:

	std::stack<double>	_stack;

	bool	isOperator( char );
	void	doOperation( char, double, double );

public:

	RPN();
	~RPN();

	class InputErrorException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	void	operate( const std::string & );

};
