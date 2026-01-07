#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( const std::string &target ) : AForm("Robotomy", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm &other ) : AForm(other), _target(other._target) {}

RobotomyRequestForm	&RobotomyRequestForm::operator=( const RobotomyRequestForm &other ) {

	if (this != &other) {

		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

std::string	&RobotomyRequestForm::getTarget( void ) const { return _target; }

void	RobotomyRequestForm::execute( Bureaucrat const & executor ) const {

	if (getIsSigned() == true) {

		if (executor.getGrade() <= getExecGrade()) {

			
		}
		else
			throw AForm::GradeTooLowException();
	}
	else
		throw AForm::FormNotSignedException();
}
