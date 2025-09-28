#ifndef WRONG_ANIMAL_HPP
#define WRONG_ANIMAL_HPP

#include <iostream>

class WrongAnimal
{
protected:
	std::string type;
public:
	// Constructor & Destructor
	WrongAnimal();
	~WrongAnimal();
	// Copy Constructor
	WrongAnimal(WrongAnimal const &src);
	// Operator Overload
	WrongAnimal &operator=(WrongAnimal const &rhs); // right hand side
	// Member Functions
	void makeSound() const;
	// Settes and Getters
	std::string getType() const;
};
#endif
