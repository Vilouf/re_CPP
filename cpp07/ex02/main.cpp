#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
	Array<float> numbers(5);

	for (int i = 0; i < static_cast<int>(numbers.size()); i++) {
		numbers[i] = i + static_cast<float>(i) / 10;
	}

	// try {std::cout << numbers[-1] << std::endl;}
	// catch(...) {return 1;}
	

	Array<float>	test(numbers);

	test[3] = 10.15;
	try {
		for (int i = 0; i < static_cast<int>(numbers.size()) + 3; i++) {
			std::cout << numbers[i] << ", " << test[i] << std::endl;
		}
	}
	catch(const std::exception &e) {
		std::cout << e.what() << std::endl;
	}


    // Array<int> numbers(MAX_VAL);
    // int* mirror = new int[MAX_VAL];
    // srand(time(NULL));
    // for (int i = 0; i < MAX_VAL; i++)
    // {
    //     const int value = rand();
    //     numbers[i] = value;
    //     mirror[i] = value;
    // }
    // //SCOPE
    // {
    //     Array<int> tmp = numbers;
    //     Array<int> test(tmp);
    // }

    // for (int i = 0; i < MAX_VAL; i++)
    // {
	// 	std::cout << numbers[i] << " ";
    //     if (mirror[i] != numbers[i])
    //     {
    //         std::cerr << "didn't save the same value!!" << std::endl;
    //         return 1;
    //     }
    // }
	// std::cout << std::endl;
    // try
    // {
    //     numbers[-2] = 0;
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }
    // try
    // {
    //     numbers[MAX_VAL] = 0;
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }

    // for (int i = 0; i < MAX_VAL; i++)
    // {
    //     numbers[i] = rand();
    // }
    // delete [] mirror;
    return 0;
}