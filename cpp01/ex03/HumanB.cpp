#include "HumanB.hpp"

HumanB::HumanB( std::string name ) : _name(name), _weapon(NULL) {

	std::cout << "HumanB " << _name << " created" << std::endl;
}

HumanB::~HumanB() {

	std::cout << "HumanB " << _name << " with weapon " << _weapon->getType() << " destroyed" << std::endl;
}

void	HumanB::attack( void ) {

	if (_weapon == NULL)
		std::cout << _name << " has no weapon" << std::endl;
	else
		std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}

void	HumanB::setWeapon( Weapon &weapon ) {

	_weapon = &weapon;
}