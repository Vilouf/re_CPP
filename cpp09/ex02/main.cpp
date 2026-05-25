#include "PmergeMe.hpp"

int main(int argc, char const *argv[]) {

	try {

		PmergeMe	pmm;

		pmm.Parsing(argc, argv);
		pmm.PrintContainers();
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
