#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
private:
	const std::string name;
	int grade;

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
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	~Bureaucrat();
	// Copy Constructor
	Bureaucrat(Bureaucrat const &src);
	// Copy Assignment Operator
	Bureaucrat &operator=(Bureaucrat const &rhs);
	// Settes and Getters
	std::string getName() const;
	int getGrade() const;
	// Member Functions
	void increment();
	void decrement();
};

// Operator Overloads
std::ostream &operator<<(std::ostream &out, Bureaucrat &bureaucrat);

#endif
