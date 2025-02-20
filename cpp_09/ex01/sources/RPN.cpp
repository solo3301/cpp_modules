/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 08:07:07 by yadereve          #+#    #+#             */
/*   Updated: 2025/02/20 08:30:57 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"

RPN::RPN()
{ }

RPN::RPN(const RPN& other)
{
	(void)other;
}

RPN& RPN::operator=(const RPN& other)
{
	(void)other;
	return *this;
}

RPN::~RPN()
{ }

void RPN::evaluateExpression(const std::string& expression)
{
	std::stack<int> stack;
	std::istringstream iss(expression);
	std::string token;

	while (iss >> token)
	{
		if (token == "+" || token == "-" || token == "*" || token == "/")
		{
			if (stack.size() < 2)
			{
				std::cerr << "Error: Not enough operands for " << token << std::endl;
				return;
			}
			int b = stack.top();
			stack.pop();
			int a = stack.top();
			stack.pop();

			if (token == "+") 
				stack.push(a + b);
			else if (token == "-")
				stack.push(a - b);
			else if (token == "*")
				stack.push(a * b);
			else if (token == "/")
			{
				if (b == 0)
				{
					std::cerr << "Error: Division by zero" << std::endl;
					return;
				}
				stack.push(a / b);
			}
		}
		else
		{
			char* end;
			int num = std::strtol(token.c_str(), &end, 10);
			if (*end != '\0')
			{
				std::cerr << "Error: Invalid token '" << token << "'\n";
				return;
			}
			stack.push(num);
		}
	}
	if (stack.size() != 1)
	{
		std::cerr << "Error: Invalid RPN expession" << std::endl;
		return;
	}
	std::cout << stack.top() << std::endl;
}
