#include "Cat.hpp"

Cat::Cat() {
	
	_type = "Kitty";
	_brain = new Brain();
	std::cout << "Cat " << _type << " created" << std::endl;
}

Cat::Cat( const Cat &other ) {
	
	_type = other._type;
	_brain = new Brain(*other._brain);
	std::cout << "Cat copy " << _type << " created" << std::endl;
}

Cat	&Cat::operator=( const Cat &other ) {

	if (this != &other) {

		_type = other._type;
		delete _brain;
		_brain = new Brain(*other._brain);
		std::cout << "Cat asignment copy " << _type << " created" << std::endl;
	}
	return *this;
}

Cat::~Cat() {
	
	delete _brain;
	std::cout << "Cat " << _type << " destroyed" << std::endl;
}

void	Cat::makeSound( void ) const { std::cout << "Meow" << std::endl; }

void	Cat::Think( void ) const {

	for (int i = 0; i < 100; i++)
		std::cout << _brain->getIdea(i);
	std::cout << std::endl;
}
