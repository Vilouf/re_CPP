#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {

protected:

	std::string	_type;
	Brain	*_brain;

public:

	Dog();
	Dog( const Dog & );
	Dog	&operator=( const Dog & );
	~Dog();

	void	makeSound( void ) const;
	std::string	&getType( void ) const;
	std::string	*getIdea( int ) const;
	void	setIdea( const std::string & );
};