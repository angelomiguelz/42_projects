#include "../includes/Scalar.hpp"

int main(int ac, char **av)
{
	if (ac != 2) {
		std::cout << "invalid input" << std::endl;
		return 1;
	}
	Scalar::convert(av[1]);
}
