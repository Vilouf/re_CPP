#pragma once

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {

public:

	WrongCat();
	WrongCat( const WrongCat & );
	WrongCat	&operator=( const WrongCat & );
	virtual ~WrongCat();

	void	makeSound( void ) const;
};