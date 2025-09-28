#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>

struct Data
{
	std::string preciousInformation;
};

class Serializer
{
public:
	static uintptr_t serialize(Data *ptr);
	static Data *deserialize(uintptr_t raw);

private:
	Serializer();
	~Serializer();
	// Copy Constructor
	Serializer(Serializer const &src);
	// Operator Overload
	Serializer &operator=(Serializer const &rhs);
};

#endif
