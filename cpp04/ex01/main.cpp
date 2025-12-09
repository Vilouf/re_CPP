#include "Cat.hpp"
#include "Dog.hpp"

#include "WrongCat.hpp"

int main( void )
{
	// const Animal*	meta = new Animal();
	// const Animal*	j = new Dog();
	// const Animal*	i = new Cat();

	// std::cout << j->getType() << std::endl;
	// std::cout << i->getType() << std::endl;

	// i->makeSound();
	// j->makeSound();
	// meta->makeSound();

	// delete i;
	// delete j;
	// delete meta;

	// const WrongAnimal* fake = new WrongCat();

	// std::cout << fake->getType() << std::endl;

	// fake->makeSound();

	// delete fake;

	Animal* j = new Dog();
	Animal* i = new Cat();

	i->setIdea("testCat");
	j->setIdea("testDog");

	std::cout << *(i->getIdea(0)) << std::endl;
	std::cout << *(j->getIdea(0)) << std::endl;

	delete j;
	delete i;

	return 0;
}
