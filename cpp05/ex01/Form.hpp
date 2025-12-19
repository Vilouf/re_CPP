#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {

private:

	const std::string	_name;
	bool	_isSigned;
	const int	_signGrade;
	const int	_execGrade;

public:

	Form( const std::string &, int, int );
	Form( const Form & );
	Form	&operator=( const Form & );
	~Form();

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
};

std::ostream	&operator<<( std::ostream &, const Form & );