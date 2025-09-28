#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include "Animal.hpp"

class Dog: public Animal
{
public:
	// Constructor & Destructor
	Dog();
	~Dog();
	// Copy Constructor
	Dog(Dog const &src);
	// Operator Overload
	Dog &operator=(Dog const &rhs); // right hand side
	 // Member Functions
	 void makeSound() const;
};
#endif
