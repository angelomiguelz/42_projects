#ifndef PRESIDENTIAL_PARDON_FORM_HPP
#define PRESIDENTIAL_PARDON_FORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class AForm;

class PresidentialPardonForm : public AForm
{
private:
	std::string target;

public:
	// Constructor & Destructor
	PresidentialPardonForm();
	PresidentialPardonForm(std::string target);
	~PresidentialPardonForm();
	// Copy Constructor
	PresidentialPardonForm(PresidentialPardonForm const &src);
	// Copy Assignment Operator
	PresidentialPardonForm &operator=(PresidentialPardonForm const &rhs);
	// Member Functions
	void execute(Bureaucrat const &executor) const;
};
#endif
