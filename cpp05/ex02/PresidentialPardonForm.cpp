#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( const std::string &target ) : AForm("Presidential", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm &other ) : AForm(other), _target(other._target) {}

PresidentialPardonForm	&PresidentialPardonForm::operator=( const PresidentialPardonForm &other ) {

	if (this != &other) {

		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

std::string	&PresidentialPardonForm::getTarget( void ) const { return _target; }

void	PresidentialPardonForm::execute( Bureaucrat const & executor ) const {

	if (getIsSigned() == true) {

		if (executor.getGrade() <= getExecGrade()) {

			
		}
		else
			throw AForm::GradeTooLowException();
	}
	else
		throw AForm::FormNotSignedException();
}
