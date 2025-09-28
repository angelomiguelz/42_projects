#include "../includes/Fixed.hpp"

// Orthodox Canon Form

Fixed::Fixed()
{
	std::cout << "Default Constructor Called" << std::endl;
	this->_fixedNumberValue = 0;
}

Fixed::Fixed(Fixed const &src)
{
	std::cout << "Copy Constructor Called" << std::endl;
	this->_fixedNumberValue = src._fixedNumberValue;
}

Fixed &Fixed::operator=(Fixed const &rhs)
{
	std::cout << "Copy Assignment Operator Called" << std::endl;
	if (this != &rhs)
	{
		this->_fixedNumberValue = rhs._fixedNumberValue;
	}
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Default Deconstructor Called" << std::endl;
}

// Demanded by the subject

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}

// Comparison Operators

bool Fixed::operator<(Fixed const &rhs)
{
	return this->_fixedNumberValue < rhs._fixedNumberValue;
}

bool Fixed::operator>(Fixed const &rhs)
{
	return this->_fixedNumberValue > rhs._fixedNumberValue;
}

bool Fixed::operator>=(Fixed const &rhs)
{
	return this->_fixedNumberValue >= rhs._fixedNumberValue;
}

bool Fixed::operator<=(Fixed const &rhs)
{
	return this->_fixedNumberValue <= rhs._fixedNumberValue;
}

bool Fixed::operator==(Fixed const &rhs)
{
	return this->_fixedNumberValue == rhs._fixedNumberValue;
}

bool Fixed::operator!=(Fixed const &rhs)
{
	return this->_fixedNumberValue != rhs._fixedNumberValue;
}

// Arithmetic Operators

Fixed Fixed::operator+(Fixed const &rhs)
{
	return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed Fixed::operator-(Fixed const &rhs)
{
	return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed Fixed::operator*(Fixed const &rhs)
{
	return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(Fixed const &rhs)
{
	return Fixed(this->toFloat() / rhs.toFloat());
}

// Pre Increment & Decrement

Fixed &Fixed::operator++()
{
	this->_fixedNumberValue++;
	return *this;
}

Fixed &Fixed::operator--()
{
	this->_fixedNumberValue--;
	return *this;
}

// Post Increment & Decrement

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	operator++();
	return tmp;
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	operator--();
	return tmp;
}

// Min & Max

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a._fixedNumberValue < b._fixedNumberValue)
		return a;
	return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a._fixedNumberValue > b._fixedNumberValue)
		return a;
	return b;
}

// Min & Max Const

Fixed const &Fixed::min(Fixed const &a, Fixed const &b)
{
	if (a._fixedNumberValue < b._fixedNumberValue)
		return a;
	return b;
}

Fixed const &Fixed::max(Fixed const &a, Fixed const &b)
{
	if (a._fixedNumberValue > b._fixedNumberValue)
		return a;
	return b;
}

// Methods

Fixed::Fixed(const int value)
{
	std::cout << "Int Constructor Called" << std::endl;
	// shifts the bits in num [_fractional] positions to the left.
	this->_fixedNumberValue = (value << this->_fractionalBits);
}

Fixed::Fixed(const float value)
{
	std::cout << "Float Constructor Called" << std::endl;
	// rounds the float to the nearest integer
	this->_fixedNumberValue = roundf(value * (256)); // 2^8 = 256 (8 bits) multypling it by 2^8 is the same as bit shiffting 8 bits.
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fixedNumberValue;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_fixedNumberValue = raw;
}

float Fixed::toFloat(void) const
{
	return (float)this->_fixedNumberValue / (256); // 2^8 = 256 (8 bits)
}

int Fixed::toInt(void) const
{
	return this->_fixedNumberValue >> this->_fractionalBits;
}
