#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
protected:
	std::string type;

public:
	// Constructor & Destructor
	Animal();
	virtual ~Animal();
	// Copy Constructor
	Animal(Animal const &src);
	// Operator Overload
	Animal &operator=(Animal const &rhs); // right hand side
	// Member Functions
	virtual void makeSound() const;
	// Settes and Getters
	std::string getType() const;
};
#endif
