#pragma once

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm {

private:

	std::string	_target;

public:

	ShrubberyCreationForm( const std::string & );
	ShrubberyCreationForm( const ShrubberyCreationForm & );
	ShrubberyCreationForm	&operator=( const ShrubberyCreationForm & );
	~ShrubberyCreationForm();

	const std::string	&getTarget( void ) const;
	void	beExecuted( void ) const;
};
