#include "../includes/Bureaucrat.hpp"

int main(void)
{
	Bureaucrat nameless;
	Bureaucrat student("Miguel", 31);
	Bureaucrat newStudent(nameless);
	nameless = student;
	std::cout << "----" << std::endl;
	std::cout << nameless;
	std::cout << student;
	std::cout << newStudent;
	std::cout << "----" << std::endl;

	std::cout << std::endl
			  << "--Grade Too High--" << std::endl;
	try
	{
		Bureaucrat high("High", 0);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl
			  << "--Grade Too Low--" << std::endl;
	try
	{
		Bureaucrat low("Low", 151);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl
			  << "--Good Increase--" << std::endl;
	try
	{
		Bureaucrat normal("Normal", 150);
		std::cout << normal;
		normal.increment();
		std::cout << normal;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl
			  << "--Bad Increase--" << std::endl;
	try
	{
		Bureaucrat bad("Normal", 1);
		bad.increment();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl
			  << "--Good Decrease--" << std::endl;
	try
	{
		Bureaucrat normal("Normal", 1);
		std::cout << normal;
		normal.decrement();
		std::cout << normal;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl
			  << "--Bad Decrease--" << std::endl;
	try
	{
		Bureaucrat bad("Bad", 150);
		bad.decrement();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
}
