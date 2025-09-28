#include "../includes/Animal.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"

int main()
{
	std::cout << "Correct Animal" << std::endl;
	const Animal *meta = new Animal();
	const Animal *dog = new Dog();
	const Animal *cat = new Cat();
	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;
	dog->makeSound();
	cat->makeSound();
	meta->makeSound();
	delete meta;
	delete dog;
	delete cat;

	//--------------------------------------------------------------

	std::cout << "Wrong Animal" << std::endl;
	const WrongAnimal *wanimal = new WrongAnimal();
	const WrongAnimal *wcat = new WrongCat();

	wanimal->makeSound();
	wcat->makeSound();
	delete wanimal;
	delete wcat;
}
