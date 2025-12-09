#include "Animal.hpp"

Animal::Animal() : _type("Animal") { std::cout << "Animal " << _type << " created" << std::endl; }

Animal::Animal( const Animal &other ) {
	
	_type = other._type;
	std::cout << "Animal copy " << _type << " created" << std::endl;
}

Animal	&Animal::operator=( const Animal &other ) {

	if (this != &other) {

		_type = other._type;
		std::cout << "Animal assignement copy " << _type << " created" << std::endl;
	}
	return *this;
}

Animal::~Animal() { std::cout << "Animal " << _type << " destroyed" << std::endl; }

void	Animal::makeSound( void ) const { std::cout << "Animal sound?" << std::endl; }

std::string	&Animal::getType( void ) const { return _type; }
