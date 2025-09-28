#include "../includes/Cat.hpp"

// Orthodox Canon Form

Cat::Cat() {
	std::cout << "Default Constructor Called Cat" << std::endl;
	new Brain();
	this->type = "Cat";
}

Cat::Cat(Cat const &src) {
	std::cout << "Copy Constructor Called Cat" << std::endl;
	this->type = src.type;
	this->brain = new Brain(*src.brain);
}

Cat &Cat::operator=(Cat const &rhs) {
	std::cout << "Copy Assignment Operator Called Cat" << std::endl;
	if (this != &rhs) {
		this->type = rhs.type;
		this->brain = rhs.brain;
	}
	return *this;
}

Cat::~Cat() {
	std::cout << "Default Deconstructor Called Cat" << std::endl;
	delete this->brain;
}

// Member Functions

void Cat::makeSound() const {
	std::cout << "Cat Meows" << std::endl;
}
