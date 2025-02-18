#include "../includes/BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <string>

BitcoinExchange::BitcoinExchange()
{ }

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _exchangeRates(other._exchangeRates) 
{ }

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
		_exchangeRates = other._exchangeRates;
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{ }

void BitcoinExchange::loadExchangeRates(const std::string& fileName)
{
	std::ifstream file(fileName.c_str());
	if (file.is_open())
	{
		std::cerr << "Error: Cannot open exchange rate file" << std::endl;
		return;
	}
	
	std::string line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		std::istringstream ss(line);
		std::string date, rateStr;
		if (std::getline(ss, date, ',') && std::getline(ss, rateStr))
			_exchangeRates[date] = std::atof(rateStr.c_str());
	}
	file.close();
}

double BitcoinExchange::getRateForDate(const std::string& date) const
{
	std::map<std::string, double>::const_iterator it = _exchangeRates.lower_bound(date);
	if (it == _exchangeRates.end() || it->first != date)
	{
		if (it == _exchangeRates.begin())
			return -1;
		it--;
	}
	return it->second;
}

void BitcoinExchange::processFile(const std::string& fileName) const
{
	std::ifstream file(fileName.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: Cannot open input file" << std::endl;
		return;
	}

	std::string line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		std::istringstream ss(line);
		std::string date, valueStr;
		if (!(std::getline(ss, date, '|') && std::getline(ss, valueStr)))
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		date.erase(date.find_last_not_of(" ") + 1);
		valueStr.erase(0, valueStr.find_last_not_of(" "));
		double value = std::atof(valueStr.c_str());
		if (value < 0)
		{
			std::cerr << "Error: not a positiv number" << std::endl;
			continue;
		}
		if (value > 1000)
		{
			std::cerr << "Error: too large a number" << std::endl;
			continue;
		}
		double rate = getRateForDate(date);
		if (rate == -1)
		{
			std::cerr << "Error: no exchange rate available for " << date << std::endl;
			continue;
		}
		std::cout << date << " => " << value << " = " << (value * rate) << std::endl;
	}
	file.close();
}
