#include "Form.hpp"

Form::Form( const std::string &name, int signGrade, int execGrade ) : 
	_name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade) {

	if (_signGrade < 1 || _execGrade < 1)
		throw Form::GradeTooHighException();
	else if (_signGrade > 150 || _execGrade > 150)
		throw Form::GradeTooLowException();
}

Form::Form( const Form &other ) : 
	_name(other._name), _isSigned(other._isSigned), _signGrade(other._signGrade), _execGrade(other._execGrade) {}

Form	&Form::operator=( const Form &other ) {

	if (this != &other) {

		_isSigned = other._isSigned;
	}
	return *this;
}

Form::~Form() {}

const char*	Form::GradeTooHighException::what() const throw() { return "Form: Grade too high!"; }

const char*	Form::GradeTooLowException::what() const throw() { return "Form: Grade too low!"; }

const std::string	&Form::getName( void ) const { return _name; }
bool	Form::getIsSigned( void ) const { return _isSigned; }
int	Form::getSignGrade( void ) const { return _signGrade; }
int	Form::getExecGrade( void ) const { return _execGrade; }

void	Form::beSigned( Bureaucrat &bc ) {

	if (_isSigned == true) {

		std::cout << *this << "is already signed" << std::endl;
		return ;
	}
	if (bc.getGrade() > _signGrade)
		throw Form::GradeTooLowException();
	_isSigned = true;
}

std::ostream	&operator<<( std::ostream &o, const Form &f ) {

	o << "Form " << f.getName() << ", sign: " << f.getSignGrade() << ", execute: " << f.getExecGrade();
	return o;
}
