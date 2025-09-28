#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class AForm;

class RobotomyRequestForm : public AForm
{
private:
	std::string target;

public:
	// Constructor & Destructor
	RobotomyRequestForm();
	RobotomyRequestForm(std::string target);
	~RobotomyRequestForm();
	// Copy Constructor
	RobotomyRequestForm(RobotomyRequestForm const &src);
	// Copy Assignment Operator
	RobotomyRequestForm &operator=(RobotomyRequestForm const &rhs);
	// Member Functions
	void execute(Bureaucrat const &executor) const;
};
#endif
