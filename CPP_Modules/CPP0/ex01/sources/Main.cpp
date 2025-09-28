#include "../includes/PhoneBook.hpp"

int main(int ac, char **av){

	(void)av;
	if (ac > 1)
		return 1;
    std::string key;
    Phonebook book;
	std::cout << "Welcome to the Phonebook" << std::endl;
	std::cout << "Available commands: ADD, SEARCH, EXIT" << std::endl;
    do {
		if (std::cin.eof())
			exit(1);
        std::cout << ("Enter Command: ");
        getline(std::cin, key);
        if (key == "ADD")
            book.ADD();
		if (key == "SEARCH")
			book.SEARCH();
        if (key == "EXIT")
            std::cout << "\nThanks bud\n";
    } while (key != "EXIT");
	return 0;
}
