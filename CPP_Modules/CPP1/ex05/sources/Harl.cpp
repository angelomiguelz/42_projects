#include "../includes/Harl.hpp"

Harl::Harl() {
	std::cout << "Default Constructor Called" << std::endl;
}

Harl::~Harl() {
	std::cout << "Default Deconstructor Called" << std::endl;
}

void Harl::debug(void) {
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info(void) {
	std::cout << "I cannot believe adding extra bacon costs more money. You didnt put enough bacon in my burger! If you did, I wouldnt be asking for more!" << std::endl;
}

void Harl::warning(void) {
	std::cout << "I think I deserve to have some extra bacon for free. Ive been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void) {
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level) {
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"}; //array of levels
	void (Harl::*functions[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error}; //array of function pointers
	for (int i = 0; i < 4; i++) {
		if (levels[i] == level) {
			(this->*functions[i])();
			return;
		}
	} 
}