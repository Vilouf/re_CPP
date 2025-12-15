#include "Dog.hpp"

Dog::Dog() {

	_type = "Doggy";
	std::cout << "Dog " << _type << " created" << std::endl;
}

Dog::Dog( const Dog &other ) {
	
	_type = other._type;
	std::cout << "Dog copy " << _type << " created" << std::endl;
}

Dog	&Dog::operator=( const Dog &other ) {

	if (this != &other) {

		_type = other._type;
		std::cout << "Dog asignment copy " << _type << " created" << std::endl;
	}
	return *this;
}

Dog::~Dog() { std::cout << "Dog " << _type << " destroyed" << std::endl; }

void	Dog::makeSound( void ) const { std::cout << "Woof" << std::endl; }
