#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::Ice( const Ice &other ) : AMateria(other) {}

Ice	&Ice::operator=( const Ice &other ) {

	(void) other;
	std::cout << GREEN("Materia copy asignment ") << GREEN(_type) << GREEN(" created") << std::endl;
	return *this;
}

Ice::~Ice() {}

AMateria	*Ice::clone( void ) const { return new Ice(); }

void	Ice::use( ICharacter &target ) { std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl; }
