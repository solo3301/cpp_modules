/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 10:53:55 by yadereve          #+#    #+#             */
/*   Updated: 2025/01/26 11:37:12 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/whatever.hpp"
#include <iostream>


int main()
{
	int a = 42, b = 53;
	std::string s1 = "apple", s2 = "banana";
	
	std::cout << "Befor swap:\n" << "a = " << a << ", b = " << b << std::endl;
	swap(a, b);
	std::cout << "After swap:\n" << "a = " << a << ", b = " << b << std::endl;
	std::cout << "max(a, b): " << ::max(a, b) << std::endl;
	std::cout << "min(a, b): " << ::min(a, b) << std::endl;

	std::cout << "\nBefor swap:\n" << "s1 = " << s1 << ", s2 = " << s2 << std::endl;
	swap(s1, s2);
	std::cout << "After swap:\n" << "s1 = " << s1 << ", s2 = " << s2 << std::endl;
	std::cout << "max(s1, s2): " << ::max(s1, s2) << std::endl;
	std::cout << "min(s1, s2): " << ::min(s1, s2) << std::endl;
	
	return 0;
}
