#include "Zombie.hpp"

Zombie::Zombie() {

	std::cout << "Zombie created" << std::endl;
}

Zombie::~Zombie() {

	std::cout << "Zombie " << _name << " destroyed" << std::endl;
}

void	Zombie::announce( void ) {

	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName( std::string name ) {

	_name = name;
}