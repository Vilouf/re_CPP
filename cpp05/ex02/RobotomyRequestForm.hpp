#pragma once

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {

private:

	std::string	_target;

public:

	RobotomyRequestForm( const std::string & );
	RobotomyRequestForm( const RobotomyRequestForm & );
	RobotomyRequestForm	&operator=( const RobotomyRequestForm & );
	~RobotomyRequestForm();

	std::string	&getTarget( void ) const;
	void	execute(Bureaucrat const & executor) const;
};
