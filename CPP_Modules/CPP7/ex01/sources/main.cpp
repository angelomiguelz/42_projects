#include "../includes/iter.hpp"

void makeIt42(int &n)
{
	n = 42;
}

void iLoveMinishell(std::string &s)
{
	s = "ILOVEMINISHELL";
}

int main(void)
{
	std::string sentences[] = {"I", "HATE", "MINISHELL"};
	int numbers[] = {1, 2, -1, 150};

	std::cout << "Printing Sentences" << std::endl;
	::print(sentences, 3);
	std::cout << std::endl;
	std::cout << "Printing Numbers" << std::endl;
	::print(numbers, 4);
	std::cout << std::endl;
	std::cout << "Making Number into 42" << std::endl;
	::iter(numbers, 4, makeIt42);
	std::cout << "Printing Numbers" << std::endl;
	::print(numbers, 4);
	std::cout << std::endl;
	std::cout << "Turning Hate into Love" << std::endl;
	::iter(sentences, 3, iLoveMinishell);
	std::cout << "Printing Sentences" << std::endl;
	::print(sentences, 3);
	std::cout << std::endl;
}
