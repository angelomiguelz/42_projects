#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>

class RPN
{
private:
	std::stack<int> stack;

public:
	// OCF
	RPN();
	RPN(std::string calc);
	~RPN();
	RPN(RPN const &o);
	RPN &operator=(RPN const &rhs);
	// member functions
};
#endif