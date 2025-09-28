#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class AForm;

class Intern
{
public:
	// Constructor & Destructor
	Intern();
	~Intern();
	// Copy Constructor
	Intern(Intern const &src);
	// Copy Assignment Operator
	Intern &operator=(Intern const &rhs);
	// Member Functions
	AForm *makeForm(std::string name, std::string target);
};
#endif
