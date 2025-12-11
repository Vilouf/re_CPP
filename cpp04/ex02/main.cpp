#include "Cat.hpp"
#include "Dog.hpp"

#include "WrongCat.hpp"

int main( void )
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const Cat	*bufCat;
	const Dog	*bufDog;

	bufDog = dynamic_cast<const Dog*>(j);
	bufDog->Think();
	bufCat = dynamic_cast<const Cat*>(i);
	bufCat->Think();

	Animal *testCat = new Cat();

	*testCat = *i;
	std::cout << "Allo" << std::endl;
	delete i;

	bufCat = dynamic_cast<const Cat*>(testCat);
	bufCat->Think();

	delete testCat;

	Animal *testDog = new Dog();

	*testDog = *j;
	std::cout << "Allo" << std::endl;
	delete j;

	bufDog = dynamic_cast<const Dog*>(testDog);
	bufDog->Think();

	delete testDog;

	// Animal *	animals[4] = { new Cat, new Dog, new Cat, new Dog };

	// const Cat	*bufCat;
	// const Dog	*bufDog;
	// for ( int i = 0; i < 4; i++ ) {

	// 	if (animals[i]->getType() == "Kitty") {

	// 		bufCat = dynamic_cast<const Cat*>(animals[i]);
	// 		bufCat->Think();
	// 	}
	// 	else {

	// 		bufDog = dynamic_cast<const Dog*>(animals[i]);
	// 		bufDog->Think();
	// 	}
	// }

	// for ( int i = 0; i < 4; i++ ) {

	// 	delete animals[i];
	// }

	return 0;
}
