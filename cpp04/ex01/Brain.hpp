#pragma once

#include <iostream>

class Brain {

private:

	std::string	_ideas[100];

public:

	Brain();
	Brain( const Brain & );
	Brain	&operator=( const Brain & );
	~Brain();

	std::string	*getIdea( int ) const;
	void	setIdea( const std::string & );
};