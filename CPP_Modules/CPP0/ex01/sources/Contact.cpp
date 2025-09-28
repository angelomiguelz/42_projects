#include "../includes/Contact.hpp"

Contact::Contact(){
}

Contact::~Contact(){
}

void Contact::showInfoBase(std::string keyword) {
	if (keyword == "FIRST NAME") {
		if (first_name.size() > 10)
			std::cout << std::string(first_name.begin(), first_name.begin() + 9) << ".";
		else
			std::cout << std::setw(10) << first_name;
	}
	if (keyword == "LAST NAME") {
		if (last_name.size() > 10)
			std::cout << std::string(last_name.begin(), last_name.begin() + 9) << ".";
		else
			std::cout << std::setw(10) << last_name;
	}
	if (keyword == "NICKNAME") {
		if (nickname.size() > 10)
			std::cout << std::string(nickname.begin(), nickname.begin() + 9) << ".";
		else
			std::cout << std::setw(10) << nickname;
	}
	if (keyword == "PHONE NUMBER") {
		if (phone.size() > 10)
			std::cout << std::string(phone.begin(), phone.begin() + 9) << ".";
		else
			std::cout << std::setw(10) << phone;
	}
	if (keyword == "DARKEST SECRET") {
		if (secret.size() > 10)
			std::cout << std::string(secret.begin(), secret.begin() + 9) << ".";
		else
			std::cout << std::setw(10) << secret;
	}
}

void Contact::showInfoAll() {
	std::cout << "FIRST NAME: " << first_name << std::endl;
	std::cout << "LAST NAME: " << last_name << std::endl;
	std::cout << "NICKNAME: " << nickname << std::endl;
	std::cout << "PHONE NUMBER: " << phone << std::endl;
	std::cout << "DARKEST SECRET: " << secret << std::endl;
}


