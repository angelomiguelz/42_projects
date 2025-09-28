#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
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
	AForm();
	AForm(std::string name, int signGrade, int executeGrade);
	virtual ~AForm();
	// Copy Constructor
	AForm(AForm const &src);
	// Copy Assignment Operator
	AForm &operator=(AForm const &rhs);
	// Setters and Getters
	std::string getName() const;
	bool getIsSigned() const;
	int getSignGrade() const;
	int getExecuteGrade() const;
	// Member Functions
	void beSigned(Bureaucrat &bureaucrat);
	// Pure Virtual Function
	virtual void execute(Bureaucrat const &executor) const = 0;
};

// Operator Overloads
std::ostream &operator<<(std::ostream &out, AForm &form);

#endif
