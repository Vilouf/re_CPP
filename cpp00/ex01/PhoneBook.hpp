#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {

private:

    Contact contats[8];

public:

    PhoneBook( void );
    ~PhoneBook( void );
	void	PhoneBook_Add( void );
	void	PhoneBook_Search( void ) const;

};

#endif