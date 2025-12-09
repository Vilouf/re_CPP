#include "Cat.hpp"

Cat::Cat() : _type("Cat") {

	_brain = new Brain();
	std::cout << "Cat " << _type << " created" << std::endl;
}

Cat::Cat( const Cat &other ) {
	
	_type = other._type;
	delete _brain;
	_brain = new Brain(other._brain);
	std::cout << "Cat copy " << _type << " created" << std::endl;
}

Cat	&Cat::operator=( const Cat &other ) {

	if (this != &other) {

		_type = other._type;
		delete _brain;
		_brain = new Brain(other._brain);
		std::cout << "Cat assignement copy " << _type << " created" << std::endl;
	}
	return *this;
}

Cat::~Cat() {

	delete _brain;
	std::cout << "Cat " << _type << " destroyed" << std::endl;
}

void	Cat::makeSound( void ) const { std::cout << "Meow" << std::endl; }

std::string	&Cat::getType( void ) const { return _type; }

std::string	*Cat::getIdea( int id ) const { return _brain->getIdea(id); }

void	Cat::setIdea( const std::string &idea ) { _brain->setIdea(idea); }
