#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <fstream>

class Harl {
    private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
    public:
		// Constructor & Destructor
		Harl();
		~Harl();

		// Setters & Getters
		// Member Functions
		void complain(std::string level);
};
#endif
