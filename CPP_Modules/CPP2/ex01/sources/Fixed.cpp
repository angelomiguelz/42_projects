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

std::ostream	&operator<<(std::ostream &out, const Fixed &fixed ) {
	out << fixed.toFloat();
	return out;
}

Fixed::Fixed(const int value) {
	std::cout << "Int Constructor Called" << std::endl;
	// shifts the bits in num [_fractional] positions to the left.
	this->_fixedNumberValue = (value << this->_fractionalBits);
}

Fixed::Fixed(const float value) {
	std::cout << "Float Constructor Called" << std::endl;
	// rounds the float to the nearest integer
	this->_fixedNumberValue = roundf(value * (256)); // 2^8 = 256 (8 bits) multypling it by 2^8 is the same as bit shiffting 8 bits.
}

int Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fixedNumberValue;
}

void Fixed::setRawBits( int const raw ) {
	std::cout << "setRawBits member function called" << std::endl;
	this->_fixedNumberValue = raw;
}

float Fixed::toFloat( void ) const {
	return (float)this->_fixedNumberValue / (256); // 2^8 = 256 (8 bits)
}

int Fixed::toInt( void ) const {
	return this->_fixedNumberValue >> this->_fractionalBits;
}

