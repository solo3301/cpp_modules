/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 19:45:35 by yadereve          #+#    #+#             */
/*   Updated: 2025/02/03 14:34:29 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{ }

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	(void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter()
{ }

static void printCharRepresentation(int value)
{
	if (value > 127 || value < -128)
		std::cout << "char: impossible\n";
	else if (!isprint(static_cast<char>(value)))
		std::cout << "char: Non displayable\n";
	else
		std::cout << "char: " << static_cast<char>(value) << std::endl;
}

static void printIntRepresentation(double value)
{
	if (isnan(value) || value < -2147483648.0 || value > 2147483648.0)
		std::cout << "int: impossible\n";
	else
		std::cout << "int: " << static_cast<int>(value) << std::endl;
}

static void printFloatRepresentation(float value)
{
	if (isnan(value))
		std::cout << "float: nanf\n";
	else if (isinf(value))
		std::cout << "float: " << (value > 0 ? "+inff" : "-inff") << std::endl;
	else
		std::cout << "float: " << std::fixed << std::setprecision(1) << value << "f\n";
}

static void printDoubleRepresentation(double value)
{
	if (isnan(value))
		std::cout << "double: nan\n";
	else if (isinf(value))
		std::cout << "double: " << (value > 0 ? "+inf" : "-inf") << std::endl;
	else
		std::cout << "double: " << value << std::endl;
}

static bool isNanOrInf(const std::string &literal)
{
	const char* specialLiterals[] = {"nan", "inf", "inff", "-inf", "+inf", "-inff", "+inff"};
	for (int i = 0; i < 7; ++i)
	{
		if (literal == specialLiterals[i])
			return true;
	}
	return false;
}

static bool hasDoubleSign(const std::string& literal)
{
	size_t plusCount = 0;
	size_t minusCount = 0;
	for (size_t i = 0; i < literal.length(); ++i)
	{
		if (literal[i] == '+')
			plusCount++;
		if (literal[i] == '-')
			minusCount++;
	}
	return (plusCount > 1 || minusCount > 1);
}

void ScalarConverter::convert(const std::string& literal)
{
	if (literal.empty())
	{
		std::cout << "Invalid literal: empty string\n";
		return;
	}

	if (isNanOrInf(literal))
	{
		double value = strtod(literal.c_str(), NULL);
		printCharRepresentation(static_cast<int>(value));
		printIntRepresentation(value);
		printFloatRepresentation(static_cast<float>(value));
		printDoubleRepresentation(value);
		return;
	}

	if (literal.length() == 1 && isprint(literal[0]) && !isdigit(literal[0]))
	{
		double value = static_cast<double>(literal[0]);
		printCharRepresentation(static_cast<int>(value));
		printIntRepresentation(value);
		printFloatRepresentation(static_cast<float>(value));
		printDoubleRepresentation(value);
		return;
	}

	if(literal.find_first_not_of("+-0123456789.f") != std::string::npos || hasDoubleSign(literal))
	{
		std::cerr << "Invalid literal\n";
		return;
	}

	char *endptr;
	double value = strtod(literal.c_str(), &endptr);

	if (*endptr != '\0' && *endptr != 'f')
	{
		std::cerr << "Invalid literal\n";
		return;
	}

	printCharRepresentation(static_cast<int>(value));
	printIntRepresentation(value);
	printFloatRepresentation(static_cast<float>(value));
	printDoubleRepresentation(value);
}
