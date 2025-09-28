#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie {
    private:
        std::string _name;
    public:
		// Constructor & Destructor
		Zombie(std::string name);
		~Zombie();

		// Setters & Getters
		void	setName(std::string name);
		std::string	getName(void);

		// Member Functions
		void	announce(void);
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);


#endif
