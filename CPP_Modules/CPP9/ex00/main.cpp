#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	(void)av;
	if (ac != 2)
	{
		std::cout << "Error > Correct Usage: ./btc [filename]" << std::endl;
		return 1;
	}
	try
	{
		BitcoinExchange exchange;
		exchange.exchange(av[1]);
	}
	catch (std::exception &e)
	{
		std::cout << "Error > " << e.what() << std::endl;
		return 1;
	}
}