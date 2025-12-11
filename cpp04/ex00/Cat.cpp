#include "Cat.hpp"

Cat::Cat() {

	_type = "Kitty";
	std::cout << "Cat " << _type << " created" << std::endl;
}

Cat::Cat( const Cat &other ) {
	
	_type = other._type;
	std::cout << "Cat copy " << _type << " created" << std::endl;
}

Cat	&Cat::operator=( const Cat &other ) {

	if (this != &other) {

		_type = other._type;
		std::cout << "Cat assignement copy " << _type << " created" << std::endl;
	}
	return *this;
}

Cat::~Cat() { std::cout << "Cat " << _type << " destroyed" << std::endl; }

void	Cat::makeSound( void ) const { std::cout << "Meow" << std::endl; }
