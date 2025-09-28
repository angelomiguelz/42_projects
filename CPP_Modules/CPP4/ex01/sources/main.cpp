#include "../includes/Animal.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"

int main()
{

	Dog basic;
	{
		Dog tmp = basic;
	}

	/* int animalSize = 1;
	Animal *animals[animalSize * 2];
	for (int i = 0; i < animalSize; i++)
	{
		animals[i] = new Dog();
		animals[i + animalSize] = new Cat();
	}

	for (int i = 0; i < animalSize * 2; i++)
		delete animals[i]; */
}
