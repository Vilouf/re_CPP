#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {

private:

	std::string	_name;

public:

	DiamondTrap();
	DiamondTrap( std::string );
	DiamondTrap( const DiamondTrap & );
	DiamondTrap	&operator=( const DiamondTrap & );
	~DiamondTrap();

	void	WhoAmI( void );
};

#endif