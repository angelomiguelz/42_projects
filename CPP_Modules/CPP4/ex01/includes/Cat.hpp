#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
	Brain *brain;
public:
	// Constructor & Destructor
	Cat();
	~Cat();
	// Copy Constructor
	Cat(Cat const &src);
	// Operator Overload
	Cat &operator=(Cat const &rhs); // right hand side
	// Member Functions
	void makeSound() const;
};
#endif
