#pragma once

#include "AMateria.hpp"

class Ice : public AMateria {

public:

	Ice();
	Ice( const Ice & );
	Ice	&operator=( const Ice & );
	~Ice();

	AMateria* clone( void ) const;
	void use( ICharacter& );
};
