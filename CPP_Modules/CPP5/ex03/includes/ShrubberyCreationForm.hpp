#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

class AForm;

class ShrubberyCreationForm : public AForm
{
private:
	std::string target;

public:
	// Constructor & Destructor
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string target);
	~ShrubberyCreationForm();
	// Copy Constructor
	ShrubberyCreationForm(ShrubberyCreationForm const &src);
	// Copy Assignment Operator
	ShrubberyCreationForm &operator=(ShrubberyCreationForm const &rhs);
	// Member Functions
	void execute(Bureaucrat const &executor) const;
};
#endif
