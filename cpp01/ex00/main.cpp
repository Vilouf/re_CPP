#include "Zombie.hpp"

int main()
{
	Zombie	*test = newZombie("jsp");

	test->announce();

	delete test;

	randomChump("jsp2");
}
