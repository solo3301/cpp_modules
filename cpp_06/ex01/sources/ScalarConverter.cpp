/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 19:45:35 by yadereve          #+#    #+#             */
/*   Updated: 2025/01/22 20:02:07 by yadereve         ###   ########.fr       */
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

void ScalarConverter::convert(const std::string& literal)
{
	if (literal.length() == 1 && !std::isdigit(literal[0]))
	{
		char c = literal[0];
		std::cout << "char: " << c << std::endl;
		std::cout << "int: " << static_cast<int>(c) << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
		return;
	}
	try
	{
		char c = static_cast<char>(std::stoi(literal));
		if (std::isprint(c))
			std::cout << "char: '" << c << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	catch (...)
	{
		std::cout << "char: impossible" << std::endl;
	}

	try
	{
		int i = std::stoi(literal);
		std::cout << "int: " << i << std::endl;
	}
	catch (...)
	{
		std::cout << "int: impossible" << std::endl;
	}

	try
	{
		float f = std::stof(literal);
		std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	}
	catch (...)
	{
		std::cout << "float: impossible" << std::endl;
	}

	try
	{
		double d = std::stod(literal);
		std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
	}
	catch (...)
	{
		std::cout << "double impossible" <<std::endl;
	}
}
