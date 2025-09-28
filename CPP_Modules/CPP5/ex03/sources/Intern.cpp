#include "../includes/Intern.hpp"

// OCF

// Constructor & Destructor

Intern::Intern()
{
	std::cout << "Intern Default Constructor Called" << std::endl;
}

Intern::~Intern()
{
	std::cout << "Intern Destructor Called" << std::endl;
}

// Copy Constructor & Copy Assignment

Intern::Intern(Intern const &src)
{
	std::cout << "Intern Copy Constructor Called" << std::endl;
	(void)src;
}

Intern &Intern::operator=(Intern const &rhs)
{
	std::cout << "Intern Copy Assignment Operator Called" << std::endl;
	(void)rhs;
	return *this;
}

// Member Functions

AForm *Intern::makeForm(std::string name, std::string target)
{
	std::string formNames[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm *form = NULL;

	for (int i = 0; i < 3; i++)
	{
		if (name == formNames[i])
		{
			switch (i)
			{
			case 0:
				form = new ShrubberyCreationForm(target);
				break;
			case 1:
				form = new RobotomyRequestForm(target);
				break;
			case 2:
				form = new PresidentialPardonForm(target);
				break;
			}
			std::cout << "Intern creates " << name << " form" << std::endl;
			return form;
		}
	}
	std::cout << "Intern cannot create " << name << " form" << std::endl;
	return NULL;
}
