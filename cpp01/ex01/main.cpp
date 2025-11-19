#include "Zombie.hpp"

int main()
{
	int	n = 5;
	Zombie	*test = zombieHorde(n, "horde");

	for (int i = 0; i < n; i++)
	{
		test[i].announce();
	}
	delete[] test;
}
