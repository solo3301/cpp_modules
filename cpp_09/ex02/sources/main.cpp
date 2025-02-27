/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:17:21 by yadereve          #+#    #+#             */
/*   Updated: 2025/02/27 16:13:23 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

int main(int ac, char* av[])
{
	if (ac < 2)
	{
		std::cerr << "Usage: " << av[0] << " <numbers>\n";
		return 1;
	}

	std::vector<int> vec;
	std::deque<int> deq;
	PmergeMe sort;
	try
	{
		for (int i = 1; i < ac; i++)
		{
			for (int j = 0; av[i][j]; j++)
			{
				if (!std::isdigit(av[i][j]))
					throw std::invalid_argument("Invalid input");
			}
			int num = std::atoi(av[i]);
			if (num < 0)
				throw std::invalid_argument("Invalid input men");
			sort.pushVector(vec, num);
			sort.pushDeque(deq, num);
		}
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl; 
		return 1;
	}
	std::cout << "Befor: ";
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << vec[i] << " ";
	std::cout << std::endl;
	sort.sortAndMeasure(vec);
	sort.sortAndMeasure(deq);
	std::cout << "After: ";
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << vec[i] << " ";
	std::cout << std::endl;
	sort.printDurations(vec, deq);

	return 0;
}
