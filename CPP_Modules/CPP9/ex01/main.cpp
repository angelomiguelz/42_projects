#include "RPN.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Error > Correct Usage: ./RPN [calculation]" << std::endl;
		return 1;
	}
	try
	{
		RPN exchange(av[1]);
	}
	catch (std::exception &e)
	{
		std::cout << "Error > " << e.what() << std::endl;
		return 1;
	}
}