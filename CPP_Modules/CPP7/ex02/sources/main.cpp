#include <iostream>
#include <../includes/Array.hpp>

// -> My main
int main(void)
{
	// Simple Construction
	{
		Array<int> empty;
		try
		{
			std::cout << "Simple Array Construction with Error" << std::endl;
			std::cout << empty[0] << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl
					  << std::endl;
		}
	}
	// Int Param Constructor
	{
		Array<int> numbers(10);
		try
		{
			std::cout << "Param Constructor, Filling with Numbers and Displaying" << std::endl;
			for (int i = 0; i < 10; i++)
				numbers[i] = i;
			for (int i = 0; i < 10; i++)
				std::cout << "[" << std::to_string(numbers[i]) << "]";
			std::cout << std::endl;
			// Errors
			std::cout << "Errors" << std::endl;
			numbers[-2] = 0;
			numbers[10] = 0;
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl
					  << std::endl;
		}
	}
	// Char Param Constructor
	{
		Array<std::string> numbers(10);
		try
		{
			std::cout << "Param Constructor, Filling with Characters and Displaying" << std::endl;
			for (int i = 0; i < 10; i++)
				numbers[i] = i + 42;
			for (int i = 0; i < 10; i++)
				std::cout << "[" << numbers[i] << "]";
			std::cout << std::endl;
			// Errors
			std::cout << "Errors" << std::endl;
			numbers[-2] = "";
			numbers[10] = "";
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl
					  << std::endl;
		}
	}
}

// -> Main Subject
// #define MAX_VAL 750
// int main(int, char **)
// {
// 	Array<int> numbers(MAX_VAL);
// 	int *mirror = new int[MAX_VAL];
// 	srand(time(NULL));
// 	for (int i = 0; i < MAX_VAL; i++)
// 	{
// 		const int value = rand();
// 		numbers[i] = value;
// 		mirror[i] = value;
// 	}
// 	// SCOPE
// 	{
// 		Array<int> tmp = numbers;
// 		Array<int> test(tmp);
// 	}

// 	for (int i = 0; i < MAX_VAL; i++)
// 	{
// 		if (mirror[i] != numbers[i])
// 		{
// 			std::cerr << "didn't save the same value!!" << std::endl;
// 			return 1;
// 		}
// 	}
// 	try
// 	{
// 		numbers[-2] = 0;
// 	}
// 	catch (const std::exception &e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}
// 	try
// 	{
// 		numbers[MAX_VAL] = 0;
// 	}
// 	catch (const std::exception &e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}

// 	for (int i = 0; i < MAX_VAL; i++)
// 	{
// 		numbers[i] = rand();
// 	}
// 	delete[] mirror; //
// 	return 0;
// }
