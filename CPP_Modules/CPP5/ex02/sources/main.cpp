#include "../includes/Bureaucrat.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"

int main(void)
{
	// Bureaucrat god("God", 1);
	// RobotomyRequestForm test("test");
	// god.signForm(test);
	// god.executeForm(test);
	// return 0;
	try
	{
		std::cout << "\n=== Creating Bureaucrats ===\n"
				  << std::endl;

		Bureaucrat intern("Intern", 150);
		Bureaucrat employee("Employee", 70);
		Bureaucrat manager("Manager", 25);
		Bureaucrat ceo("CEO", 1);

		std::cout << intern << employee << manager << ceo << std::endl;

		std::cout << "\n=== Testing Shrubbery Creation Form ===\n"
				  << std::endl;
		{
			ShrubberyCreationForm form("garden");
			std::cout << form << std::endl;

			// Test with intern (should fail to sign)
			intern.signForm(form);
			intern.executeForm(form);

			// Test with employee (should work)
			employee.signForm(form);
			employee.executeForm(form);
		}

		std::cout << "\n=== Testing Robotomy Request Form ===\n"
				  << std::endl;
		{
			RobotomyRequestForm form("Bender");
			std::cout << form << std::endl;

			// Test with employee (should fail to execute)
			employee.signForm(form);
			employee.executeForm(form);

			// Test with manager (should work)
			RobotomyRequestForm form2("R2D2");
			manager.signForm(form2);
			manager.executeForm(form2);
		}

		std::cout << "\n=== Testing Presidential Pardon Form ===\n"
				  << std::endl;
		{
			PresidentialPardonForm form("Criminal");
			std::cout << form << std::endl;

			// Test with manager (should fail to execute)
			manager.signForm(form);
			manager.executeForm(form);

			// Test with CEO (should work)
			PresidentialPardonForm form2("Justin");
			ceo.signForm(form2);
			ceo.executeForm(form2);
		}

		std::cout << "\n=== Testing Invalid Cases ===\n"
				  << std::endl;

		// Test invalid bureaucrat grades
		try
		{
			Bureaucrat invalid1("Invalid1", 151);
		}
		catch (std::exception &e)
		{
			std::cout << "Grade 151 test: " << e.what() << std::endl;
		}

		try
		{
			Bureaucrat invalid2("Invalid2", 0);
		}
		catch (std::exception &e)
		{
			std::cout << "Grade 0 test: " << e.what() << std::endl;
		}

		// Test executing before signing
		std::cout << "\n=== Testing Execution Without Signature ===\n"
				  << std::endl;
		{
			ShrubberyCreationForm form("test");
			ceo.executeForm(form); // Should fail because not signed
		}
	}
	catch (std::exception &e)
	{
		std::cerr << "Unexpected error: " << e.what() << std::endl;
		return 1;
	}

	return 0;
}