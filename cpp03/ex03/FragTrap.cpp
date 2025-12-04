#include "FragTrap.hpp"

FragTrap::FragTrap( void ) : ClapTrap() {

	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap " << _name << " has been created" << std::endl; 
}

FragTrap::FragTrap( std::string name ) : ClapTrap(name) {

	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap " << _name << " has been created" << std::endl; 
}

FragTrap::FragTrap( const FragTrap & other ) : ClapTrap(other) {

	std::cout << "FragTrap copy " << _name << " has been created" << std::endl; 
}

FragTrap	&FragTrap::operator=( const FragTrap & other ) {

	if (this != &other)
	{
		ClapTrap::operator=(other);
		std::cout << "FragTrap copy " << _name << " has been created" << std::endl;
	}
	return (*this);
}

FragTrap::~FragTrap( void ) { std::cout << "FragTrap " << _name << " has been destroyed" << std::endl; }

void	FragTrap::highFivesGuys( void ) {

	std::cout << "highFiveGuys function called by " << _name << std::endl;
}
