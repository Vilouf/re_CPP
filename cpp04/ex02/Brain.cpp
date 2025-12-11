#include "Brain.hpp"

Brain::Brain() {

	for (int i = 0; i < 100; i++)
		_ideas[i] = "idea";
	std::cout << "Brain created" << std::endl;
}

Brain::Brain( const Brain &other ) {
	
	for (int i = 0; i < 100; i++)
		_ideas[i] = other._ideas[i];
	std::cout << "Brain copy created" << std::endl;
}

Brain	&Brain::operator=( const Brain &other ) {

	if (this != &other) {

		for (int i = 0; i < 100; i++)
			_ideas[i] = other._ideas[i];
		std::cout << "Brain assignement copy created" << std::endl;
	}
	return *this;
}

Brain::~Brain() { std::cout << "Brain destroyed" << std::endl; }

std::string	Brain::getIdea( int id ) const { return _ideas[id]; }
