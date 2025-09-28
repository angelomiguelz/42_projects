#ifndef WRONG_CAT_HPP
#define WRONG_CAT_HPP

#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
public:
	// Constructor & Destructor
	WrongCat();
	~WrongCat();
	// Copy Constructor
	WrongCat(WrongCat const &src);
	// Operator Overload
	WrongCat &operator=(WrongCat const &rhs); // right hand side
	// Member Functions
	void makeSound() const;
};
#endif
