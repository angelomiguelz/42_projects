#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string name;
	bool isSigned;
	const int signGrade;
	const int executeGrade;

public:
	// Exception Classes
	class GradeTooHighException : public std::exception
	{
		const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		const char *what() const throw();
	};
	// Constructor & Destructor
	Form();
	Form(std::string name, int signGrade, int executeGrade);
	~Form();
	// Copy Constructor
	Form(Form const &src);
	// Copy Assignment Operator
	Form &operator=(Form const &rhs);
	// Settes and Getters
	std::string getName() const;
	bool getIsSigned() const;
	int getSignGrade() const;
	int getExecuteGrade() const;
	// Member Functions
	void beSigned(Bureaucrat &bureaucrat);
};

// Operator Overloads
std::ostream &operator<<(std::ostream &out, Form &form);

#endif
