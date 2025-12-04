#include "ClapTrap.hpp"


ClapTrap::ClapTrap( void ) : _name("default"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {

	std::cout << "ClapTrap " << _name << " has been created" << std::endl; 
}

ClapTrap::ClapTrap( std::string name ) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {

	std::cout << "ClapTrap " << _name << " has been created" << std::endl; 
}

ClapTrap::ClapTrap( const ClapTrap & other ) : _name(other._name), _hitPoints(other._hitPoints), _energyPoints(other._energyPoints), _attackDamage(other._attackDamage) {

	std::cout << "ClapTrap copy " << _name << " has been created" << std::endl; 
}

ClapTrap	&ClapTrap::operator=( const ClapTrap & other ) {

	if (this != &other)
	{
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
		std::cout << "ClapTrap copy " << _name << " has been created" << std::endl;
	}
	return (*this);
}

ClapTrap::~ClapTrap( void ) { std::cout << "ClapTrap " << _name << " has been destroyed" << std::endl; }

void	ClapTrap::attack( const std::string & target ) {

	if ( _hitPoints > 0 ) {

		if ( _energyPoints > 0 ) {

			std::cout << "ClapTrap " << _name << " attacks " << target << " causing " << _attackDamage << " points of damage" << std::endl;
			_energyPoints--;
		}
		else {

			std::cout << "ClapTrap " << _name << " has no energy points left" << std::endl;
		}
	}
	else {

		std::cout << "ClapTrap " << _name << " has no hit points left" << std::endl;
	}
}

void	ClapTrap::takeDamage( unsigned int amount ) {

	if ( _hitPoints > 0 ) {

		if ( amount >= _hitPoints ) {

			std::cout << "ClapTrap " << _name << " recieve " << amount << " point of damage which is lethal amount of damage" << std::endl;
			_hitPoints = 0;
		}
		else {

			std::cout << "ClapTrap " << _name << " recieve " << amount << " point of damage" << std::endl;
			_hitPoints -= amount;
		}
	}
	else {

		std::cout << "ClapTrap " << _name << " was already at 0 hit points" << std::endl;
	}
}

void	ClapTrap::beRepaired( unsigned int amount ) {

	if ( _hitPoints > 0 ) {

		if ( _energyPoints > 0 ) {

			std::cout << "ClapTrap " << _name << " repair " << amount << " hit points" << std::endl;
			_hitPoints += amount;
			_energyPoints--;
		}
		else {

			std::cout << "ClapTrap " << _name << " has no energy points left" << std::endl;
		}
	}
	else {

		std::cout << "ClapTrap " << _name << " has no hit points left, it cannot be repaired" << std::endl;
	}
}