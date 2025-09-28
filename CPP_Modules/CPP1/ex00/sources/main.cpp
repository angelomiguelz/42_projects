#include "Zombie.hpp"

int main(void){

	Zombie *heap1 = new Zombie("Heap1 Zombie");
	Zombie *heap2 = newZombie("Heap2 Zombie");
	Zombie stack1("Stack1 Zombie");

	heap1->announce();
	heap2->announce();
	stack1.announce();

	randomChump("Stack2 Zombie");

	delete heap1;
	delete heap2;

	return 0;
}
