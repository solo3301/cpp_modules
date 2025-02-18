#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <cstdlib>

class BitcoinExchange
{
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange& operator=(const BitcoinExchange& other);
	~BitcoinExchange();

	void loadExchangeRates(const std::string& fileName);
	void processFile(const std::string& fileName) const;
	double getRateForDate(const std::string& date) const;

private:
	std::map<std::string, double> _exchangeRates;
};

#endif
