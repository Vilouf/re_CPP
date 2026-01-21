#include "easyfind.hpp"

void	list_cnt(int toFind, int len) {

	std::list<int>	V;

	for (int i = 0; i < len + 1; i++)
		V.push_back(i);
	if (easyfind(V, toFind) == true)
		std::cout << toFind << " was found in list" << std::endl;
	else
		std::cout << toFind << " has no occurence in list" << std::endl;
}

void	vector_cnt(int toFind, int len) {

	std::vector<int>	V;

	for (int i = 0; i < len + 1; i++)
		V.push_back(i);
	if (easyfind(V, toFind) == true)
		std::cout << toFind << " was found in vector" << std::endl;
	else
		std::cout << toFind << " has no occurence in vector" << std::endl;
}

void	deque_cnt(int toFind, int len) {

	std::deque<int>	D;

	for (int i = 0; i < len + 1; i++)
		D.push_back(i);
	if (easyfind(D, toFind) == true)
		std::cout << toFind << " was found in deque" << std::endl;
	else
		std::cout << toFind << " has no occurence in deque" << std::endl;
}

int	main(int ac, char **av) {

	if (ac == 3) {

		int toFind = std::atoi(av[1]);
        int len = std::atoi(av[2]);
        vector_cnt(toFind, len);
		deque_cnt(toFind, len);
		list_cnt(toFind, len);
	}
	else
		std::cout << "Usage: ./program <int_to_find> <length>" << std::endl;
}