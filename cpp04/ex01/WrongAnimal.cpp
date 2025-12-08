#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal") { std::cout << "WrongAnimal " << _type << " created" << std::endl; }

WrongAnimal::WrongAnimal( const WrongAnimal &other ) {
	
	_type = other._type;
	std::cout << "WrongAnimal copy " << _type << " created" << std::endl;
}

WrongAnimal	&WrongAnimal::operator=( const WrongAnimal &other ) {

	if (this != &other) {

		_type = other._type;
		std::cout << "WrongAnimal assignement copy " << _type << " created" << std::endl;
	}
	return *this;
}

WrongAnimal::~WrongAnimal() { std::cout << "WrongAnimal " << _type << " destroyed" << std::endl; }

void	WrongAnimal::makeSound( void ) const { std::cout << "WrongAnimal sound?" << std::endl; }

std::string	WrongAnimal::getType( void ) const { return _type; }