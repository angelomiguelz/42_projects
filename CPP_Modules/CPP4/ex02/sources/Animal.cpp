#include "../includes/Animal.hpp"

// Orthodox Canon Form

AAnimal::AAnimal() {
	std::cout << "Default Constructor Called AAnimal" << std::endl;
	this->type = "Default";
}

AAnimal::AAnimal(AAnimal const &src) {
	std::cout << "Copy Constructor Called AAnimal" << std::endl;
	this->type = src.type;
}

AAnimal &AAnimal::operator=(AAnimal const &rhs) {
	std::cout << "Copy Assignment Operator Called AAnimal" << std::endl;
	if (this != &rhs) {
		this->type = rhs.type;
	}
	return *this;
}

AAnimal::~AAnimal() {
	std::cout << "Default Deconstructor Called AAnimal" << std::endl;
}


// Demanded by the subject

std::string AAnimal::getType() const {
	return this->type;
}