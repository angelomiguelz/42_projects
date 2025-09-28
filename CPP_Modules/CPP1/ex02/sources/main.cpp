#include <iostream>

int main(void){

	//String and etc
	std::string string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string &stringREF = string;
	//Prints Addresses
	std::cout << &string << std::endl;
	std::cout << stringPTR << std::endl;
	std::cout << &stringREF << std::endl;
	//Prints Values
	std::cout << string << std::endl;
	std::cout << *stringPTR << std::endl;
	std::cout << stringREF << std::endl;
}
