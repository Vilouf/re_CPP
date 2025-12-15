#pragma once

#include "AMateria.hpp"

class Cure : public AMateria {

public:

	Cure();
	Cure( const Cure & );
	Cure	&operator=( const Cure & );
	~Cure();

	AMateria* clone( void ) const;
	void use( ICharacter& );
};
