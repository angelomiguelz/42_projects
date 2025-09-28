#include "../includes/Fixed.hpp"

// Orthodox Canon Form

Fixed::Fixed() {
	std::cout << "Default Constructor Called" << std::endl;
	this->_fixedNumberValue = 0;
}

Fixed::Fixed(Fixed const &src){
	std::cout << "Copy Constructor Called" << std::endl;
	this->_fixedNumberValue = src._fixedNumberValue;
}

Fixed &Fixed::operator=(Fixed const &rhs) {
	std::cout << "Copy Assignment Operator Called" << std::endl;
	if (this != &rhs) {
		this->_fixedNumberValue = rhs._fixedNumberValue;
	}
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Default Deconstructor Called" << std::endl;
}

// Demanded by the subject

int Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fixedNumberValue;
}

void Fixed::setRawBits( int const raw ) {
	std::cout << "setRawBits member function called" << std::endl;
	this->_fixedNumberValue = raw;
}
