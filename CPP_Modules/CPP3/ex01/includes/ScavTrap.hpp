#ifndef SCAV_TRAP_HPP
#define SCAV_TRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    private:
    public:
		// Constructor & Destructor
		ScavTrap();
		ScavTrap(std::string name);
		~ScavTrap();
		// Copy Constructor
		ScavTrap(ScavTrap const &src);
		// Operator Overload
		ScavTrap &operator=(ScavTrap const &rhs); //right hand side
		// Setters & Getters
		std::string getName();
		int getHP();
		int getEP();
		int getAD();
		// Member Functions
		void guardGate();
};
#endif
