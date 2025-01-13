/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 12:15:22 by yadereve          #+#    #+#             */
/*   Updated: 2025/01/08 19:53:58 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat b1("Alice", 1);
		std::cout << b1 << std::endl;
		b1.incrementGrade(); // call exception
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat b2("Bob", 150);
		std::cout << b2 << std::endl;
		b2.decrementGrade(); // call exception
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat b3("Charlie", 200); // call exception
		std::cout << b3 << std::endl; // does not print b3 only exception
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std:: endl;
	}

	return 0;
}
