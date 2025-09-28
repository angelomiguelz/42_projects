#include "../includes/ScavTrap.hpp"

int	main(void)
{
	ScavTrap a;
	ScavTrap b("Roberto");
	ScavTrap c(b);
	ScavTrap d("Copy");

	a = d;

	std::cout << "Hp: " << a.getHP() << " Ep: " << a.getEP() << " Ad: " << a.getAD() << " Name: " << a.getName() << std::endl;
	std::cout << "Hp: " << b.getHP() << " Ep: " << b.getEP() << " Ad: " << b.getAD() << " Name: " << b.getName() << std::endl;
	std::cout << "Hp: " << c.getHP() << " Ep: " << c.getEP() << " Ad: " << c.getAD() << " Name: " << c.getName() << std::endl;
	std::cout << "Hp: " << d.getHP() << " Ep: " << d.getEP() << " Ad: " << d.getAD() << " Name: " << d.getName() << std::endl;
	return 0;
}
