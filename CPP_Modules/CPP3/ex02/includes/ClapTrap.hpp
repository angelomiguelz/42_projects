#ifndef CLAP_TRAP_HPP
#define CLAP_TRAP_HPP

#include <iostream>
#include <fstream>

class ClapTrap {
    protected:
		std::string _name;
		int			_hitPoints;
		int			_energyPoints;
		int			_attackDamage;
    public:
		// Constructor & Destructor
		ClapTrap();
		ClapTrap(std::string name);
		~ClapTrap();
		// Copy Constructor
		ClapTrap(ClapTrap const &src);
		// Operator Overload
		ClapTrap &operator=(ClapTrap const &rhs); //right hand side
		// Setters & Getters
		// Member Functions
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};
#endif
