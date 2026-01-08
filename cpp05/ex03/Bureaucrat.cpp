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

const char*	Bureaucrat::GradeTooHighException::what() const throw() { return "Bureaucrat: Grade too high!"; }

const char*	Bureaucrat::GradeTooLowException::what() const throw() { return "Bureaucrat: Grade too low!"; }

const std::string	&Bureaucrat::getName( void ) const { return _name; }

int	Bureaucrat::getGrade( void ) const { return _grade; }

void	Bureaucrat::promote( int amount ) {

	if (_grade - amount < 1)
		throw Bureaucrat::GradeTooHighException();
	_grade -= amount;
}

void	Bureaucrat::demote( int amount ) {

	if (_grade + amount > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade += amount;
}

void	Bureaucrat::signForm( AForm &f ) {

	if (f.getIsSigned() == false) {

		f.beSigned(*this);
		std::cout << *this << " signed " << f << std::endl;
	}
	else
		std::cout << *this << " couldn't sign " << f << " because it was already signed" << std::endl;
}

void	Bureaucrat::executeForm( AForm const & form ) const {

	form.execute(*this);
	std::cout << *this << " executed " << form <<  std::endl;
}

std::ostream	&operator<<( std::ostream &o, const Bureaucrat &bc ) {

	o << bc.getName() << ", bureaucrat grade " << bc.getGrade() << ".";
	return o;
}
