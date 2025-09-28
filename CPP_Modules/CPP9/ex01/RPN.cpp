#include "RPN.hpp"

RPN::RPN() {}
RPN::~RPN() {}
RPN::RPN(RPN const &o) { *this = o; }
RPN &RPN::operator=(RPN const &rhs)
{
	if (this != &rhs)
		this->stack = rhs.stack;
	return *this;
}

RPN::RPN(std::string calc)
{
	// std::cout << "RPN Param constructor called" << std::endl;
	std::istringstream iss(calc);
	std::string token;
	while (iss >> token)
	{
		// std::cout << "THE TOKEN >" << token << std::endl;
		if ((token.size() > 1 && token[0] == '-' && std::isdigit(token[1])) || (token.size() > 1 && token[0] == '+' && std::isdigit(token[1])) || std::isdigit(token[0]))
		{
			int num = std::stoi(token);
			if (num > 9)
				throw std::runtime_error("out-of-range (max 9)");
			stack.push(num);
		}
		else if (token == "+" || token == "-" || token == "/" || token == "*")
		{
			if (stack.size() < 2)
				throw std::runtime_error("not enough operands");
			int b = stack.top();
			stack.pop();
			int a = stack.top();
			stack.pop();
			switch (token[0])
			{
			case '+':
				stack.push(a + b);
				break;
			case '-':
				stack.push(a - b);
				break;
			case '/':
			{
				if (b == 0)
					throw std::runtime_error("division by zero");
				else
					stack.push(a / b);
				break;
			}
			case '*':
				stack.push(a * b);
				break;
			}
			continue;
		}
		else
			throw std::runtime_error("invalid token: " + token);
	}
	// std::cout << "RESULT >" << stack.top() << std::endl;
	if (stack.size() == 1)
		std::cout << stack.top() << std::endl;
	else
		throw std::runtime_error("invalid syntax");
}