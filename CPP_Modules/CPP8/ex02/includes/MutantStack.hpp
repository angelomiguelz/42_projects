#ifndef MUTANT_STACK_HPP
#define MUTANT_STACK_HPP

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	typedef typename std::stack<T>::container_type::iterator iterator;
	MutantStack() : std::stack<T>() {};
	~MutantStack() {};
	MutantStack(MutantStack const &other) : std::stack<T>(other) {};
	MutantStack &operator=(MutantStack const &rhs)
	{
		if (this != &rhs)
			std::stack<T>::operator=(rhs);
		return *this;
	};
	iterator begin() { return std::stack<T>::c.begin(); };
	iterator end() { return std::stack<T>::c.end(); };

private:
};

#endif