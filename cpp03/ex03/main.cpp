#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap	a("1");
	DiamondTrap	b("2");
	DiamondTrap	test;

	test = a;
	test.attack("2");
	b.takeDamage(30);
	b.takeDamage(30);
	b.takeDamage(30);
	b.takeDamage(30);
	b.takeDamage(30);
	b.beRepaired(10);
	test.highFivesGuys();

	test.WhoAmI();
	return 0;
}
