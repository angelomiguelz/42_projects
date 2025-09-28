#include "../includes/Form.hpp"

// OCF

// Constructor & Destructor

Form::Form() : name("Default"), isSigned(false), signGrade(150), executeGrade(150)
{
	std::cout << "Form Default Constructor Called" << std::endl;
}

Form::Form(std::string name, int signGrade, int executeGrade) : name(name), isSigned(false), signGrade(signGrade), executeGrade(executeGrade)
{
	std::cout << "Form Custom Constructor Called" << std::endl;
	if (signGrade < 1 || executeGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150 || executeGrade > 150)
		throw GradeTooLowException();
}

Form::~Form()
{
	std::cout << "Form Destructor Called" << std::endl;
}

// Copy Constructor & Copy Assignment Operator

Form::Form(Form const &src) : name(src.name), isSigned(src.isSigned), signGrade(src.signGrade), executeGrade(src.executeGrade)
{
	std::cout << "Form Copy Constructor Called" << std::endl;
}

Form &Form::operator=(Form const &rhs)
{
	std::cout << "Form Copy Assignment Operator Called" << std::endl;
	if (this != &rhs)
		this->isSigned = rhs.isSigned;
	return *this;
}

// Setters and Getters

std::string Form::getName() const
{
	return this->name;
}

bool Form::getIsSigned() const
{
	return this->isSigned;
}

int Form::getSignGrade() const
{
	return this->signGrade;
}

int Form::getExecuteGrade() const
{
	return this->executeGrade;
}

// Member Functions

void Form::beSigned(Bureaucrat &bureaucrat)
{
	if (this->getIsSigned())
	{
		std::cout << "Form is already signed" << std::endl;
		return;
	}
	if (bureaucrat.getGrade() <= this->getSignGrade())
		this->isSigned = true;
	else
		throw GradeTooLowException();
}

// Exception Classes

const char *Form::GradeTooHighException::what() const throw()
{
	return "Invalid Grade: Too High";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Invalid Grade: Too Low";
}

// Operator Overloads

std::ostream &operator<<(std::ostream &out, Form &form)
{
	out << "---Form Info---" << std::endl;
	out << "| Name: " << form.getName() << std::endl;
	out << "| Is Signed?: " << (form.getIsSigned() ? "Yes" : "No") << std::endl;
	out << "| Sign Grade: " << form.getSignGrade() << std::endl;
	out << "| Execute Grade: " << form.getExecuteGrade() << std::endl;
	out << "---------------" << std::endl;
	return out;
}