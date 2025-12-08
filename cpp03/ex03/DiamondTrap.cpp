#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void ) : ClapTrap() {

	_name = ClapTrap::_name + "_clap_name";
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
	std::cout << "DiamondTrap " << _name << " has been created" << std::endl; 
}

DiamondTrap::DiamondTrap( std::string name ) : ClapTrap(name) {

	_name = ClapTrap::_name + "_clap_name";
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
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

void	DiamondTrap::WhoAmI( void ) {

	std::cout << "ClapTrap's name: " << ClapTrap::_name << std::endl;
	std::cout << "DiamondTrap's name: " << _name << std::endl;
}
