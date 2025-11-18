#include "Contact.hpp"

Contact::Contact( void ) { }

Contact::~Contact( void ) { }

std::string	Contact::get_input( std::string str ) const {

	std::string	input;

	while (1) {

		std::cout << str << std::flush;
		if (std::getline(std::cin, input) == 0)
			break;
		if (input.empty()) {

			std::cout << "Invalid input" << std::endl;
		}
		else
			return input;
	}
	return NULL;
}

std::string	Contact::print_text( std::string str ) const {

	if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

void	Contact::init_contact( int i ) {

	try {
		this->firstName = this->get_input("Enter first name: ");
		this->lastName = this->get_input("Enter last name: ");
		this->nickName = this->get_input("Enter nick name: ");
		this->phoneNumber = this->get_input("Enter phone number: ");
		this->darkestSecret = this->get_input("Enter darkest secret: ");
	}
	catch (std::logic_error &e) {

		return ;
	}
	this->index = i;
}

void	Contact::view_contact( void ) const {

	if (this->firstName.empty())
		return ;
	std::cout << "|" << std::setw(10) << this->index + 1;
	std::cout << "|" << std::setw(10) << this->print_text(this->firstName);
	std::cout << "|" << std::setw(10) << this->print_text(this->lastName);
	std::cout << "|" << std::setw(10) << this->print_text(this->nickName) << "|" << std::endl;
}

void	Contact::display_contact( void ) const {

	if (this->firstName.empty()) {

		std::cout << "This contact does not exist" << std::endl;
		return ;
	}
	std::cout << "first name: " << this->firstName << std::endl;
	std::cout << "last name: " << this->lastName << std::endl;
	std::cout << "nick name: " << this->nickName << std::endl;
	std::cout << "phone number: " << this->phoneNumber << std::endl;
	std::cout << "darkest secret: " << this->darkestSecret << std::endl;
}

int	Contact::check_contact( void ) const { return this->firstName.empty(); }