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
	// Setters & Getters
	// Member Functions
	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
