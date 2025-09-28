#include "../includes/Weapon.hpp"


Weapon::Weapon(std::string type) {
	setType(type);
}

Weapon::~Weapon() {
}

void Weapon::setType(std::string type) {
	this->_type = type;
}

const std::string  &Weapon::getType() {
	return this->_type;
}