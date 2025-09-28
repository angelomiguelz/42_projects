#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
    private:
		int _fixedNumberValue;
		static const int _fractionalBits = 8;
    public:
		// Constructor & Destructor
		Fixed();
		~Fixed();
		// Copy Constructor
		Fixed(Fixed const &src);
		// Operator Overload
		Fixed &operator=(Fixed const &rhs); //right hand side
		// Setters & Getters
		// Member Functions
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};
#endif
