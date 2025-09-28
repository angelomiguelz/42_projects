#include "../includes/Base.hpp"

int main(void)
{
	std::cout << "-->Manual Test<--" << std::endl;
	{
		std::cout << "Creating <A>" << std::endl;
		Base *ptr = new A;
		identify(ptr);
		identify(*ptr);
		delete ptr;
	}
	{
		std::cout << "Creating <B>" << std::endl;
		Base *ptr = new B;
		identify(ptr);
		identify(*ptr);
		delete ptr;
	}
	{
		std::cout << "Creating <C>" << std::endl;
		Base *ptr = new C;
		identify(ptr);
		identify(*ptr);
		delete ptr;
	}
	{
		std::cout << "-->Random Test 1<--" << std::endl;

		Base *ptr = generate();
		std::cout << "Function: identify(Base *p):" << std::endl;
		identify(ptr);
		std::cout << "Fucntion: identify(Base &p):" << std::endl;
		identify(*ptr);
		delete ptr;
	}
}
