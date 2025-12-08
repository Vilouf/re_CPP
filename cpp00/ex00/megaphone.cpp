#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

int main( int ac, char *av[] ) {

	std::string test;

	if (ac < 2) {

		std::cout << "PLEASE ENTER ARGUMENTS!!!!!!";
	}
	for (int i = 1; i < ac; i++) {
		test = av[i];
		std::transform(test.begin(), test.end(), test.begin(), ::toupper);
		std::cout << test << " ";
	}
	std::cout << std::endl;
}