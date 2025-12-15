#pragma once

#include <iostream>
#include "ICharacter.hpp"

#define GREEN_COLOR "\033[32m"
#define RED_COLOR "\033[31m"
#define RESET "\033[0m"

#define GREEN(str) GREEN_COLOR << (str) << RESET
#define RED(str) RED_COLOR << (str) << RESET

class ICharacter;

class AMateria {

protected:

	const std::string	_type;
	bool	_isEquipped;

public:

	AMateria( std::string const & );
	AMateria( const AMateria & );
	AMateria	&operator=( const AMateria & );
	virtual ~AMateria();

	std::string const & getType() const;

	void	setEquipped( bool );
	bool	getEquipped();

	virtual AMateria* clone( void ) const = 0;
	virtual void use( ICharacter& );
};
