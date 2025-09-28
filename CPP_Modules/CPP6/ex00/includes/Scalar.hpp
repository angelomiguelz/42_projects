#ifndef SCALAR_HPP
#define SCALAR_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

class Scalar
{
public:
	static void convert(std::string literal);
private:
	Scalar();
	~Scalar();
	// Copy Constructor
	Scalar(Scalar const &src);
	// Operator Overload
	Scalar &operator=(Scalar const &rhs);
};

#endif
