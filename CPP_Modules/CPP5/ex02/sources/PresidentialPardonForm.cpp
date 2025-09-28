#include "../includes/PresidentialPardonForm.hpp"

// OCF

// Constructor & Destructor

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Pardon", 25, 5)
{
	std::cout << "PresidentialPardonForm Default Constructor Called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential Pardon", 25, 5), target(target)
{
	std::cout << "PresidentialPardonForm Custom Constructor Called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm Destructor Called" << std::endl;
}

// Copy Constructor & Copy Assignment

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) : AForm(src), target(src.target)
{
	std::cout << "PresidentialPardonForm Copy Constructor Called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs)
{
	std::cout << "PresidentialPardonForm Copy Assignment Operator Called" << std::endl;
	if (this != &rhs)
		this->target = rhs.target;
	return *this;
}

// Member Functions

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (this->getIsSigned() && executor.getGrade() <= this->getExecuteGrade())
	{
		std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	}
	else
		throw GradeTooLowException();
}