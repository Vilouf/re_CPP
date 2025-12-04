#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {

private:

	std::string	_name;
	unsigned int	_hitPoints;
	unsigned int	_energyPoints;
	unsigned int	_attackDamage;

public:

	ClapTrap();
	ClapTrap( std::string );
	ClapTrap( const ClapTrap & );
	ClapTrap	&operator=( const ClapTrap & );
	~ClapTrap();

	void	attack( const std::string & target );
	void	takeDamage( unsigned int amount );
	void	beRepaired( unsigned int amount );
};


#endif