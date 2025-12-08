#include "Contact.hpp"

Contact::Contact( void ) { }

Contact::~Contact( void ) { }

int	is_input_printable( std::string input ) {

	for ( size_t i = 0; i < input.length() ; i++ ) {

		if (std::isprint(input[i]) == 0)
			return (0);
	}
	return (1);
}

std::string	Contact::get_input( std::string str ) const {

	std::string	input;

	while (1) {

		std::cout << str << std::flush;
		if (std::getline(std::cin, input) == 0)
			std::exit(1);
		if (input.empty() || is_input_printable(input) == 0) {

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

	firstName = get_input("Enter first name: ");
	lastName = get_input("Enter last name: ");
	nickName = get_input("Enter nick name: ");
	phoneNumber = get_input("Enter phone number: ");
	darkestSecret = get_input("Enter darkest secret: ");
	index = i;
}

void	Contact::view_contact( void ) const {

	if (firstName.empty())
		return ;
	std::cout << "|" << std::setw(10) << index + 1;
	std::cout << "|" << std::setw(10) << print_text(firstName);
	std::cout << "|" << std::setw(10) << print_text(lastName);
	std::cout << "|" << std::setw(10) << print_text(nickName) << "|" << std::endl;
}

void	Contact::display_contact( void ) const {

	if (firstName.empty()) {

		std::cout << "This contact does not exist" << std::endl;
		return ;
	}
	std::cout << "first name: " << firstName << std::endl;
	std::cout << "last name: " << lastName << std::endl;
	std::cout << "nick name: " << nickName << std::endl;
	std::cout << "phone number: " << phoneNumber << std::endl;
	std::cout << "darkest secret: " << darkestSecret << std::endl;
}

int	Contact::check_contact( void ) const { return firstName.empty(); }