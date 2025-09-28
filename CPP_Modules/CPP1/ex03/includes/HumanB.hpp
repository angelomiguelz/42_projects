#ifndef HUMAN_B_HPP
#define HUMAN_B_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanB {
    private:
		Weapon *_weapon; //weapon pointer to delay the weapon object creation and allow it to change wahterver for a differente object of weapon
        std::string _name;
    public:
		// Constructor & Destructor
		HumanB(std::string name);
		~HumanB();
		// Setters & Getters
		void setWeapon(Weapon &weapon);
		// Member Functions
		void attack();
};

#endif
