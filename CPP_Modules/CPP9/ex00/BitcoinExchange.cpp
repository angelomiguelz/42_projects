#include "BitcoinExchange.hpp"

BitcoinExchange::~BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(BitcoinExchange const &o) { *this = o; }
BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &rhs)
{
	if (this != &rhs)
		this->rates = rhs.rates;
	return *this;
}

std::string trim(std::string const &str)
{
	size_t first = str.find_first_not_of(" \t\n\r");
	if (first == std::string::npos)
		return str;
	size_t last = str.find_last_not_of(" \t\n\r");
	return str.substr(first, (last - first + 1));
}

bool BitcoinExchange::validDate(std::string date)
{
	// Check for correct format (YYYY-MM-DD)
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return false;

	// Check if all other characters are digits
	for (size_t i = 0; i < date.length(); i++)
	{
		if (i != 4 && i != 7 && !isdigit(date[i]))
			return false;
	}

	int year, month, day;
	char sep1, sep2;
	std::istringstream stream(date);
	if (!(stream >> year >> sep1 >> month >> sep2 >> day) || sep1 != '-' || sep2 != '-')
		return false;

	// Rest of your existing date validation
	if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
		return false;
	if (day > 30 && (month == 4 || month == 6 || month == 9 || month == 11))
		return false;
	if (month == 2)
	{
		bool isLeap = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
		if ((isLeap && day > 29) || (!isLeap && day > 28))
			return false;
	}
	return true;
}

bool BitcoinExchange::validValue(std::string valueStr)
{
	float value;
	std::istringstream stream(valueStr);
	if (!(stream >> value))
	{
		std::cout << "bad input <" << valueStr << ">" << std::endl;
		return false;
	}
	if (value < 0 || value > 1000)
	{
		std::cout << "value out of range (0-1000): <" << valueStr << ">" << std::endl;
		return false;
	}
	return true;
}

BitcoinExchange::BitcoinExchange()
{
	std::ifstream file("data.csv");
	if (!file.is_open())
		throw std::runtime_error("data.csv: File not found");
	std::string line;
	if (!std::getline(file, line) || line != "date,exchange_rate")
		throw std::runtime_error("data.csv: Invalid header format");
	std::string nextLine;
	if (std::getline(file, nextLine) && nextLine == "date,exchange_rate")
		throw std::runtime_error("data.csv: Duplicate header");

	// Process the second line if it exists and isn't empty
	if (!nextLine.empty())
		processDataLine(nextLine);
	while (std::getline(file, line))
		processDataLine(line);
	file.close();
}

void BitcoinExchange::processDataLine(const std::string &line)
{
	size_t commaPos = line.find(',');
	if (commaPos == std::string::npos)
	{
		std::cout << "bad input <" << line << ">" << std::endl;
		return;
	}
	std::string date = line.substr(0, commaPos);
	std::string value = line.substr(commaPos + 1, line.length());
	double rate;
	std::istringstream valueStream(value);
	if (!(valueStream >> rate))
	{
		std::cout << "bad input <" << value << ">" << std::endl;
		return;
	}
	this->rates[date] = rate;
}

void BitcoinExchange::exchange(std::string fileName)
{
	std::ifstream file(fileName.c_str());
	if (!file.is_open())
		throw std::runtime_error(fileName + ": File not found");
	std::string line;
	if (!std::getline(file, line) || line != "date | value")
		throw std::runtime_error(fileName + ": Invalid header format");
	std::string nextLine;
	if (std::getline(file, nextLine) && nextLine == "date | value")
		throw std::runtime_error(fileName + ": Duplicate header");

	// Process the second line if it exists and isn't empty
	if (!nextLine.empty())
		processInputLine(nextLine);

	while (std::getline(file, line))
		processInputLine(line);
}

void BitcoinExchange::processInputLine(const std::string &line)
{
	if (line.empty())
	{
		std::cout << "bad input <empty line>" << std::endl;
		return;
	}

	size_t pipe = line.find("|");
	if ((pipe = line.find("|")) && pipe == std::string::npos)
	{
		std::cout << "bad input <" << line << ">" << std::endl;
		return;
	}

	std::string date = trim(line.substr(0, pipe));
	std::string value = trim(line.substr(pipe + 1, line.length()));

	if (!validDate(date))
	{
		std::cout << "bad date <" << date << ">" << std::endl;
		return;
	}
	if (!validValue(value))
		return;

	std::map<std::string, double>::iterator it = rates.lower_bound(date);
	if (rates.empty())
	{
		std::cout << "cant find date <" << date << ">" << std::endl;
		return;
	}

	// If we're at the beginning and the date is earlier than our first entry
	if (it == rates.begin() && date < it->first)
	{
		std::cout << "cant find date <" << date << ">" << std::endl;
		return;
	}
	// If we're at the end, use the last entry
	if (it == rates.end())
		--it;
	// If the date is greater than our found date, use the previous entry
	else if (it->first > date)
		--it;

	double exchangeRate = it->second;
	double valueNum;
	std::istringstream stream(value);
	if (!(stream >> valueNum))
	{
		std::cout << "bad input in value <" << line << ">" << std::endl;
		return;
	}

	std::cout << date << " => " << valueNum << " = " << valueNum * exchangeRate << std::endl;
}
