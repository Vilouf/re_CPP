#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void	Harl::debug( void ) { std::cout << "Debug" << std::endl; }
void	Harl::info( void ) { std::cout << "Info" << std::endl; }
void	Harl::warning( void ) { std::cout << "Warning" << std::endl; }
void	Harl::error( void ) { std::cout << "Error" << std::endl; }

void	Harl::complain( std::string level ) {

	void		(Harl::*ptr[4])( void ) = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
	std::string	strtab[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };

	for (int i = 0; i < 4; i++) {

		if (level == strtab[i]) {

			(this->*ptr[i])();
			return ;
		}
	}
}