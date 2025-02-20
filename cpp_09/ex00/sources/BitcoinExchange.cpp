/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 12:38:51 by yadereve          #+#    #+#             */
/*   Updated: 2025/02/20 18:10:56 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	if (!file.is_open())
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
		{
			size_t first = rateStr.find_first_not_of(" \t");
			size_t last = rateStr.find_last_not_of(" \t");
			if (first != std::string::npos && last != std::string::npos)
				rateStr = rateStr.substr(first, last - first + 1);
			double rate = std::atof(rateStr.c_str());
			if (rate != 0.0)
				_exchangeRates[date] = rate;
		}
		else
			std::cerr << "Error: Invalid data format in line: " << line << std::endl;
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

static bool isLeapYear(int year)
{
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

static bool isValidDate(const std::string& date)
{
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return false;
	int year = atoi(date.substr(0, 4).c_str());
	int month = atoi(date.substr(5, 2).c_str());
	int day = atoi(date.substr(8, 2).c_str());
	if (month < 1 || month > 12)
		return false;
	int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (month == 2 && isLeapYear(year))
		daysInMonth[1] = 29;
	return day >= 1 && day <= daysInMonth[month - 1];
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
		if (!isValidDate(date))
		{
			std::cerr << "Error: Invalid date -> " << date << std::endl;
			continue;
		}
		valueStr.erase(0, valueStr.find_first_not_of(" "));
		double value = std::atof(valueStr.c_str());
		if (value < 0)
		{
			std::cerr << "Error: not a positive number" << std::endl;
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
