#include "../includes/WrongAnimal.hpp"

// Orthodox Canon Form

WrongAnimal::WrongAnimal() {
	std::cout << "Default Constructor Called WrongAnimal" << std::endl;
	this->type = "Default";
}

WrongAnimal::WrongAnimal(WrongAnimal const &src) {
	std::cout << "Copy Constructor Called WrongAnimal" << std::endl;
	this->type = src.type;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &rhs) {
	std::cout << "Copy Assignment Operator Called WrongAnimal" << std::endl;
	if (this != &rhs) {
		this->type = rhs.type;
	}
	return *this;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "Default Deconstructor Called WrongAnimal" << std::endl;
}


// Demanded by the subject

void WrongAnimal::makeSound() const {
	std::cout << "WrongAnimal Sound" << std::endl;
}

std::string WrongAnimal::getType() const {
	return this->type;
}