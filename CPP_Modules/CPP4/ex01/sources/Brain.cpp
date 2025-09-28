#include "../includes/Brain.hpp"

// Orthodox Canon Form

Brain::Brain()
{
	std::cout << "Default Constructor Called Brain" << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = "Random Garbage";
}

Brain::Brain(Brain const &src)
{
	std::cout << "Copy Constructor Called Brain" << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = src.ideas[i];
}

Brain &Brain::operator=(Brain const &rhs)
{
	std::cout << "Copy Assignment Operator Called Brain" << std::endl;
	if (this != &rhs)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = rhs.ideas[i];
	}
	return *this;
}

Brain::~Brain()
{
	std::cout << "Default Deconstructor Called Brain" << std::endl;
}

// Member Functions
