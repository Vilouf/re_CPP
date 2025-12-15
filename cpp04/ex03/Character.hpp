#pragma once

#include "AMateria.hpp"

class Character : public ICharacter {

private:

	std::string	_name;
	AMateria	*_inventory[4];
	AMateria	*_floor;

public:

	Character();
	Character( std::string const & );
	Character( const Character & );
	Character	&operator=( const Character & );
	~Character();

	std::string const & getName() const;
	AMateria	*getFloor() const;

	void equip( AMateria* m );
	void unequip( int idx );
	void use( int idx, ICharacter& target );
};
