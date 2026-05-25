#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe & other) : _vector(other._vector), _list(other._list) {}

PmergeMe &PmergeMe::operator=(const PmergeMe & other) {

	if (this != &other) {
		_vector = other._vector;
		_list = other._list;
	}
	return *this;

}

PmergeMe::~PmergeMe() {}

const char*	PmergeMe::InputErrorException::what() const throw() { return "Error: Invalid input"; }

void	PmergeMe::Parsing(int argc, char const *argv[]) {

    for (int i = 1; i < argc; ++i) {

        std::istringstream iss(argv[i]);
        std::string token;

        while (iss >> token) {

			if (token.size() > 10)
				throw InputErrorException();
            char *end;
            long value = std::strtol(token.c_str(), &end, 10);

            if (token.empty() || *end != 0 || value < 0 || value > std::numeric_limits<int>::max())
                throw InputErrorException();

            _vector.push_back(static_cast<int>(value));
            _list.push_back(static_cast<int>(value));
        }
    }
	if (_vector.empty())
		throw InputErrorException();
}

void	PmergeMe::PrintContainers( void ) {

	std::vector<int>::iterator itv = _vector.begin();

	std::cout << "vector container: ";
	while (itv != _vector.end()) {

		std::cout << " " << *itv;
		itv++;
	}
	std::cout << std::endl;

	std::list<int>::iterator itl = _list.begin();

	std::cout << "list container: ";
	while (itl != _list.end()) {

		std::cout << " " << *itl;
		itl++;
	}
	std::cout << std::endl;
}
