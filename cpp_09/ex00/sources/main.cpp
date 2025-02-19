/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 12:39:24 by yadereve          #+#    #+#             */
/*   Updated: 2025/02/19 12:39:24 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"

int main(int ac, char* av[])
{
	if (ac != 2)
	{
		std::cerr << "Usage: " << av[0] << " <input_file>" << std::endl;
		return 1;
	}
	BitcoinExchange btc;
	btc.loadExchangeRates("data.csv");
	btc.processFile(av[1]);
	return 0;
}
