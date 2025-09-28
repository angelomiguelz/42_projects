#include "../includes/Animal.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"

int main()
{
	int animalSize = 1;
	AAnimal *animals[animalSize * 2];
	for (int i = 0; i < animalSize; i++)
	{
		animals[i] = new Dog();
		animals[i + animalSize] = new Cat();
	}

	for (int i = 0; i < animalSize * 2; i++)
		delete animals[i];
}
