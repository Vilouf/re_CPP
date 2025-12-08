#pragma once

#include "Animal.hpp"

class Dog : public Animal {

protected:

	std::string	_type;

public:

	Dog();
	Dog( const Dog & );
	Dog	&operator=( const Dog & );
	~Dog();

	void	makeSound( void ) const;
	std::string	getType( void ) const;
};