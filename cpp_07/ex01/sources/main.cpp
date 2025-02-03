/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 18:52:20 by yadereve          #+#    #+#             */
/*   Updated: 2025/02/03 16:14:12 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/iter.hpp"

int main()
{
	int numbers[] = {1, 2, 3, 4, 5};
	size_t numLen = sizeof(numbers) / sizeof(numbers[0]);
	float floats[] = {.1, .2, .3, .4, .5};
	size_t floatLen = sizeof(numbers) / sizeof(numbers[0]);
	char chars[] = {'a', 'b', 'c'};
	size_t charLen = sizeof(chars) / sizeof(chars[0]);

	std::cout << "Origin numbers: " << std::endl;
	iter(numbers, numLen, print);
	std::cout << std::endl;
	iter(numbers, numLen, increment);
	std::cout << "Incremented numbers: " << std::endl;
	iter(numbers, numLen, print);
	std::cout << std::endl;

	std::cout << "\nOrigin floats: " << std::endl;
	iter(floats, floatLen, print);
	std::cout << std::endl;
	iter(floats, floatLen, increment);
	std::cout << "Incremented floats: " << std::endl;
	iter(floats, floatLen, print);
	std::cout << std::endl;

	std::cout << "\nOriginal chars: " << std::endl;
	iter(chars, charLen, print);
	std::cout << std::endl;
	iter(chars, charLen, makeUppercase);
	std::cout << "Uppercase chars: " << std::endl;
	iter(chars, charLen, print);
	std::cout << std::endl;

	return 0;
}
