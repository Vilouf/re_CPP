#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <iomanip>

class Contact {

private:

	std::string firstName, lastName, nickName, phoneNumber, darkestSecret;
	int	index;

	std::string	get_input( std::string str ) const;
	std::string	print_text( std::string str ) const;

public:

	Contact( void );
	~Contact( void );
	void	init_contact( int i );
	void		view_contact( void ) const;
	void	display_contact( void ) const;
	int		check_contact( void ) const;

};

#endif
