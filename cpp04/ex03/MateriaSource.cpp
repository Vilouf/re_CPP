#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {

	for (int i = 0; i < 4; i++) {

		_source[i] = NULL;
	}
	std::cout << GREEN("MateriaSource created") << std::endl;
}

MateriaSource::MateriaSource( const MateriaSource &other ) {

	for (int i = 0; i < 4; i++) {

		_source[i] = other._source[i];
	}
	std::cout << GREEN("MateriaSource copy created") << std::endl;
}

MateriaSource	&MateriaSource::operator=( const MateriaSource &other ) {

	if (this != &other) {

		for (int i = 0; i < 4; i++) {

			if (_source[i])
				delete _source[i];
			_source[i] = other._source[i];
		}
		std::cout << GREEN("MateriaSource copy assignment created") << std::endl;
	}
	return *this;
}

MateriaSource::~MateriaSource() {

	for (int i = 0; i < 4; i++) {

		if (_source[i])
			delete _source[i];
	}
	std::cout << RED("MateriaSource deleted") << std::endl;
}

void	MateriaSource::learnMateria( AMateria *m ) {

	if (!m) {

		std::cout << "Materia must exist" << std::endl;
	}
	else {

		for (int i = 0; i < 4; i++) {

			if (!_source[i]) {

				_source[i] = m;
				return ;
			}
		}
		std::cout << "Materia source is full" << std::endl;
	}
}

AMateria	*MateriaSource::createMateria( std::string const & type ) {

	for (int i = 0; i < 4; i++) {

		if (_source[i]->getType() == type) {
			
			return _source[i]->clone();
		}
	}
	if (type == "ice" || type == "cure"){

		std::cout << "Materia source has no Materia of this type" << std::endl;
	}
	else {

		std::cout << "Materia of this type doesn't exist" << std::endl;
	}
	return 0;
}
