#include "Dog.hpp"

Dog::Dog() : _type("Doggy") {
	
	_brain = new Brain();
	std::cout << "Dog " << _type << " created" << std::endl;
}

Dog::Dog( const Dog &other ) {
	
	_type = other._type;
	_brain = new Brain(*other._brain);
	std::cout << "Dog copy " << _type << " created" << std::endl;
}

Dog	&Dog::operator=( const Dog &other ) {

	if (this != &other) {

		_type = other._type;
		delete _brain;
		_brain = new Brain(*other._brain);
		std::cout << "Dog assignement copy " << _type << " created" << std::endl;
	}
	return *this;
}

Dog::~Dog() {
	
	delete _brain;
	std::cout << "Dog " << _type << " destroyed" << std::endl;
}

void	Dog::makeSound( void ) const { std::cout << "Woof" << std::endl; }

std::string	Dog::getType( void ) const { return _type; }
