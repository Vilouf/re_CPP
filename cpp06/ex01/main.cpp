#include "Serializer.hpp"
#include <sstream>
#include <iomanip>

int	main ( void ) {

	Data	*test = new Data();
	uintptr_t	ptr;

	std::cout << "Data pointer value: " << test << std::endl;
	std::cout << "Data value: " << test->getValue() << std::endl;

	ptr = Serializer::serialize(test);

	std::cout << "uintptr_t pointer value: " << std::hex << "Ox" << ptr << std::dec << std::endl;

	test = Serializer::deserialize(ptr);

	std::cout << "Data pointer value: " << test << std::endl;
	std::cout << "Data value: " << test->getValue() << std::endl;

	test->setValue(21);

	std::cout << "Data pointer value: " << test << std::endl;
	std::cout << "Data value: " << test->getValue() << std::endl;

	ptr = Serializer::serialize(test);

	std::cout << "uintptr_t pointer value: " << std::hex << "Ox" << ptr << std::dec << std::endl;

	test = Serializer::deserialize(ptr);

	std::cout << "Data pointer value: " << test << std::endl;
	std::cout << "Data value: " << test->getValue() << std::endl;

	delete test;
}