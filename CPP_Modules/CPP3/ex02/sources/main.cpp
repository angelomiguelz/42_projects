#include "../includes/FragTrap.hpp"

int	main()
{
	FragTrap a;
	FragTrap b("Alfonso");
	FragTrap c(b);
	FragTrap d("Yo");

	a = d;

	b.highFivesGuys();
	
	std::cout << "Hp: " << a.getHP() << " Ep: " << a.getEP() << " Ad: " << a.getAD() << " Name: " << a.getName() << std::endl;
	std::cout << "Hp: " << b.getHP() << " Ep: " << b.getEP() << " Ad: " << b.getAD() << " Name: " << b.getName() << std::endl;
	std::cout << "Hp: " << c.getHP() << " Ep: " << c.getEP() << " Ad: " << c.getAD() << " Name: " << c.getName() << std::endl;
	std::cout << "Hp: " << d.getHP() << " Ep: " << d.getEP() << " Ad: " << d.getAD() << " Name: " << d.getName() << std::endl;
	return 0;
}
