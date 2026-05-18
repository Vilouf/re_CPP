#include "RPN.hpp"

int main(int argc, char const *argv[]) {

	if (argc != 2) {
		std::cout << "Invalid Args" << std::endl;
		return (0);
	}
	try {
		RPN	rpn;

		std::cout << rpn.operate(argv[1]) << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
