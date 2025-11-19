#include <iostream>
#include <fstream>

int main(int argc, char const *argv[]) {

	if (argc != 4) {

		std::cout << "Args Error" << std::endl;
		return (1);
	}

	std::ifstream	file(argv[1]);
	std::string	s1 = argv[2];
	std::string s2 = argv[3];
	std::string	line;

	while (std::getline(file, line)) {

		std::cout << line;
	}
}
