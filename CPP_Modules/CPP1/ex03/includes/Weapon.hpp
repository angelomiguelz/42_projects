#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon {
    private:
        std::string _type;
    public:
		// Constructor & Destructor
		Weapon(std::string type);
		~Weapon();

		// Setters & Getters
		void setType(std::string);
		const std::string &getType();
		// Member Functions
};
#endif
