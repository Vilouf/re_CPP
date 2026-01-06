#pragma once

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {

private:

	std::string	_target;

public:

	ShrubberyCreationForm( const std::string & );
	ShrubberyCreationForm( const ShrubberyCreationForm & );
	ShrubberyCreationForm	&operator=( const ShrubberyCreationForm & );
	~ShrubberyCreationForm();

	std::string	&getTarget( void ) const;
	void	execute(Bureaucrat const & executor) const;
};
