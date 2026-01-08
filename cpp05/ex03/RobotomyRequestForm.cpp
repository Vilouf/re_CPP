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

const std::string	&RobotomyRequestForm::getTarget( void ) const { return _target; }

void	RobotomyRequestForm::beExecuted() const {

	std::cout << "* some drilling noises *" << std::endl;
	std::cout << "* some drilling noises *" << std::endl;
	if (std::rand() % 2)
		std::cout << _target << " has been successfully robotomized!" << std::endl;
	else
		std::cout << _target << "'s robotomy has failed." << std::endl;
}
