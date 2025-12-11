#include "WrongCat.hpp"

WrongCat::WrongCat() {

	_type = "WrongKitty";
	std::cout << "WrongCat " << _type << " created" << std::endl;
}

WrongCat::WrongCat( const WrongCat &other ) {
	
	_type = other._type;
	std::cout << "WrongCat copy " << _type << " created" << std::endl;
}

WrongCat	&WrongCat::operator=( const WrongCat &other ) {

	if (this != &other) {

		_type = other._type;
		std::cout << "WrongCat assignement copy " << _type << " created" << std::endl;
	}
	return *this;
}

WrongCat::~WrongCat() { std::cout << "WrongCat " << _type << " destroyed" << std::endl; }

void	WrongCat::makeSound( void ) const { std::cout << "WrongMeow" << std::endl; }
