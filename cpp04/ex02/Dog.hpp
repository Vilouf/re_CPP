#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {

private:

	Brain	*_brain;

public:

	Dog();
	Dog( const Dog & );
	Dog	&operator=( const Dog & );
	~Dog();

	void	makeSound( void ) const;
	void	Think( void ) const;
};