#include "Cat.hpp"
#include "Dog.hpp"

#include "WrongCat.hpp"

int main( void )
{
	const Animal*	meta = new Animal();
	const Animal*	j = new Dog();
	const Animal*	i = new Cat();

	std::cout << j->getType() << std::endl;
	std::cout << i->getType() << std::endl;

	i->makeSound();
	j->makeSound();
	meta->makeSound();

	delete i;
	delete j;
	delete meta;

	const WrongAnimal* fake = new WrongCat();

	std::cout << fake->getType() << std::endl;

	fake->makeSound();

	delete fake;
	return 0;
}
