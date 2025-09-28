#include "../includes/ScavTrap.hpp"

// Orthodox Canon Form

ScavTrap::ScavTrap() {
	std::cout << "Default Constructor Called ScavTrap" << std::endl;
	this->_name = "Default";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap(ScavTrap const &src) {
	std::cout << "Copy Constructor Called ScavTrap" << std::endl;
	this->_name = src._name;
	this->_hitPoints = src._hitPoints;
	this->_energyPoints = src._energyPoints;
	this->_attackDamage = src._attackDamage;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &rhs) {
	std::cout << "Copy Assignment Operator Called ScavTrap" << std::endl;
	if (this != &rhs) {
		this->_name = rhs._name;
		this->_hitPoints = rhs._hitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDamage = rhs._attackDamage;
	}
	return *this;
}


// Demanded by the subject

ScavTrap::ScavTrap(std::string name) {
	std::cout << "Name Constructor Called ScavTrap" << std::endl;
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::~ScavTrap() {
	std::cout << "Default Deconstructor Called ScavTrap" << std::endl;
}

// Member Functions
void ScavTrap::guardGate() {
	std::cout << this->_name << " ScavTrap is now in Gate keeper mode" << std::endl;
}

// Setters & Getters

std::string ScavTrap::getName() {
	return this->_name;
}

int ScavTrap::getHP() {
	return this->_hitPoints;
}

int ScavTrap::getEP() {
	return this->_energyPoints;
}

int ScavTrap::getAD() {
	return this->_attackDamage;
}