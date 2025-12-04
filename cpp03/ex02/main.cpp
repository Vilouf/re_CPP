#include "FragTrap.hpp"

int main()
{
	FragTrap	a("1");
	FragTrap	b("2");
	FragTrap	test;

	ClapTrap	c("3");

	test = a;
	test.attack("2");
	b.takeDamage(30);
	b.takeDamage(30);
	b.takeDamage(30);
	b.takeDamage(30);
	b.takeDamage(30);
	b.beRepaired(10);
	test.highFivesGuys();

	return 0;
}
