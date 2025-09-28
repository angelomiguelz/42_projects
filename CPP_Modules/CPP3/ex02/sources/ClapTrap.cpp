#include "../includes/ClapTrap.hpp"

// Orthodox Canon Form

ClapTrap::ClapTrap() {
	std::cout << "Default Constructor Called ClapTrap" << std::endl;
	this->_name = "Default";
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
}

ClapTrap::ClapTrap(ClapTrap const &src): _name(src._name), _hitPoints(src._hitPoints), _energyPoints(src._energyPoints), _attackDamage(src._attackDamage){
	std::cout << "Copy Constructor Called ClapTrap" << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &rhs) {
	std::cout << "Copy Assignment Operator Called ClapTrap" << std::endl;
	if (this != &rhs) {
		this->_name = rhs._name;
		this->_hitPoints = rhs._hitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDamage = rhs._attackDamage;
	}
	return *this;
}


// Demanded by the subject

ClapTrap::ClapTrap(std::string name): _name(name) {
	std::cout << "Name Constructor Called ClapTrap" << std::endl;
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
}

ClapTrap::~ClapTrap() {
	std::cout << "Default Deconstructor Called ClapTrap" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
	if (this->_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " is already dead!" << std::endl;
		return;
	}
	if (this->_energyPoints > 0) {
		std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
		this->_energyPoints -= 1;
	} else
		std::cout << "ClapTrap " << this->_name << " has no energy left to attack!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hitPoints > 0) {
		std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage!" << std::endl;
		this->_hitPoints -= amount;
	} else
		std::cout << "ClapTrap " << this->_name << " is already dead!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->_energyPoints > 0)
	{
		if (this->_hitPoints > 0) {
			std::cout << "ClapTrap " << this->_name << " is repaired for " << amount << " points of health!" << std::endl;
			this->_hitPoints += amount;
			this->_energyPoints -= 1;
		} else
			std::cout << "ClapTrap " << this->_name << " is already dead!" << std::endl;
	} else
		std::cout << "ClapTrap " << this->_name << " has no energy left to be repaired!" << std::endl;
}