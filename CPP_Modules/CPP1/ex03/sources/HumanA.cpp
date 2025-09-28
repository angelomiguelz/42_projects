#include "../includes/HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _weapon(weapon), _name(name)
{
    std::cout << "HumanA Name Constructor Called" << std::endl;
}

HumanA::~HumanA() {
	std::cout << "HumanA Destructor Called" << std::endl;
}

void HumanA::attack() {
	std::cout << this->_name << " attacks with his " << this->_weapon.getType() << std::endl;
}

