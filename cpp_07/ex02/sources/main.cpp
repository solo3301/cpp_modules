/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 10:12:23 by yadereve          #+#    #+#             */
/*   Updated: 2025/02/03 17:24:22 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Array.hpp"

#define MAX_VAL 750

int main(int, char**)
{
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	//SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}
	//Check the saved values
	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	std::cout << "\nLet's try to turn to the -2 index:\n";
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\nAn attempt to write to numbers[750] (outside MAX_VAL).\n";
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	delete [] mirror;
	return 0;
}

// int main()
// {
// 	try
// 	{
// 		Array<int> numbers(5);
// 		for (size_t i = 0; i < numbers.size(); i++)
// 			numbers[i] = i * 2;
// 		std::cout << "Array element: ";
// 		for (size_t i = 0; i < numbers.size(); i++)
// 			std::cout << numbers[i] << " ";
// 		std::cout << std::endl;

// 		std::cout << "Accesing out-of-bounds index: ";
// 		std::cout << numbers[10] << std::endl;
// 	}
// 	catch (const std::exception& e)
// 	{
// 		std::cerr << "Exception: " << e.what() << std::endl;
// 	}

// 	Array<std::string> strings(3);
// 	strings[0] = "hello";
// 	strings[1] = "42";
// 	strings[2] = "lisboa";

// 	Array<std::string> copy = strings;
// 	std::cout << "\nCopyed array: ";
// 	for (size_t i = 0; i < copy.size(); i++)
// 		std::cout << copy[i] << " ";
// 	std::cout << std::endl;
// 	return 0;
// }
