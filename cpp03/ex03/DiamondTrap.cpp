#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void ) : ClapTrap() {

	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 30;
	this->_name = _name.append("_clap_name");
	std::cout << "DiamondTrap " << _name << " has been created" << std::endl; 
}

DiamondTrap::DiamondTrap( std::string name ) : ClapTrap(name) {

	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 30;
	this->_name = _name.append("_clap_name");
	std::cout << "DiamondTrap " << _name << " has been created" << std::endl; 
}

DiamondTrap::DiamondTrap( const DiamondTrap & other ) : ClapTrap(other) {

	this->_name = other._name;
	std::cout << "DiamondTrap copy " << _name << " has been created" << std::endl; 
}

DiamondTrap	&DiamondTrap::operator=( const DiamondTrap & other ) {

	if (this != &other)
	{
		ClapTrap::operator=(other);
		this->_name = other._name;
		std::cout << "DiamondTrap copy " << _name << " has been created" << std::endl;
	}
	return (*this);
}

DiamondTrap::~DiamondTrap( void ) { std::cout << "DiamondTrap " << _name << " has been destroyed" << std::endl; }
