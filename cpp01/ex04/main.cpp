#include <iostream>
#include <fstream>

int main(int argc, char const *argv[]) {

	if (argc != 4) {

		std::cout << "Args Error" << std::endl;
		return (1);
	}

	std::ifstream	file(argv[1]);
	std::string	strFind = argv[2], strReplace = argv[3], newFile = argv[1], line;
	size_t	i = 0, nl = 0;

	newFile.append(".replace");
	std::ofstream	outfile(newFile.data());
	while (std::getline(file, line)) {

		if (nl != 0)
			outfile << std::endl;
		nl = 1;
		while ((i = line.find(strFind, i)) != (unsigned long)-1) {

			line.insert(i, strReplace);
			line.erase(i + strReplace.length(), strFind.length());
		}
		if (!line.empty())
			outfile << line;
		i = 0;
	}
}
