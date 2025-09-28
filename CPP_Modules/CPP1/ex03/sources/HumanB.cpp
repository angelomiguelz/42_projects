#include "../includes/HumanB.hpp"

HumanB::HumanB(std::string name): _name(name) {
	this->_weapon = NULL;
	std::cout << "HumanB Name Constructor Called" << std::endl;
}

HumanB::~HumanB() {
	std::cout << "HumanB Destructor Called" << std::endl;
}

void HumanB::setWeapon(Weapon &weapon) {
	this->_weapon = &weapon;
}

void HumanB::attack(void) {
	if (this->_weapon == NULL || this->_weapon->getType().empty())
		std::cout << this->_name << " has no Weapon" << std::endl;
	else
		std::cout << this->_name << " attacks with his " << _weapon->getType() << std::endl;
}