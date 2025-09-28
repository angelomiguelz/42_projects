#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
private:
	std::string ideas[100];

public:
	// Constructor & Destructor
	Brain();
	~Brain();
	// Copy Constructor
	Brain(Brain const &src);
	// Operator Overload
	Brain &operator=(Brain const &rhs); // right hand side
	// Member Functions
	// Settes and Getters
};
#endif
