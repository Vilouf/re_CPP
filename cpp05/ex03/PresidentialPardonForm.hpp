#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {

private:

	std::string	_target;

public:

	PresidentialPardonForm( const std::string & );
	PresidentialPardonForm( const PresidentialPardonForm & );
	PresidentialPardonForm	&operator=( const PresidentialPardonForm & );
	~PresidentialPardonForm();

	const std::string	&getTarget( void ) const;
	void	beExecuted( void ) const;
};
