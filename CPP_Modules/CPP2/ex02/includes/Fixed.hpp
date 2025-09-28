#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int _fixedNumberValue;
	static const int _fractionalBits = 8;

public:
	// Constructor & Destructor
	Fixed();
	Fixed(const int value);
	Fixed(const float value);
	~Fixed();
	// Copy Constructor
	Fixed(Fixed const &src);
	// Operator Overload
	Fixed &operator=(Fixed const &rhs);
	// Comparison Operators
	bool operator<(Fixed const &rhs);
	bool operator>(Fixed const &rhs);
	bool operator>=(Fixed const &rhs);
	bool operator<=(Fixed const &rhs);
	bool operator==(Fixed const &rhs);
	bool operator!=(Fixed const &rhs);
	// Arithmetic Operators
	Fixed operator+(Fixed const &rhs);
	Fixed operator-(Fixed const &rhs);
	Fixed operator*(Fixed const &rhs);
	Fixed operator/(Fixed const &rhs);
	// Pre Increment & Decrement
	Fixed &operator++();
	Fixed &operator--();
	// Post Increment & Decrement
	Fixed operator++(int);
	Fixed operator--(int);
	// Min & Max
	static Fixed &min(Fixed &a, Fixed &b);
	static Fixed &max(Fixed &a, Fixed &b);
	// Min & Max Const
	static Fixed const &min(Fixed const &a, Fixed const &b);
	static Fixed const &max(Fixed const &a, Fixed const &b);
	// Setters & Getters
	// Member Functions
	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
