#include "../includes/ShrubberyCreationForm.hpp"

// OCF

// Constructor & Destructor

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation", 145, 137)
{
	std::cout << "ShrubberyCreationForm Default constructor called" << std::endl;
	this->target = "default";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery Creation", 145, 137)
{
	std::cout << "ShrubberyCreationForm Custom constructor called" << std::endl;
	this->target = target;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm Destructor called" << std::endl;
}

// Copy Constructor & Copy Assignment Operator

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) : AForm(src)
{
	std::cout << "ShrubberyCreationForm Copy constructor called" << std::endl;
	this->target = src.target;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
	std::cout << "ShrubberyCreationForm Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->target = rhs.target;
	return *this;
}

// Member Functions
void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (this->getIsSigned() && executor.getGrade() <= this->getExecuteGrade())
	{
		std::string fname = this->target + "_shrubbery";
		std::ofstream file(fname);
		file << std::endl;
		file << "               ,@@@@@@@," << std::endl;
		file << "       ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl;
		file << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl;
		file << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl;
		file << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl;
		file << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl;
		file << "   `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl;
		file << "       |o|        | |         | |" << std::endl;
		file << "       |.|        | |         | |" << std::endl;
		file << "jgs \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_" << std::endl;
		file.close();
	}
	else
		throw GradeTooLowException();
}
