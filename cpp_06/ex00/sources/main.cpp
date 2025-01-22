/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:00:00 by yadereve          #+#    #+#             */
/*   Updated: 2025/01/22 18:40:15 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

int main(int ac, char** av)
{
	if (ac != 2)
	{
		std::cout << "Usage: " << av[0] << " lieral" << std::endl;
		return 1;
	}

	ScalarConverter::convert(av[1]);
	return 0;
}
