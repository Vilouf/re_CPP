#pragma once

#include "Animal.hpp"

class Cat : public Animal {

protected:

	std::string	_type;

public:

	Cat();
	Cat( const Cat & );
	Cat	&operator=( const Cat & );
	~Cat();

	void	makeSound( void ) const;
	std::string	getType( void ) const;
};