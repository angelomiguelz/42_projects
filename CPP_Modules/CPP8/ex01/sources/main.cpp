#include "../includes/Span.hpp"
#include <cstdlib>

int main()
{
	try
	{
		// Basic test with manual numbers
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;

		// Test with iterator range
		Span sp2 = Span(10);
		int numbers[] = {2, 4, 6, 8, 10};
		std::vector<int> v;
		for (int i = 0; i < 5; ++i)
			v.push_back(numbers[i]);
		sp2.addNumbers(v.begin(), v.end());
		std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp2.longestSpan() << std::endl;

		// Test exceptions
		try
		{
			Span sp3 = Span(1);
			sp3.addNumber(5);
			sp3.addNumber(10); // Should throw exception
		}
		catch (const std::exception &e)
		{
			std::cout << "Exception: " << e.what() << std::endl;
		}

		// Test with min/max values
		Span sp4 = Span(3);
		sp4.addNumber(INT_MIN);
		sp4.addNumber(INT_MAX);
		std::cout << "Max span possible: " << sp4.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}