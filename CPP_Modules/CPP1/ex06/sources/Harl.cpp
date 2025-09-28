#include "../includes/Harl.hpp"

Harl::Harl() {
	std::cout << "Default Constructor Called" << std::endl;
}

Harl::~Harl() {
	std::cout << "Default Deconstructor Called" << std::endl;
}

void Harl::debug(void) {
	std::cout << " [DEBUG] " << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info(void) {
	std::cout << " [INFO] " << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didnt put enough bacon in my burger! If you did, I wouldnt be asking for more!" << std::endl;
}

void Harl::warning(void) {
	std::cout << " [WARNING] " << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. Ive been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void) {
	std::cout << " [ERROR] " << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level) {
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*function_p[4])(void) = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error}; //array of member funtion pointer in the harl class
	int lvl = -1;
	for (int i = 0; i < 4; i++) {
		if (levels[i] == level)
		{
			lvl = i;
			break;
		}
	}
	switch (lvl) {
		case 0:
			(this->*(function_p[0]))();
		case 1:
			(this->*(function_p[1]))();
		case 2:
			(this->*(function_p[2]))();
		case 3:
			(this->*(function_p[3]))();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}

}