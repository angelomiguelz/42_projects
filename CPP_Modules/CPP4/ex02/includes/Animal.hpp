#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class AAnimal
{
protected:
	std::string type;

public:
	// Constructor & Destructor
	AAnimal();
	virtual ~AAnimal();
	// Copy Constructor
	AAnimal(AAnimal const &src);
	// Operator Overload
	AAnimal &operator=(AAnimal const &rhs); // right hand side
	// Member Functions
	virtual void makeSound() const = 0;
	// Settes and Getters
	std::string getType() const;
};
#endif
