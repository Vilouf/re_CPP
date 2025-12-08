#pragma once

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {

protected:

	std::string	_type;

public:

	WrongCat();
	WrongCat( const WrongCat & );
	WrongCat	&operator=( const WrongCat & );
	virtual ~WrongCat();

	void	makeSound( void ) const;
	std::string	getType( void ) const;
};