#ifndef FRAG_TRAP_HPP
#define FRAG_TRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap 
{
    public:
		// Constructor & Destructor
		FragTrap();
		FragTrap(std::string name);
		~FragTrap();
		// Copy Constructor
		FragTrap(FragTrap const &src);
		// Operator Overload
		FragTrap &operator=(FragTrap const &rhs); //right hand side
		// Setters & Getters
		std::string getName();
		int getHP();
		int getEP();
		int getAD();
		// Member Functions
		void highFivesGuys(void);
};
#endif
