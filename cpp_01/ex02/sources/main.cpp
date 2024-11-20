/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 12:04:22 by yadereve          #+#    #+#             */
/*   Updated: 2024/11/20 12:28:29 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
	std::string brain = "HI THIS IS BRAIN";
	std::string* stringPTR = &brain;
	std::string& stringREF = brain;

	std::cout << "The memory address of the string variable\t" << &brain << std::endl
		<< "The memory address held by stringPTR\t\t" << stringPTR << std::endl
		<< "The memory address held by stringREF\t\t" << &stringREF << std::endl
		<< std::endl;

	std::cout << "The value of the string variable\t\t" << brain << std::endl
		<< "The value pointed to by stringPTR\t\t" << *stringPTR << std::endl
		<< "The value pointed to by stringREF\t\t" << stringREF << std::endl;
	return 0;
}
