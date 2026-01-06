#include "AForm.hpp"

AForm::AForm( const std::string &name, int signGrade, int execGrade ) : 
	_name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade) {

	if (_signGrade < 1 || _execGrade < 1)
		throw AForm::GradeTooHighException();
	else if (_signGrade > 150 || _execGrade > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm( const AForm &other ) : 
	_name(other._name), _isSigned(other._isSigned), _signGrade(other._signGrade), _execGrade(other._execGrade) {}

AForm	&AForm::operator=( const AForm &other ) {

	if (this != &other) {

		_isSigned = other._isSigned;
	}
	return *this;
}

AForm::~AForm() {}

const char*	AForm::GradeTooHighException::what() const throw() { return "Form: Grade too high!"; }

const char*	AForm::GradeTooLowException::what() const throw() { return "Form: Grade too low!"; }

const std::string	&AForm::getName( void ) const { return _name; }
bool	AForm::getIsSigned( void ) const { return _isSigned; }
int	AForm::getSignGrade( void ) const { return _signGrade; }
int	AForm::getExecGrade( void ) const { return _execGrade; }

void	AForm::beSigned( Bureaucrat &bc ) {

	if (_isSigned == true) {

		std::cout << *this << "is already signed" << std::endl;
		return ;
	}
	if (bc.getGrade() > _signGrade)
		throw AForm::GradeTooLowException();
	_isSigned = true;
}

std::ostream	&operator<<( std::ostream &o, const AForm &f ) {

	o << "Form " << f.getName() << ", sign: " << f.getSignGrade() << ", execute: " << f.getExecGrade();
	return o;
}
