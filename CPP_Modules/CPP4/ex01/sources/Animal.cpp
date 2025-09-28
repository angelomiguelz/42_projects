#include "../includes/Animal.hpp"

// Orthodox Canon Form

Animal::Animal() {
	std::cout << "Default Constructor Called Animal" << std::endl;
	this->type = "Default";
}

Animal::Animal(Animal const &src) {
	std::cout << "Copy Constructor Called Animal" << std::endl;
	this->type = src.type;
}

Animal &Animal::operator=(Animal const &rhs) {
	std::cout << "Copy Assignment Operator Called Animal" << std::endl;
	if (this != &rhs) {
		this->type = rhs.type;
	}
	return *this;
}

Animal::~Animal() {
	std::cout << "Default Deconstructor Called Animal" << std::endl;
}


// Demanded by the subject

void Animal::makeSound() const {
	std::cout << "Animal Sound" << std::endl;
}

std::string Animal::getType() const {
	return this->type;
}