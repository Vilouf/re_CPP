#pragma once

#include <iostream>

class Bureaucrat {

private:

	const std::string	_name;
	int	_grade;

public:

	Bureaucrat( const std::string &, int );
	Bureaucrat( const Bureaucrat & );
	Bureaucrat	&operator=( const Bureaucrat & );
	~Bureaucrat();

	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	const std::string	&getName() const;
	int	getGrade() const;

	void	promote();
	void	demote();
};

std::ostream	&operator<<( std::ostream &, const Bureaucrat & );