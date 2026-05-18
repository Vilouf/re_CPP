#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN & other) : _stack(other._stack) {}

RPN &RPN::operator=(const RPN & other) {

	if (this != &other)
		_stack = other._stack;
	return *this;

}

RPN::~RPN() {}

const char*	RPN::InputErrorException::what() const throw() { return "Error: Valid input needed to operate"; }
const char*	RPN::DivideByZeroException::what() const throw() { return "Error: Cannot divide by 0"; }
const char*	RPN::TooManyNumbersException::what() const throw() { return "Error: Too many numbers in stack"; }
const char*	RPN::NotEnoughNumbersException::what() const throw() { return "Error: Not enough numbers in stack"; }

bool	RPN::isOperator( char c ) {

	if (c == '+' || c == '-' || c == '*' || c == '/')
		return true;
	return false;
}

double	RPN::doOperation( char tokenOperator, double operand1, double operand2 ) {

	if (tokenOperator == '+')
		return operand1 + operand2;
	if (tokenOperator == '-')
		return operand1 - operand2;
	if (tokenOperator == '*')
		return operand1 * operand2;
	if (tokenOperator == '/') {

		if (operand2 == 0)
			throw DivideByZeroException();

		return operand1 / operand2;
	}
	throw InputErrorException();
}

double	RPN::operate( const std::string &input ) {

	if (input.empty())
		throw InputErrorException();
	
	std::istringstream iss(input);
	std::string	token;

	while (iss >> token) {

		if (token.size() == 1) {

			if (std::isdigit(token[0]))
				_stack.push(static_cast<double>(token[0]) - 48);
			else if (isOperator(token[0])) {

				if (_stack.size() < 2)
					throw NotEnoughNumbersException();
				double	operand2 = _stack.top();
				_stack.pop();
				double	operand1 = _stack.top();
				_stack.pop();
				_stack.push(doOperation(token[0], operand1, operand2));
			}
			else
				throw InputErrorException();
		}
		else
			throw InputErrorException();
	}
	if (_stack.size() != 1)
		throw TooManyNumbersException();
	return _stack.top();
}
