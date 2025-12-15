#include "AMateria.hpp"

AMateria::AMateria( const std::string &type ) : _type(type), _isEquipped(false) { std::cout << GREEN("Materia ") << GREEN(_type) << GREEN(" created") << std::endl; }

AMateria::AMateria( const AMateria &other ) : _type(other._type), _isEquipped(false) {

	std::cout << GREEN("Materia copy ") << GREEN(_type) << GREEN(" created") << std::endl;
}

AMateria	&AMateria::operator=( const AMateria &other ) {

	(void) other;
	std::cout << GREEN("Materia copy assignment ") << GREEN(_type) << GREEN(" created") << std::endl;
	return *this;
}

AMateria::~AMateria() { std::cout << RED("Materia ") << RED(_type) << RED(" destroyed") << std::endl; }

std::string const	&AMateria::getType( void ) const { return _type; }

void	AMateria::setEquipped( bool isEquipped ) { _isEquipped = isEquipped; }

bool	AMateria::getEquipped() { return _isEquipped; }

void	AMateria::use( ICharacter &target ) {(void)target;}
