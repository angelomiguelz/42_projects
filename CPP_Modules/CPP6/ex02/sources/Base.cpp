#include "../includes/Base.hpp"

Base *generate(void)
{
	std::srand(time(NULL));
	int n = std::rand() % 3;
	switch (n)
	{
	case 0:
		std::cout << "Randomly hit the jackpot and generated A class" << std::endl;
		return new A;
	case 1:
		std::cout << "Randomly hit the jackpot and generated B class" << std::endl;
		return new B;
	case 2:
		std::cout << "Randomly hit the jackpot and generated C class" << std::endl;
		return new C;
	default:
		break;
	}
	return NULL;
}

void identify(Base *p)
{
	// std::cout << "Base *p" << std::endl;
	if (dynamic_cast<A *>(p) != NULL)
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p) != NULL)
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p) != NULL)
		std::cout << "C" << std::endl;
}

void identify(Base &p)
{
	// std::cout << "Base &p" << std::endl;
	try
	{
		A &aux = dynamic_cast<A &>(p);
		(void)aux;
		std::cout << "A" << std::endl;
		return;
	}
	catch (...)
	{
	}

	try
	{
		B &aux = dynamic_cast<B &>(p);
		(void)aux;
		std::cout << "B" << std::endl;
		return;
	}
	catch (...)
	{
	}

	try
	{
		C &aux = dynamic_cast<C &>(p);
		(void)aux;
		std::cout << "C" << std::endl;
		return;
	}
	catch (...)
	{
	}
}

Base::~Base() {}