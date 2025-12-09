#include "Brain.hpp"

Brain::Brain( void ) { std::cout << "Brain constructed" << std::endl; }

Brain::Brain( const Brain &other ) {

	for ( int i = 0; i < 100; i++ ) {

		setIdea(other.getIdea(i));
	}
	std::cout << "Brain copy constructor called" << std::endl;
}

Brain	&Brain::operator=( const Brain &other ) {

	for ( int i = 0; i < 100; i++ ) {

		setIdea(other.getIdea(i));
	}
	std::cout << "Brain assignement copy constructor called" << std::endl;
}

Brain::~Brain( void ) { std::cout << "Brain deleted" << std::endl; }

std::string	&Brain::getIdea( int id ) const { return &_ideas[i]; }

void	Brain::setIdea( const std::string &idea ) {

	static int	id = 0;

	_ideas[id] = idea;
	id++;
	if (id == 100) {
		i = 0;
	}
}
