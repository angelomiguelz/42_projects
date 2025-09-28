#include "Zombie.hpp"


Zombie::Zombie(std::string name) {
	this->_name = name;
}

Zombie::~Zombie() {
	std::cout << "Zombie " << this->_name << " has been destroyed" << std::endl;
}

void	Zombie::setName(std::string name) {
	this->_name = name;
}

std::string	Zombie::getName(void) {
	return (this->_name);
}

void Zombie::announce() {
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}