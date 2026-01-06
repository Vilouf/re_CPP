#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {

private:

	const std::string	_name;
	bool	_isSigned;
	const int	_signGrade;
	const int	_execGrade;

public:

	AForm( const std::string &, int, int );
	AForm( const AForm & );
	AForm	&operator=( const AForm & );
	virtual ~AForm();

	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	const std::string	&getName() const;
	bool	getIsSigned() const;
	int	getSignGrade() const;
	int	getExecGrade() const;

	void	beSigned( Bureaucrat & );
	virtual void	execute(Bureaucrat const & executor) const = 0;
};

std::ostream	&operator<<( std::ostream &, const AForm & );
