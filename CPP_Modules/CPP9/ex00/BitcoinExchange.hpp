#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <sstream>

class BitcoinExchange
{
private:
	std::map<std::string, double> rates;
	void processDataLine(const std::string &line);
	void processInputLine(const std::string &line);

public:
	// OCF
	BitcoinExchange();
	~BitcoinExchange();
	BitcoinExchange(BitcoinExchange const &o);
	BitcoinExchange &operator=(BitcoinExchange const &rhs);
	// member functions
	void exchange(std::string fileName);
	bool validDate(std::string);
	bool validValue(std::string valueStr);
};
std::string trim(const std::string &str);
#endif