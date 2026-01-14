#include "iter.hpp"

template <typename T>
void	iterate( T &n ) { n++; }

void	printstr( const std::string &str ) { std::cout << str; }

int	main( void ) {

	int	array[] = { 1, 2, 3, 4 };

	iter(array, 4, iterate<int>);
	for (size_t i = 0; i < 4; i++)
		std::cout << array[i] << " ";
	std::cout << std::endl;

	float	floatarray[] = { 1.1, 2.2, 3.3, 4.4 };

	iter(floatarray, 4, iterate<float>);
	for (size_t i = 0; i < 4; i++)
		std::cout << floatarray[i] << " ";
	std::cout << std::endl;

	std::string	strarray[] = { "Hello ", "World" };

	iter(strarray, 2, printstr);
	std::cout << std::endl;
}