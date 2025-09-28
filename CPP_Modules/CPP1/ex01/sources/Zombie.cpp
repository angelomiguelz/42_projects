#include "../includes/Zombie.hpp"

Zombie::Zombie(void) {
	setName("default");
}

Zombie::~Zombie() {
	std::cout << "Zombie " << getName() << " has been destroyed" << std::endl;
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