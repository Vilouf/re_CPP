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

std::string	&ShrubberyCreationForm::getTarget( void ) const { return _target; }

void	ShrubberyCreationForm::execute( Bureaucrat const & executor ) const {

	if (getIsSigned() == true) {

		if (executor.getGrade() <= getExecGrade()) {

			std::ofstream	outfile(_target + "_shrubbery");
			outfile << "       _-_       " << std::endl;
			outfile << "    /~~   ~~\    " << std::endl;
			outfile << " /~~         ~~\ " << std::endl;
			outfile << "{               }" << std::endl;
			outfile << " \  _-     -_  / " << std::endl;
			outfile << "   ~  \\ //  ~   " << std::endl;
			outfile << "_- -   | | _- _  " << std::endl;
			outfile << "  _ -  | |   -_  " << std::endl;
			outfile << "      // \\      " << std::endl;
		}
		else
			throw AForm::GradeTooLowException();
	}
	else
		throw AForm::FormNotSignedException();
}
