#include "PhoneBook.hpp"

int main( void ) {

	PhoneBook	book;
	std::string prompt;

	while (1) {
		std::cout << "> ";
		if (std::getline(std::cin, prompt) == 0)
			return 0;
		if (prompt == "ADD") { book.PhoneBook_Add(); }
		else if (prompt == "SEARCH") { book.PhoneBook_Search(); }
		else if (prompt == "EXIT") { break; }
	}
	return 0;
}