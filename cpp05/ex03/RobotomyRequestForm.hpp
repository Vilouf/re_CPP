#pragma once

#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm {

private:

	std::string	_target;

public:

	RobotomyRequestForm( const std::string & );
	RobotomyRequestForm( const RobotomyRequestForm & );
	RobotomyRequestForm	&operator=( const RobotomyRequestForm & );
	~RobotomyRequestForm();

	const std::string	&getTarget( void ) const;
	void	beExecuted( void ) const;
};
