# include "../includes/PhoneBook.hpp"

Phonebook::Phonebook(){
	index = 0;
}

void	Phonebook::ADD(){
	contacts[this->index % 8].getInfoBase("FIRST NAME");
	contacts[this->index % 8].getInfoBase("LAST NAME");
	contacts[this->index % 8].getInfoBase("NICKNAME");
	if (contacts[this->index % 8].getInfoBase("PHONE NUMBER") == -1)
	{
		system("clear");
		std::cout << "Invalid phone number" << std::endl;
		return ;
	}
	contacts[this->index % 8].getInfoBase("DARKEST SECRET");
	system("clear");
	std::cout << "Contact Added" << std::endl;
	index++;
}

bool	is_num_limits(std::string s, int lim) {
	if (s.size() != 1)
		return (false);
	if (s[0] >= '0' && s[0] <= '0' + lim)
		return (true);
	return (false);
}

void Phonebook::SEARCH() {
	std::string buff;
	int i = index;
	int max = index - 1;

	if (index == 0) {
		system("clear");
		std::cout << "No contacts to show" << std::endl;
		return ;
	}
	std::cout << "|     INDEX|FIRST NAME| LAST NAME|  NICKNAME|" << std::endl;
	for (int i = 0; i < index; i++) {
		if (i >= 8)
			break;
		std::cout << "|         " << i << "|";
		contacts[i].showInfoBase("FIRST NAME");
		std::cout << "|";
		contacts[i].showInfoBase("LAST NAME");
		std::cout << "|";
		contacts[i].showInfoBase("NICKNAME");
		std::cout << "|";
		std::cout << std::endl;
	}
	while (1) {
		std::cout << "Select the index: ";
		getline(std::cin, buff);
		if (std::cin.eof())
			exit(1);
		if (buff.empty())
			continue;
		if (is_num_limits(buff, max))
			i = atoi(buff.c_str());
		else
        {
            std::cout << "Enter a valid index." << std::endl;
            continue;
        }
		contacts[i].showInfoAll();
		break;
	}
}

int isNumberChar(const char *s)
{
	int i = -1;
	while (s[++i])
		if (s[i] < '0' || s[i] > '9')
			return 1;
	return 0;
}

std::string removeWhiteSpace(const std::string& s)
{
	std::string result;
	size_t i = 0;
	size_t j = s.length();
	while (s[i] && std::isspace(s[i]))
		i++;
	while (s[--j] && std::isspace(s[j]))
		;
	j++;
	if (i == j)
		result += s[i];
	while (i != j)
		result += s[i++];
	i = -1;
	while (result[++i])
		if (result[i] == '\t')
		{
			std::cout << "String doesn't accept tabs inside sentences" << std::endl;
			result = "";
			break;
		}
	return result;
}

int	Contact::getInfoBase(std::string keyword) {
	std::string buff;
	do {
		if (std::cin.eof())
			exit(1);
		std::cout << ("ENTER ") << keyword << (": ");
		getline(std::cin, buff);
		buff = removeWhiteSpace(buff);
	} while(buff.empty());
	if (keyword == "FIRST NAME") {
		first_name = buff;
	}
	if (keyword == "LAST NAME") {
		last_name = buff;
	}
	if (keyword == "NICKNAME") {
		nickname = buff;
	}
	if (keyword == "PHONE NUMBER") {
		if (isNumberChar(buff.c_str()) == 0)
			phone = buff;
		else
			return -1;
	}
	if (keyword == "DARKEST SECRET") {
		secret = buff;
	}	
	return 0;
}


