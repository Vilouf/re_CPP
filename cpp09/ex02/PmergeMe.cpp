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

void	PmergeMe::CheckDuplicate( void ) {

	std::vector<int>	check(_vector);
	std::sort( check.begin(), check.end() );
	if (std::adjacent_find(check.begin(), check.end()) != check.end())
        throw InputErrorException();
}

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
	CheckDuplicate();
}

std::vector<int>	PmergeMe::getVector( void ) { return _vector; }
std::list<int>	PmergeMe::getList( void ) { return _list; }

void 	PmergeMe::setVector( std::vector<int> vec ) { _vector = vec; }
void 	PmergeMe::setList( std::list<int> lst ) { _list = lst; }

void	PmergeMe::PrintVector( void ) {

	std::vector<int>::iterator itv = _vector.begin();

	while (itv != _vector.end()) {

		std::cout << " " << *itv;
		itv++;
	}
	std::cout << std::endl;
}

void	PmergeMe::PrintList( void ) {

	std::list<int>::iterator itl = _list.begin();

	while (itl != _list.end()) {

		std::cout << " " << *itl;
		itl++;
	}
	std::cout << std::endl;
}
