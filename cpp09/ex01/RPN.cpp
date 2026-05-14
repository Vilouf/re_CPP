#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN & other) : _stack(other._stack) {}

RPN & RPN::operator = (const RPN & other)
{
	if (this != &other)
		_stack = other._stack;
	return *this;
}

RPN::~RPN() {}

const char*	RPN::InputErrorException::what() const throw() { return "Valid input needed to operate"; }

bool	RPN::isOperator( char c ) {

	if (c == '+' || c == '-' || c == '*' || c == '/')
		return true;
	return false;
}

void	doOperation( char tokenOperator, double operand1, double operand2 ) {


}

void	RPN::operate( const std::string &input ) {

	if (input.empty())
		throw InputErrorException();
	
	std::istringstream iss(input);
	std::string	token;

	while (iss >> token) {

		if (token.size() == 1) {

			if (std::isdigit(token[0]))
				_stack.push(static_cast<double>(token[0]));
			else if (isOperator(token[0])) {

				if (_stack.size() < 2)
					throw InputErrorException();
				double	operand2 = _stack.top();
				_stack.pop();
				double	operand1 = _stack.top();
				_stack.pop();
				doOperation(token[0], operand1, operand2);
			}
			else
				throw InputErrorException();
		}
		else
			throw InputErrorException();
	}
}
