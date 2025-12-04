#include "ScavTrap.hpp"

int main()
{
	ScavTrap	a("1");
	ScavTrap	b("2");
	ScavTrap	test;

	ClapTrap	c("3");

	test = a;
	test.attack("2");
	b.takeDamage(20);
	b.takeDamage(20);
	b.takeDamage(20);
	b.takeDamage(20);
	b.takeDamage(20);
	b.takeDamage(20);
	b.beRepaired(10);
	test.guardGate();
	test.guardGate();
	test.guardGate();

	return 0;
}
