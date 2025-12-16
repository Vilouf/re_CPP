#include "Character.hpp"
#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main( void )
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;

	delete src;

	// IMateriaSource* src = new MateriaSource();
	// src->learnMateria(new Ice());
	// src->learnMateria(new Cure());

	// ICharacter* toto = new Character("Sephiroth");
	// ICharacter* me = new Character("Cloud");
	// AMateria* tmp;

	// tmp = src->createMateria("ice");
	// me->equip(tmp);

	// tmp = src->createMateria("ice");
	// me->equip(tmp);

	// tmp = src->createMateria("ice");
	// me->equip(tmp);

	// tmp = src->createMateria("ice");
	// me->equip(tmp);

	// tmp = src->createMateria("ice");
	// me->equip(tmp);
	// delete tmp;
	// me->unequip(3);

	// tmp = src->createMateria("cure");

	// me->equip(tmp);
	// me->use(3, *toto);

	// me->unequip(3);
	// tmp = src->createMateria("cure");
	// me->equip(tmp);
	// toto->equip(tmp);

	// me->use(0, *toto);
	// me->use(1, *toto);
	// me->use(3, *toto);

	// delete toto;
	// delete me;
	// delete src;
	return (0);
}
