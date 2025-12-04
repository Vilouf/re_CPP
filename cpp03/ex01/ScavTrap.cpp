#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void ) : ClapTrap(), _guardGuateState(false) {

	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap " << _name << " has been created" << std::endl; 
}

ScavTrap::ScavTrap( std::string name ) : ClapTrap(name), _guardGuateState(false) {

	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap " << _name << " has been created" << std::endl; 
}

ScavTrap::ScavTrap( const ScavTrap & other ) : ClapTrap(other), _guardGuateState(other._guardGuateState) {

	std::cout << "ScavTrap copy " << _name << " has been created" << std::endl; 
}

ScavTrap	&ScavTrap::operator=( const ScavTrap & other ) {

	if (this != &other)
	{
		ClapTrap::operator=(other);
		_guardGuateState = other._guardGuateState;
		std::cout << "ScavTrap copy " << _name << " has been created" << std::endl;
	}
	return (*this);
}

ScavTrap::~ScavTrap( void ) { std::cout << "ScavTrap " << _name << " has been destroyed" << std::endl; }

void	ScavTrap::attack( const std::string & target ) {

	if ( _hitPoints > 0 ) {

		if ( _energyPoints > 0 ) {

			std::cout << "ScavTrap " << _name << " attacks " << target << " causing " << _attackDamage << " points of damage" << std::endl;
			_energyPoints--;
		}
		else {

			std::cout << "ScavTrap " << _name << " has no energy points left" << std::endl;
		}
	}
	else {

		std::cout << "ScavTrap " << _name << " has no hit points left" << std::endl;
	}
}

void	ScavTrap::guardGate( void ) {

	if ( _hitPoints > 0) {

		if ( _guardGuateState == true ) {

			std::cout << "ScavTrap " << _name << " is no longer in Gate keeper mode" << std::endl;
			_guardGuateState = false;
		}
		else {	

			std::cout << "ScavTrap " << _name << " is now in Gate keeper mode" << std::endl;
			_guardGuateState = true;
		}
	}
	else {

		std::cout << "Gate keeper mode? ScavTrap " << _name << " is DEAD" << std::endl;
	}
}
