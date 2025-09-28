#include "../includes/AForm.hpp"

// OCF

// Constructor & Destructor

AForm::AForm() : name("Default"), isSigned(false), signGrade(150), executeGrade(150)
{
	std::cout << "AForm Default Constructor Called" << std::endl;
}

AForm::AForm(std::string name, int signGrade, int executeGrade) : name(name), isSigned(false), signGrade(signGrade), executeGrade(executeGrade)
{
	std::cout << "AForm Custom Constructor Called" << std::endl;
	if (signGrade < 1 || executeGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150 || executeGrade > 150)
		throw GradeTooLowException();
}

AForm::~AForm()
{
	std::cout << "AForm Destructor Called" << std::endl;
}

// Copy Constructor & Copy Assignment Operator

AForm::AForm(AForm const &src) : name(src.name), isSigned(src.isSigned), signGrade(src.signGrade), executeGrade(src.executeGrade)
{
	std::cout << "AForm Copy Constructor Called" << std::endl;
}

AForm &AForm::operator=(AForm const &rhs)
{
	std::cout << "AForm Copy Assignment Operator Called" << std::endl;
	if (this != &rhs)
		this->isSigned = rhs.isSigned;
	return *this;
}

// Setters and Getters

std::string AForm::getName() const
{
	return this->name;
}

bool AForm::getIsSigned() const
{
	return this->isSigned;
}

int AForm::getSignGrade() const
{
	return this->signGrade;
}

int AForm::getExecuteGrade() const
{
	return this->executeGrade;
}

// Member Functions

void AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (this->getIsSigned())
	{
		std::cout << "AForm is already signed" << std::endl;
		return;
	}
	if (bureaucrat.getGrade() <= this->getSignGrade())
		this->isSigned = true;
	else
		throw GradeTooLowException();
}

// Exception Classes

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Invalid Grade: Too High";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Invalid Grade: Too Low";
}

// Operator Overloads

std::ostream &operator<<(std::ostream &out, AForm &form)
{
	out << "---AForm Info---" << std::endl;
	out << "| Name: " << form.getName() << std::endl;
	out << "| Is Signed?: " << (form.getIsSigned() ? "Yes" : "No") << std::endl;
	out << "| Sign Grade: " << form.getSignGrade() << std::endl;
	out << "| Execute Grade: " << form.getExecuteGrade() << std::endl;
	out << "---------------" << std::endl;
	return out;
}