#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cout << "Error > Correct Usage: ./PmergeMe [int sequence]" << std::endl;
		return 1;
	}
	try
	{
		PmergeMe mergeSort;
		mergeSort.init(av, ac);
		mergeSort.check();
	}
	catch (std::exception &e)
	{
		std::cout << "Error > " << e.what() << std::endl;
		return 1;
	}
}