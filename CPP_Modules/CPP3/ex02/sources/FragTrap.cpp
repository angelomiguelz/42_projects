#include "../includes/FragTrap.hpp"

// Orthodox Canon Form

FragTrap::FragTrap() {
	std::cout << "Default Constructor Called FragTrap" << std::endl;
	this->_name = "Default";
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(FragTrap const &src) {
	std::cout << "Copy Constructor Called FragTrap" << std::endl;
	this->_name = src._name;
	this->_hitPoints = src._hitPoints;
	this->_energyPoints = src._energyPoints;
	this->_attackDamage = src._attackDamage;
}

FragTrap &FragTrap::operator=(FragTrap const &rhs) {
	std::cout << "Copy Assignment Operator Called FragTrap" << std::endl;
	if (this != &rhs) {
		this->_name = rhs._name;
		this->_hitPoints = rhs._hitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDamage = rhs._attackDamage;
	}
	return *this;
}


// Demanded by the subject

FragTrap::FragTrap(std::string name)
{
	std::cout << "Name Constructor Called FragTrap" << std::endl;
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::~FragTrap() {
	std::cout << "Default Deconstructor Called FragTrap" << std::endl;
}

void FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << this->_name << " says: Gimme a high five!" << std::endl;
}

// Setters & Getters

std::string FragTrap::getName() {
	return this->_name;
}

int FragTrap::getHP() {
	return this->_hitPoints;
}

int FragTrap::getEP() {
	return this->_energyPoints;
}

int FragTrap::getAD() {
	return this->_attackDamage;
}