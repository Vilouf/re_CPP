#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {

private:

	bool	_guardGuateState;

public:

	ScavTrap();
	ScavTrap( std::string );
	ScavTrap( const ScavTrap & );
	ScavTrap	&operator=( const ScavTrap & );
	~ScavTrap();

	void	attack( const std::string & target );
	void	guardGate( void );
};

#endif