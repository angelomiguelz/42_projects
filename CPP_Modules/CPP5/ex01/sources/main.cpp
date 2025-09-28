#include "../includes/Bureaucrat.hpp"

int main(void)
{
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
	// ex01
	{
		std::cout << "------Form Testing------" << std::endl
				  << std::endl;
		Form nameless;
		Form student("Miguel", 42, 42);
		Form newStudent(nameless);
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
			Form high("High", 0, 0);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl
				  << "--Grade Too Low--" << std::endl;
		try
		{
			Form low("Low", 151, 151);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl
				  << "--Be Signed Success--" << std::endl;
		try
		{
			Bureaucrat b("Miguel", 1);
			Form form("Sign", 150, 150);
			form.beSigned(b);
			std::cout << form;
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl
				  << "--Be Signed Failure--" << std::endl;
		try
		{
			Bureaucrat b("Miguel", 42);
			Form form("Sign", 40, 40);
			form.beSigned(b);
			std::cout << form;
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl
				  << "--Sign Form Success--" << std::endl;
		try
		{
			Bureaucrat b("Miguel", 42);
			Form form("Form", 150, 150);
			b.signForm(form);
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl
				  << "--Sign Form Failure--" << std::endl;
		try
		{
			Bureaucrat b("Miguel", 69);
			Form form("Form", 50, 50);
			b.signForm(form);
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
}
