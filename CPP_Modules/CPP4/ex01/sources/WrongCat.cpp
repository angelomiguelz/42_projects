#include "../includes/WrongCat.hpp"

// Orthodox Canon Form

WrongCat::WrongCat() {
	std::cout << "Default Constructor Called WrongCat" << std::endl;
	this->type = "WrongCat";
}

WrongCat::WrongCat(WrongCat const &src) {
	std::cout << "Copy Constructor Called WrongCat" << std::endl;
	this->type = src.type;
}

WrongCat &WrongCat::operator=(WrongCat const &rhs) {
	std::cout << "Copy Assignment Operator Called WrongCat" << std::endl;
	if (this != &rhs) {
		this->type = rhs.type;
	}
	return *this;
}

WrongCat::~WrongCat() {
	std::cout << "Default Deconstructor Called WrongCat" << std::endl;
}