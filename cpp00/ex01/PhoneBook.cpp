#include "PhoneBook.hpp"

PhoneBook::PhoneBook( void ) { }

PhoneBook::~PhoneBook( void ) { }

void	PhoneBook::PhoneBook_Add( void ) {

	static int	index = 0;

	contats[index % 8].init_contact(index % 8);
	index++;
}

void	PhoneBook::PhoneBook_Search( void ) const {

	std::string	input;
	int			n_input;
	bool		valid = false;

	if (contats[0].check_contact()) {

		std::cout << "Phonebook has no contact in it!" << std::endl;
		return ;
	}
	else {

		std::cout << "|----------|----------|----------|----------|" << std::endl;
		std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
		std::cout << "|----------|----------|----------|----------|" << std::endl;
		for (int i = 0; i < 8; i++) {

			contats[i].view_contact();
			std::cout << "|----------|----------|----------|----------|" << std::endl;
		}
		std::cout << std::endl;
	}
	while (!valid) {

		std::cout << "select an index: ";
		if (std::getline(std::cin, input) == 0)
			return ;
		if (input.size() != 1) {

			std::cout << "Input error" << std::endl;
		}
		else {

			n_input = input[0] - 48;
			if (n_input >= 1 && n_input <= 8) {

				valid = true;
			}
			else {

				std::cout << "Invalid index" << std::endl;
			}
		}
	}
	std::cout << std::endl;
	contats[n_input - 1].display_contact();

}