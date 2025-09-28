#include "../includes/Dog.hpp"

// Orthodox Canon Form

Dog::Dog() {
	std::cout << "Default Constructor Called Dog" << std::endl;
	this->brain = new Brain();
	this->type = "Dog";
}

Dog::Dog(Dog const &src) {
	std::cout << "Copy Constructor Called Dog" << std::endl;
	this->type = src.type;
	this->brain = new Brain(*src.brain);
}

Dog &Dog::operator=(Dog const &rhs) {
	std::cout << "Copy Assignment Operator Called Dog" << std::endl;
	if (this != &rhs) {
		this->type = rhs.type;
		this->brain = rhs.brain;
	}
	return *this;
}

Dog::~Dog() {
	std::cout << "Default Deconstructor Called Dog" << std::endl;
	delete this->brain;
}

// Member Functions

void Dog::makeSound() const {
	std::cout << "Dog Barks" << std::endl;
}
