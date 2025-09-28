#include "../includes/Dog.hpp"

// Orthodox Canon Form

Dog::Dog() {
	std::cout << "Default Constructor Called Dog" << std::endl;
	this->type = "Dog";
}

Dog::Dog(Dog const &src) {
	std::cout << "Copy Constructor Called Dog" << std::endl;
	this->type = src.type;
}

Dog &Dog::operator=(Dog const &rhs) {
	std::cout << "Copy Assignment Operator Called Dog" << std::endl;
	if (this != &rhs) {
		this->type = rhs.type;
	}
	return *this;
}

Dog::~Dog() {
	std::cout << "Default Deconstructor Called Dog" << std::endl;
}

// Member Functions

void Dog::makeSound() const {
	std::cout << "Dog Barks" << std::endl;
}
