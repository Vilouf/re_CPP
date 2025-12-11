#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {

private:

	Brain	*_brain;

public:

	Cat();
	Cat( const Cat & );
	Cat	&operator=( const Cat & );
	~Cat();

	void	makeSound( void ) const;
	void	Think( void ) const;
};