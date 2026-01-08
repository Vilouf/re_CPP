#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( const std::string &target ) : AForm("Shrubbery", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm &other ) : AForm(other), _target(other._target) {}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=( const ShrubberyCreationForm &other ) {

	if (this != &other) {

		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

const std::string	&ShrubberyCreationForm::getTarget( void ) const { return _target; }

void	ShrubberyCreationForm::beExecuted() const {

	std::string	fileName = _target + "_shrubbery";
	std::ofstream	outfile(fileName.c_str());
	outfile << "       _-_              _-_" << std::endl;
	outfile << "    /~~   ~~\\        /~~   ~~\\" << std::endl;
	outfile << " /~~         ~~\\  /~~         ~~\\" << std::endl;
	outfile << "{               }{               }" << std::endl;
	outfile << " \\  _-     -_  /  \\  _-     -_  /" << std::endl;
	outfile << "   ~  \\\\ //  ~      ~  \\\\ //  ~" << std::endl;
	outfile << "_- -   | | _- _  _- -   | | _- _" << std::endl;
	outfile << "  _ -  | |   -_    _ -  | |   -_" << std::endl;
	outfile << "      // \\\\            // \\\\" << std::endl;
}
