#include "HumanA.hpp"

HumanA::HumanA( std::string name, Weapon &weapon ) : _name(name), _weapon(weapon) {

	std::cout << "HumanA " << _name << " with weapon " << _weapon.getType() << " created" << std::endl;
}

HumanA::~HumanA() {

	std::cout << "HumanA " << _name << " with weapon " << _weapon.getType() << " destroyed" << std::endl;
}

void	HumanA::attack( void ) {

	std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}