#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie {
    private:
        std::string _name;
    public:
		// Constructor & Destructor
		Zombie();
		~Zombie();

		// Setters & Getters
		void	setName(std::string name);
		std::string	getName(void);

		// Member Functions
		void	announce(void);
};

Zombie* zombieHorde(int N, std::string name);

#endif
