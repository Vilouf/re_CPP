#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {

protected:

	std::string	_type;
	Brain	*_brain;

public:

	Cat();
	Cat( const Cat & );
	Cat	&operator=( const Cat & );
	~Cat();

	void	makeSound( void ) const;
	std::string	&getType( void ) const;
	std::string	*getIdea( int ) const;
	void	setIdea( const std::string & );
};