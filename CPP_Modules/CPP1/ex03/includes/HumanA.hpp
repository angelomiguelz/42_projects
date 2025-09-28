#ifndef HUMAN_A_HPP
#define HUMAN_A_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanA {
    private:
		Weapon &_weapon; //reference puts immutability on the object since humanA needs always to have a weapon
        std::string _name;
    public:
		// Constructor & Destructor
		HumanA(std::string name, Weapon &weapon);
		~HumanA();
		// Setters & Getters
		// Member Functions
		void attack();
};

#endif
