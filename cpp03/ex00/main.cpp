#include "ClapTrap.hpp"

int main()
{
	ClapTrap	a("1");
	ClapTrap	b("2");
	ClapTrap	test;

	test = a;
	test.attack("2");
	b.takeDamage(0);
	b.beRepaired(0);
	return 0;
}
