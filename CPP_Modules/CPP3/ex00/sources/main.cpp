#include "../includes/ClapTrap.hpp"

int	main(void)
{
	ClapTrap Minishell("Minishell");
	ClapTrap Students("Students");
	ClapTrap assignment;
	assignment = Minishell;

	Minishell.attack("Students");
	Students.takeDamage(0);
	Students.takeDamage(132);
	Students.beRepaired(10);
	Minishell.attack("Me");
	Minishell.beRepaired(2);
	Minishell.takeDamage(10);
	assignment.attack("Students");
	return 0;
}
