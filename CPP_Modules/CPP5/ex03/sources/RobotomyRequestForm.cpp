#include "../includes/RobotomyRequestForm.hpp"

// OCF

// Constructor & Destructor

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request", 72, 45), target("default")
{
	std::cout << "RobotomyRequestForm Default Constructor Called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy Request", 72, 45), target(target)
{
	std::cout << "RobotomyRequestForm Custom Constructor Called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm Destructor Called" << std::endl;
}

// Copy Constructor & Copy Assignment Operator

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) : AForm(src), target(src.target)
{
	std::cout << "RobotomyRequestForm Copy constructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
	std::cout << "RobotomyRequestForm Copy Assignment Operator Called" << std::endl;
	if (this != &rhs)
		this->target = rhs.target;
	return *this;
}

// Member Functions

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (this->getIsSigned() && executor.getGrade() <= this->getExecuteGrade())
	{
		std::cout << std::endl
				  << "Drilling Noises :V" << std::endl;
		bool chance = (rand() % 2) != 0;
		std::cout << (chance ? (this->target + " Has Been Robotomized") : "Robotomy Failed") << std::endl;
	}
	else
		throw GradeTooLowException();
}