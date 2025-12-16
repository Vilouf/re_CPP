#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( const std::string &name, int grade ) : _name(name), _grade(grade) {

	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat( const Bureaucrat &other ) : _name(other._name), _grade(other._grade) {}

Bureaucrat	&Bureaucrat::operator=( const Bureaucrat &other ) {

	if (this != &other) {

		_grade = other._grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat() {}

const char*	Bureaucrat::GradeTooHighException::what() const throw() { return "Grade too high!"; }

const char*	Bureaucrat::GradeTooLowException::what() const throw() { return "Grade too low!"; }

const std::string	&Bureaucrat::getName( void ) const { return _name; }

int	Bureaucrat::getGrade( void ) const { return _grade; }

void	Bureaucrat::promote( void ) {

	_grade--;
	if (_grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

void	Bureaucrat::demote( void ) {

	_grade++;
	if (_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

std::ostream	&operator<<( std::ostream &o, const Bureaucrat &bc ) {

	o << "Bureaucrat " << bc.getName() << " (" << bc.getGrade() << ")";
	return o;
}
