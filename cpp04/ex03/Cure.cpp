#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::Cure( const Cure &other ) : AMateria(other) {}

Cure	&Cure::operator=( const Cure &other ) {

	(void) other;
	std::cout << GREEN("Materia copy asignment ") << GREEN(_type) << GREEN(" created") << std::endl;
	return *this;
}

Cure::~Cure() {}

AMateria	*Cure::clone( void ) const { return new Cure(); }

void	Cure::use( ICharacter &target ) { std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl; }
