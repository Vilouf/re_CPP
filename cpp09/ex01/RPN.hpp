#pragma once

#include <iostream>
#include <stack>
#include <sstream>

class RPN {

private:

	std::stack<double>	_stack;

	bool	isOperator( char );
	double	doOperation( char, double, double );

public:

	RPN();
	RPN(const RPN & other);
	RPN &operator=(const RPN & other);
	~RPN();

	class InputErrorException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
	class DivideByZeroException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
	class TooManyNumbersException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
	class NotEnoughNumbersException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	double	operate( const std::string & );

};
