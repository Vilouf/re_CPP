#include "Character.hpp"

Character::Character() : _name("default") {

	for (int i = 0; i < 4; i++) {

		_inventory[i] = NULL;
	}
	_floor = NULL;
	std::cout << GREEN("Character ") << GREEN(_name) << GREEN(" created") << std::endl;
}

Character::Character( const std::string &name ) : _name(name) {

	for (int i = 0; i < 4; i++) {

		_inventory[i] = NULL;
	}
	_floor = NULL;
	std::cout << GREEN("Character ") << GREEN(_name) << GREEN(" created") << std::endl;
}

Character::Character( const Character &other ) {

	for (int i = 0; i < 4; i++) {

		_name = other._name;
		_inventory[i] = other._inventory[i];
	}
	_floor = other._floor;
	std::cout << GREEN("Character copy ") << GREEN(_name) << GREEN(" created") << std::endl;
}

Character	&Character::operator=( const Character &other ) {

	if (this != &other) {

		_name = other._name;
		for (int i = 0; i < 4; i++) {

			if (_inventory[i])
				delete _inventory[i];
			_inventory[i] = other._inventory[i];
		}
		if (_floor)
			delete _floor;
		if (other._floor) {
			_floor = other._floor;
		}
		else {
			_floor = NULL;
		}
		std::cout << GREEN("Character copy assignment ") << GREEN(_name) << GREEN(" created") << std::endl;
	}
	return *this;
}

Character::~Character() {

	for (int i = 0; i < 4; i++) {

		if (_inventory[i])
			delete _inventory[i];
	}
	if (_floor)
		delete _floor;
	std::cout << RED("Character ") << RED(_name) << RED(" deleted") << std::endl;
}

std::string const	&Character::getName( void ) const { return _name; }

AMateria	*Character::getFloor( void ) const { 
	
	_floor->setEquipped(false);
	return _floor;
}

void	Character::equip( AMateria *m ) {

	if (!m) {

		std::cout << "Materia must exist" << std::endl;
	}
	else if (m->getEquipped() == true) {

		std::cout << m->getType() << " Materia is already equipped" << std::endl;
	}
	else {

		for (int i = 0; i < 4; i++) {

			if (!_inventory[i]) {

				_inventory[i] = m;
				m->setEquipped(true);
				return ;
			}
		}
		std::cout << _name << "'s inventory is full" << std::endl;
	}
}

void	Character::unequip( int idx ) {

	if (idx < 0 || idx > 3) {

		std::cout << "Index must be between 0 and 3" << std::endl;
	}
	else if (!_inventory[idx]) {

		std::cout << "Nothing to unequip at this index" << std::endl;
	}
	else {

		if (_floor)
			delete _floor;
		_floor = _inventory[idx];
		_inventory[idx] = NULL;
	}
}

void	Character::use( int idx, ICharacter &target ) {

	if (idx < 0 || idx > 3) {

		std::cout << "Index must be between 0 and 3" << std::endl;
	}
	else if (!_inventory[idx]) {

		std::cout << "Nothing to use at this index" << std::endl;
	}
	else {

		_inventory[idx]->use(target);
	}
}
